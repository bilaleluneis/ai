cmake_minimum_required(VERSION 3.13)
project(ai)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic -Werror")
set(CMAKE_CXX_CLANG_TIDY clang-tidy-9)
set(SOURCES src/problem.cpp)
set(INCLUDES include/problem.h include/state.h include/types/grid.h)
set(TESTS test/problemTests.cpp test/stateTests.cpp test/types/grid_tests.cpp test/test_runner.cpp)

find_package(Boost 1.67 REQUIRED COMPONENTS unit_test_framework)

add_library(ai SHARED ${SOURCES} ${INCLUDES})

target_include_directories(ai PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(ai PUBLIC Boost::boost)

enable_testing()

add_executable(aiTests ${TESTS})

target_link_libraries(aiTests ai Boost::unit_test_framework)

target_compile_definitions(aiTests PRIVATE BOOST_TEST_DYN_LINK)

add_test(test_all aiTests)