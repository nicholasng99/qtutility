cmake_minimum_required(VERSION 3.5)

cmake_policy(SET CMP0099 NEW)

project(TestCpp1 LANGUAGES CXX)

enable_testing()

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Test)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Test)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(TestCpp1 tst_testcpp1.cpp)
add_test(NAME TestCpp1 COMMAND TestCpp1)

target_link_libraries(TestCpp1
    PRIVATE Qt${QT_VERSION_MAJOR}::Test
    PRIVATE FirstPlugin)

