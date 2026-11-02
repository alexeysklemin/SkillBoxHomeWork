# =============================================================================
# Минимальная версия CMake
# Указываем, что проект требует CMake не ниже 3.5
# =============================================================================
cmake_minimum_required(VERSION 3.5)

# =============================================================================
# Название проекта и языки
# Создаем проект module_4_7, используем только C++
# =============================================================================
project(module_4_7 LANGUAGES CXX C)

# =============================================================================
# Стандарт C++
# Устанавливаем стандарт C++17 и требуем его поддержки от компилятора
# =============================================================================
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# =============================================================================
# Настройки автоматизации Qt
# Эти три строки КРИТИЧНЫ для работы Qt с CMake:
# AUTOMOC - автоматически обрабатывает макрос Q_OBJECT (сигналы/слоты)
# AUTOUIC - автоматически компилирует .ui файлы от Qt Designer в C++ код
# AUTORCC - автоматически обрабатывает .qrc файлы ресурсов (картинки, иконки)
# Ставим ДО find_package и add_executable
# =============================================================================
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# =============================================================================
# Поиск библиотек Qt
# Сначала пробуем найти Qt6. Если не удалось (QUIET - без ошибок), ищем Qt5
# Это делает CMake универсальным для разных версий Qt
# =============================================================================
find_package(Qt6 COMPONENTS Widgets QUIET)
if(NOT Qt6_FOUND)
    find_package(Qt5 REQUIRED COMPONENTS Widgets)
    set(QT_VERSION_MAJOR 5)
else()
    set(QT_VERSION_MAJOR 6)
endif()

# =============================================================================
# Настройка путей к исходным файлам
# PRJ_HDR_DIR - папка для заголовочных файлов (.h, .hpp)
# PRJ_SRC_DIR - папка для исходных файлов (.cpp)
# =============================================================================
set(PRJ_HDR_DIR "inc")
set(PRJ_SRC_DIR "src")

# =============================================================================
# Поиск файлов (GLOB)
# Рекурсивно ищем все .h/.hpp в папке inc и все .cpp в папке src
# GLOB_RECURSE означает поиск включая подпапки
# =============================================================================
file(GLOB_RECURSE HEADERS "${CMAKE_SOURCE_DIR}/${PRJ_HDR_DIR}/*.h" "${CMAKE_SOURCE_DIR}/${PRJ_HDR_DIR}/*.hpp")
file(GLOB_RECURSE SOURCES "${CMAKE_SOURCE_DIR}/${PRJ_SRC_DIR}/*.cpp")
file(GLOB_RECURSE SOURCES_C "${CMAKE_SOURCE_DIR}/${PRJ_SRC_DIR}/*.c")

# ← ДОБАВЬ ЭТИ СТРОКИ ДЛЯ ОТЛАДКИ:
message(STATUS "=== ОТЛАДКА C ФАЙЛОВ ===")
message(STATUS "SOURCES_C: ${SOURCES_C}")
message(STATUS "Search path: ${CMAKE_SOURCE_DIR}/${PRJ_SRC_DIR}/*.c")

message(STATUS "CMAKE_SOURCE_DIR: ${CMAKE_SOURCE_DIR}")
message(STATUS "PRJ_HDR_DIR: ${PRJ_HDR_DIR}")
message(STATUS "ПComplite path к inc: ${CMAKE_SOURCE_DIR}/${PRJ_HDR_DIR}")
message(STATUS "Found HEADERS: ${HEADERS}")

# =============================================================================
# Создание исполняемого файла
# Добавляем в сборку:
# - Все .cpp из папки src (переменная SOURCES)
# - Все заголовки (переменная HEADERS) - для отображения в IDE
# - main.cpp из корня проекта (явно, т.к. его нет в SOURCES)
# =============================================================================
add_executable(${PROJECT_NAME}
    ${SOURCES}
    ${SOURCES_C} #Это не папка Это переменная!
    ${HEADERS}
    main.cpp
)

# Для автоматического подключение библиотек
if(MINGW)
    target_link_options(module_4_7 PRIVATE 
        -static -static-libgcc -static-libstdc++
    )
endif()

# =============================================================================
# Пути к заголовочным файлам (Include Directories)
# Говорим компилятору, где искать файлы при #include "MenuLogic.h"
# PRIVATE означает, что эти пути нужны только для сборки этой цели
# =============================================================================
target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_SOURCE_DIR}/${PRJ_HDR_DIR}
    ${CMAKE_SOURCE_DIR}/${PRJ_SRC_DIR}
)

# =============================================================================
# Линковка библиотек
# Привязываем к проекту библиотеки Qt Widgets нужной версии (5 или 6)
# Без этой строки будут ошибки "unresolved external symbol" при сборке
# =============================================================================
target_link_libraries(${PROJECT_NAME} PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# =============================================================================
# Настройка установки (Install)
# Подключаем стандартные пути GNU (bin, lib и т.д.)
# Настраиваем команду 'cmake --install', чтобы скопировать готовый exe
# в нужную директорию при установке
# =============================================================================
include(GNUInstallDirs)
install(TARGETS ${PROJECT_NAME}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}  # .exe файлы идут в bin
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}  # .dll/.so файлы идут в lib
)
