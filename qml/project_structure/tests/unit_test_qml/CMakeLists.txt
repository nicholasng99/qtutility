cmake_minimum_required(VERSION 3.5)

cmake_policy(SET CMP0099 NEW)

project(TestQML LANGUAGES CXX)

enable_testing()

#set(APP_QML_MODULES_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../../modules")
#list(APPEND QML_DIRS ${APP_QML_MODULES_PATH})
#set(QML_IMPORT_PATH ${QML_DIRS} CACHE STRING "add qml import path")

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS QuickTest Qml)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS QuickTest Qml)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# no need to copy around qml test files for shadow builds - just set the respective define
add_definitions(-DQUICK_TEST_SOURCE_DIR="${CMAKE_CURRENT_SOURCE_DIR}")

add_executable(TestQML main.cpp
               setup.cpp setup.h)
add_test(NAME TestQML COMMAND TestQML)

target_link_libraries(TestQML
                      PRIVATE Qt${QT_VERSION_MAJOR}::QuickTest
                      PRIVATE Qt${QT_VERSION_MAJOR}::Qml
                      PRIVATE FirstPlugin                      
                      PRIVATE FirstPluginplugin
                      PRIVATE Style
                      PRIVATE Styleplugin
                  )

