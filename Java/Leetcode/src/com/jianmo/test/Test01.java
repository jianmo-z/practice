package com.jianmo.test;

/* *** 代码是写给人看，顺带让机器执行 ***
 * ***  永远不要相信任何传进来的参数 ***
 *
 * 文件: Test01
 * 时间: 2020/12/28-23:38
 * 作者: Pip
 */

import java.util.HashMap;

/**
 * @author Pip
 */
public class Test01 {
    static class Student {
        String name;

        @Override
        public String toString() {
            return "Student{" +
                    "name='" + name + '\'' +
                    '}';
        }
    }

    public static void main(String[] args) {
        HashMap<Student, Integer> map = new HashMap<>();

        Student s = new Student();
        s.name = "张三";
        map.put(s, 10);
        s.name = "李四";
        System.out.println(map.get(s));
    }
}
