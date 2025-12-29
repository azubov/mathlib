# Mathlib

Mathlib — это небольшая C++ библиотека для базовых математических операций с целыми числами (`std::int64_t`).  
Она предоставляет функции сложения, вычитания, умножения, деления, возведения в степень и вычисления факториала с проверкой переполнений и ошибок.

## 📂 Структура проекта

```
mathlib/
├── include/
│   └── mathlib/
│       └── math_operations.h
├── src/
│   └── math_operations.cpp
├── tests/
│   └── CMakeLists.txt
│   └── test_math.cpp
├── CMakeLists.txt
└── README.md
```

## 🚀 Возможности

- `add(lhs, rhs)` — сложение с проверкой переполнения
- `subtract(lhs, rhs)` — вычитание
- `multiply(lhs, rhs)` — умножение с проверкой переполнения
- `divide(lhs, rhs)` — деление с проверкой деления на ноль и переполнения
- `power(base, exponent)` — возведение в степень (только для неотрицательных показателей)
- `factorial(n)` — факториал (только для неотрицательных чисел)

## 📦 Доставка артефактов

Библиотека собирается в двух вариантах:

- **release-static** — статическая библиотека (`libmathlib.a`)
- **release-shared** — динамическая библиотека (`libmathlib.so`)

Оба варианта публикуются в [GitHub Releases](https://github.com/azubov/mathlib/releases).

---

## 🔗 Подключение в другом проекте

### CPM.cmake (рекомендуемый способ)

В `CMakeLists.txt` вашего проекта:

```cmake
if(NOT EXISTS "${CMAKE_BINARY_DIR}/cmake/cpm.cmake")
    message(STATUS "Downloading CPM.cmake...")
    file(MAKE_DIRECTORY "${CMAKE_BINARY_DIR}/cmake")
    file(DOWNLOAD
            https://github.com/cpm-cmake/CPM.cmake/releases/latest/download/cpm.cmake
            "${CMAKE_BINARY_DIR}/cmake/cpm.cmake"
    )
endif()
include(${CMAKE_BINARY_DIR}/cmake/cpm.cmake)

CPMAddPackage(
        NAME mathlib
        VERSION 1.0.0
        URL https://github.com/azubov/mathlib/releases/download/v1.0.0/mathlib-release-static-v1.0.0.tar.gz
)

add_executable(simple_calculator src/main.cpp)
target_link_libraries(simple_calculator PRIVATE mathlib::mathlib)
```

### FetchContent (альтернативный способ)

В `CMakeLists.txt` вашего проекта:

```cmake
include(FetchContent)

FetchContent_Declare(
        mathlib
        GIT_REPOSITORY https://github.com/azubov/mathlib.git
        GIT_TAG v1.0.0
)

FetchContent_MakeAvailable(mathlib)

add_executable(simple_calculator src/main.cpp)
target_link_libraries(simple_calculator PRIVATE mathlib::mathlib)
```

## 🧩 Пример использования

```c++
#include "mathlib/math_operations.h"
#include <iostream>

int main() {
    std::cout << "2 + 3 = " << mathlib::add(2, 3) << "\n";
    std::cout << "5! = " << mathlib::factorial(5) << "\n";
}
```

## 🛠️ Сборка через CMakePresets

В проекте используется файл `CMakePresets.json`, который описывает готовые профили сборки.

### Доступные пресеты

| Пресет          | Тип библиотеки | Режим   | Тесты | Clang‑tidy `--warnings-as-errors=*` |
|-----------------|----------------|---------|-------|-------------|
| `release-shared`  | `Shared (.so/.dll)` | `Release` | ❌    | ❌           |
| `release-static`  | `Static (.a/.lib)`  | `Release` | ❌    | ❌           |
| `debug-with-tests` | `Static`           | `Debug`   | ✅    | ❌           |
| `debug-tidy`      | `Static`           | `Debug`   | ❌    | ✅           |

### Использование

Сборка shared‑версии:

```bash
cmake --preset release-shared
cmake --build --preset release-shared
```

Сборка static‑версии:

```bash
cmake --preset release-static
cmake --build --preset release-static
```

Сборка с тестами:

```bash
cmake --preset debug-with-tests
cmake --build --preset debug-with-tests
ctest --preset debug-with-tests --output-on-failure
```

Сборка с clang‑tidy:

```bash
cmake --preset debug-tidy
cmake --build --preset debug-tidy
```