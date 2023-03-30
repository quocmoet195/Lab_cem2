cmake_minimum_required(VERSION 3.11)

project(Class-v1 CXX)

set(CMAKE_CXX_STANDARD 23)

# Специфичные настройки для компилятора Visual Studio
if(MSVC)
    # Генерируем статическую заглушку для динамических библиотек
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS true)

    # Включаем высокий уровень предупреждений
    if(CMAKE_CXX_FLAGS MATCHES "/W[0-4]")
        string(REGEX REPLACE "/W[0-4]" "/W4" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
    else()
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
    endif()
endif()

# Подключаем googletest
include(FetchContent)
FetchContent_Declare(googletest URL https://github.com/google/googletest/archive/6b63c98ac43efc992122f1da12aaf0a0e0658206.zip)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Объявляем библиотеку . основня логика 
add_library(Class-v1 SHARED
    "include/Class/Class.h"
    "src/Class.cpp"
    "src/Class_list.cpp")
target_include_directories(Class-v1 PUBLIC "include")

# Объявляем тесты
add_executable(Class-v1-tests
    "test/Class_list_tests.cpp"
    "test/Class_tests.cpp")
target_link_libraries(Class-v1-tests Class-v1 GTest::gtest_main)

# Объявляем 
add_executable(Class-v1-console
 "console/console_app.cpp")
target_link_libraries(Class-v1-console Class-v1)