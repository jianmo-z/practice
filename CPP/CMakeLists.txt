cmake_minimum_required(VERSION 3.5.1)
project(practice)

set(CMAKE_CXX_STANDARD 11)
set(GOOGLETEST_VERSION 1.9.0)

set(LIBRARIES gtest gtest_main pthread)
set(SOURCE_FILES
        main.cpp
        nowcode/SortSingleLinkList.cpp
        comm/ListNode.cpp
        leetcodeEditor/leetcode/editor/cn/49_GroupAnagrams.cpp
        leetcodeEditor/leetcode/editor/cn/738_MonotoneIncreasingDigits.cpp
        leetcodeEditor/leetcode/editor/cn/42_TrappingRainWater.cpp
        leetcodeEditor/leetcode/editor/cn/146_LruCache.cpp
        leetcodeEditor/leetcode/editor/cn/402_RemoveKDigits.cpp
        leetcodeEditor/leetcode/editor/cn/316_RemoveDuplicateLetters.cpp
        leetcodeEditor/leetcode/editor/cn/239_SlidingWindowMaximum.cpp
        leetcodeEditor/leetcode/editor/cn/15_ThreeSum.cpp
        leetcodeEditor/leetcode/editor/cn/205_IsomorphicStrings.cpp
        practice/02test.cpp
        )

# 编译google practice
add_subdirectory(./googletest)
# 把google test的头文件添加到include路径中
include_directories(./googletest/include)
# 将libtest.a添加到连接路径中
link_directories(./googletest)


add_executable(practice ${SOURCE_FILES})
target_link_libraries(practice  ${LIBRARIES})