cmake_minimum_required(VERSION 3.5.1)
project(practice)

set(CMAKE_CXX_STANDARD 11)
set(GOOGLETEST_VERSION 1.9.0)

set(LIBRARIES gtest gtest_main)
set(SOURCE_FILES
        main.cpp
        nowcode/SortSingleLinkList.cpp
        comm/ListNode.cpp
        leetcodeEditor/leetcode/editor/cn/179_LargestNumber.cpp
        practice/07test.cpp
        )

# 编译google practice
add_subdirectory(./googletest)
# 把google test的头文件添加到include路径中
include_directories(./googletest/include)
# 将libtest.a添加到连接路径中
link_directories(./googletest)


add_executable(practice ${SOURCE_FILES})
target_link_libraries(practice  ${LIBRARIES})