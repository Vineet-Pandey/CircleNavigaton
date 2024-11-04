cmake_minimum_required(VERSION 3.16)
project(CircleNavigation)
set(CMAKE_CXX_STANDARD 17)

# Set the source file for the main executable
set(SOURCE_FILE src/main.cpp)

add_executable(CircleNavigation ${SOURCE_FILE})

target_include_directories(CircleNavigation PRIVATE ${CMAKE_SOURCE_DIR}/include)


set_target_properties(CircleNavigation PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_library(CircleNavigationLib STATIC ${SOURCE_FILE})
target_include_directories(CircleNavigationLib PUBLIC ${CMAKE_SOURCE_DIR}/include)


find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})


add_executable(UnitTests src/unit_test.cpp)
set_target_properties(UnitTests PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
target_link_libraries(UnitTests PRIVATE CircleNavigationLib GTest::GTest GTest::Main pthread)

# Enable testing
enable_testing()
add_test(NAME CircleNavigationTests COMMAND UnitTests)
# Set Clang Tidy options
set(CMAKE_CXX_CLANG_TIDY "clang-tidy;-checks=*")

# Enable Clang Format
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
function(format_code)
    find_program(CLANG_FORMAT "clang-format")
    if(CLANG_FORMAT)
        add_custom_target(format ALL
                COMMAND ${CLANG_FORMAT} -i ${SOURCES}
                COMMENT "Formatting source files"
        )
    else()
        message(WARNING "clang-format not found! Please install it to use the formatting target.")
    endif()
endfunction()

# Call the format_code function to create the format target
format_code()
