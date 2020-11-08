package com.jianmo;

/* *** 代码是写给人看，顺带让机器执行 ***
 * ***  永远不要相信任何传进来的参数 ***
 *
 * 文件: L136SingleNumber
 * 时间: 2020/11/8-22:32
 * 作者: Pip
 */

import org.junit.Assert;
import org.junit.Test;

/**
 * @author Pip
 */
public class L136SingleNumber {
    @Test
    public void test01() {
        Assert.assertEquals(singleNumber(new int[] {2,2,1}), 1);
    }
    public int singleNumber(int[] nums) {
        int ret = 0;
        for (int i : nums) {
            ret ^= i;
        }
        return ret;
    }
}
