cmake_minimum_required(VERSION 3.12)
project(runTests)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

FetchContent_MakeAvailable(googletest)


include(FetchContent)
set(BUILD_MinimalCppSocket_SAMPLES OFF CACHE BOOL "" FORCE) # you don't want the samples in this case
FetchContent_Declare(
min_sock
GIT_REPOSITORY https://github.com/andreacasalino/Minimal-Socket
GIT_TAG        master
)
FetchContent_MakeAvailable(min_sock)


# include _deps directory for gtest
include_directories(_deps/googletest-src/googletest/include)
include_directories(../)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/_deps/min_sock-src/src/header)
# ADD PATH FOR FINDING LIBRARIES
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/_deps/min_sock-src/build)

enable_testing()

# el main, el test, el archivo que quiero probar
add_executable(
  runTests
  test_main.cpp
  Test_funciones_cpp.cpp
  Test_Poscion_test.cpp
  Test_area.cpp
  ../Posicion_abs.cpp
  ../Funciones.cpp
  ../area.cpp
  ../utils.cpp
)
target_link_libraries(
  runTests
  GTest::gtest_main
  MinimalSocket
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

include(GoogleTest)
gtest_discover_tests(runTests 
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)