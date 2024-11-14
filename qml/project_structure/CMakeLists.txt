cmake_minimum_required(VERSION 3.16)
cmake_policy(SET CMP0099 NEW)

set(EXECUTABLE_NAME "ProjectName")

project(${EXECUTABLE_NAME} VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 20)

find_package(Qt6 6.2 COMPONENTS Quick QuickControls2 LinguistTools REQUIRED)
qt_policy(SET QTP0001 NEW)

set(PROJECT_TESTS TRUE)
include(config.cmake)

add_subdirectory(modules/doctor_console)
add_subdirectory(modules/settings)
add_subdirectory(modules/style)

if(${PROJECT_TESTS})
    add_subdirectory(tests/unit_test_cpp)
    add_subdirectory(tests/unit_test_qml)
endif()

file(GLOB_RECURSE PROJECT_SOURCES "src/*.cpp")
file(GLOB_RECURSE PROJECT_HEADERS "include/*.hpp" "include/*.h")
file(GLOB_RECURSE RESOURCES "resources/*.qrc")

qt_add_resources(PROJECT_RESOURCES ${RESOURCES})

qt_add_executable(${EXECUTABLE_NAME}
    ${PROJECT_SOURCES} ${PROJECT_HEADERS}
    ${PROJECT_RESOURCES}
)

# Subfolders must be grouped seperately
file(GLOB PROJECT_QMLS RELATIVE ${CMAKE_SOURCE_DIR} qml/*.qml)
source_group("Qml Files" FILES ${PROJECT_QMLS})

qt_add_qml_module(${EXECUTABLE_NAME}
    URI ${EXECUTABLE_NAME}
    VERSION 1.0
    QML_FILES ${PROJECT_QMLS}
)

set_target_properties(${EXECUTABLE_NAME} PROPERTIES
    MACOSX_BUNDLE FALSE
    WIN32_EXECUTABLE TRUE
)

target_include_directories(${EXECUTABLE_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(${EXECUTABLE_NAME} PRIVATE
    Qt6::Quick
    Qt6::QuickControls2
    # add modules here append "plugin" to the name
)

file(GLOB_RECURSE ALL_QMLS RELATIVE ${CMAKE_SOURCE_DIR} *.qml)

qt_add_translations(${EXECUTABLE_NAME} TS_FILES
    translations/English.ts
    translations/Chinese.ts
    SOURCES ${ALL_QMLS} ${PROJECT_SOURCES} ${PROJECT_HEADERS}
    RESOURCE_PREFIX "/translations"
)

install(TARGETS ${EXECUTABLE_NAME}
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)
