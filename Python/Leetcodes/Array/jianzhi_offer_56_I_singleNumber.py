#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
@Time    : 2021/1/2 4:59 下午
@Author  : luocai
@file    : jianzhi_offer_56_I_singleNumber.py
@concat  : 429546420@qq.com
@site    : 
@software: PyCharm Community Edition 
@desc    :

https://leetcode-cn.com/problems/shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-lcof/
剑指 offer56 题 I--数组中数字出现的次数
"""
from typing import List


class Solution:
    def singleNumbers(self, nums: List[int]) -> List[int]:
        res = nums[0]
        for i in range(1, len(nums)):
            res ^= nums[i]
        div = 1
        # 找到为 1 的任意一位
        while (div & res) == 0:
            div <<= 1
        # 分组异或
        a, b = 0, 0
        for n in nums:
            if n & div:
                a ^= n
            else:
                b ^= n
        return [a, b]


if __name__ == '__main__':
    nums = [1, 2, 10, 4, 1, 4, 3, 3]
    solution = Solution()
    print("result:", solution.singleNumbers(nums))
