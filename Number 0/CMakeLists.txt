cmake_minimum_required(VERSION 3.10)
project(untitled1)

set(CMAKE_CXX_STANDARD 14)

# Сборка статической библиотеки
add_library(matrix STATIC matrix.cpp)

# Основной исполняемый файл
add_executable(main main.cpp)
target_link_libraries(main matrix)

# Тесты
add_executable(test1 test1.cpp)
target_link_libraries(test1 matrix)

add_executable(test2 test2.cpp)
target_link_libraries(test2 matrix)

add_executable(test3 test3.cpp)
target_link_libraries(test3 matrix)
