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
├── CMakePresets.json
└── README.md
```

## 🚀 Возможности

- `add(lhs, rhs)` — сложение с проверкой переполнения
- `subtract(lhs, rhs)` — вычитание
- `multiply(lhs, rhs)` — умножение с проверкой переполнения
- `divide(lhs, rhs)` — деление с проверкой деления на ноль и переполнения
- `power(base, exponent)` — возведение в степень (только для неотрицательных показателей)
- `factorial(n)` — факториал (только для неотрицательных чисел)

## 🔗 Подключение в другом проекте

### FetchContent

В `CMakeLists.txt` вашего проекта:

```cmake
include(FetchContent)
FetchContent_Declare(
        mathlib
        GIT_REPOSITORY https://github.com/azubov/mathlib.git
        GIT_TAG master
)
FetchContent_MakeAvailable(mathlib)
```

 Сборка `static` в `CMakeLists.txt`:
```cmake
set(BUILD_SHARED_LIBS OFF CACHE BOOL "Build static libraries" FORCE)
```

Сборка `shared` в `CMakeLists.txt`:
```cmake
set(BUILD_SHARED_LIBS ON CACHE BOOL "Build shared libraries" FORCE)
```

Линковка в `CMakeLists.txt`:
```cmake
target_link_libraries(my_app PRIVATE mathlib)
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

- **debug** — сборка в режиме Debug, включает тесты и clang-tidy. 
- **release** — оптимизированная сборка в режиме Release, без тестов. 
- **shared** — сборка Release с динамической библиотекой, без тестов.
- **static** — сборка Release со статической библиотекой, без тестов.

### Использование

Сборка debug-версии с тестами и clang-tidy:

```bash
cmake --preset debug
cmake --build --preset debug
ctest --preset debug --output-on-failure
```

Сборка release‑версии (по умолчанию статическая):

```bash
cmake --preset release 
cmake --build --preset release
```

Сборка shared‑версии:

```bash
cmake --preset shared
cmake --build --preset shared
```

Сборка static‑версии:

```bash
cmake --preset static
cmake --build --preset static
```
