cmake_minimum_required(VERSION 3.29)
project(untitled)

# Устанавливаем стандарт C++
set(CMAKE_CXX_STANDARD 17)

# Добавляем исходные файлы
set(SOURCES
        src/ASCIIPicture.cpp
        src/Cloud.cpp
        src/Cow.cpp
        src/Field.cpp
        src/main.cpp
        src/Parser.cpp
)

# Добавляем заголовочные файлы
set(HEADERS
        src/ASCIIPicture.hpp
        src/Cloud.hpp
        src/Cow.hpp
        src/Field.hpp
        src/Parser.hpp
)

# Создаем исполняемый файл
add_executable(ASCIIArt ${SOURCES} ${HEADERS})

# Указываем, где искать заголовочные файлы
target_include_directories(ASCIIArt PRIVATE src)

# Копируем папки cows и clouds в директорию сборки
file(COPY cows clouds DESTINATION ${CMAKE_BINARY_DIR})
