cmake_minimum_required(VERSION 3.5.1)
project(practice)

set(CMAKE_CXX_STANDARD 11)
set(GOOGLETEST_VERSION 1.9.0)

set(LIBRARIES gtest gtest_main pthread)
set(SOURCE_FILES main.cpp fff.cpp df.h sd.h ff.h)

# 编译google test
add_subdirectory(./googletest)
# 把google test的头文件添加到include路径中
include_directories(./googletest/include)
# 将libtest.a添加到连接路径中
link_directories(./googletest)


add_executable(practice ${SOURCE_FILES})
target_link_libraries(practice  ${LIBRARIES})