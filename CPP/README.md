# practice简介

> 该仓库主要是用来平时刷题和笔试时候记录自己写的代码，方便以后可能会看一看，生命不息，学习不止。编程应当是爱好。

## Leetcode-Editor模板

* 标题

  ```json
  $!{question.frontendQuestionId}_$!velocityTool.camelCaseName(${question.titleSlug})
  ```

* 内容

  ```
  \#include <bits/stdc++.h>
  \#include "../googletest/include/gtest/gtest.h"
  
  ${question.content}
  
  namespace WordLadder {
      using namespace std;    
      
  ${question.code}
      
      TEST(WordLadder, test01) {
          Solution s;
      }
  }
  ```

  
