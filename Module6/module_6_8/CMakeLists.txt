#CMakeLists.txt
cmake_minimum_required(VERSION 3.23)

project(module_6_8 VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(PROJ_PATH "${CMAKE_CURRENT_SOURCE_DIR}")

# Ищем Qt с компонентами Widgets и Test
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Test)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Test)

# Указываем где искать заголовки
include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/engine
    ${CMAKE_CURRENT_SOURCE_DIR}/dataLayer
    ${CMAKE_CURRENT_SOURCE_DIR}/UI
    ${CMAKE_CURRENT_SOURCE_DIR}/tests
)

# ===== АВТОМАТИЧЕСКИЙ ПОИСК ФАЙЛОВ =====
file(GLOB_RECURSE ALL_HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/*.h")
file(GLOB_RECURSE ALL_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

# Исключаем тесты из основного приложения
list(FILTER ALL_HEADERS EXCLUDE REGEX ".*/tests/.*")
list(FILTER ALL_SOURCES EXCLUDE REGEX ".*/tests/.*")

# Используем ТОЛЬКО найденные файлы
set(PROJECT_SOURCES ${ALL_HEADERS} ${ALL_SOURCES})

# ===== ОСНОВНОЕ ПРИЛОЖЕНИЕ =====
if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(module_6_8
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET module_6_8 APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(module_6_8 SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(module_6_8
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(module_6_8 PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# ===== ТЕСТЫ =====
enable_testing()

# Автоматический поиск всех тестов
file(GLOB TEST_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/tests/*.cpp")
foreach(test_source ${TEST_SOURCES})
    get_filename_component(test_name ${test_source} NAME_WE)
    add_executable(${test_name} ${test_source})
    target_link_libraries(${test_name} PRIVATE Qt${QT_VERSION_MAJOR}::Test)
    target_include_directories(${test_name} PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/engine
        ${CMAKE_CURRENT_SOURCE_DIR}/UI
    )
    add_test(NAME ${test_name} COMMAND ${test_name})
endforeach()

# ===== СВОЙСТВА под MACOS =====
set_target_properties(module_6_8 PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(module_6_8)
endif()
