#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
@Time    : 2020/12/26 2:32 下午
@Author  : luocai
@file    : jianzhi_offer_56_II_singleNumber.py
@concat  : 429546420@qq.com
@site    : 
@software: PyCharm Community Edition 
@desc    :

https://leetcode-cn.com/problems/shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-ii-lcof/
剑指 offer56 题II--数组中出现的次数
"""
from typing import List


class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        nums.sort()
        n = len(nums)
        i = 0
        while i < n:
            if (i == 0 and nums[i] != nums[i + 1]) or (i == n - 1 and nums[i] != nums[i - 1]):
                return nums[i]
            if nums[i] != nums[i + 1]:
                return nums[i]
            else:
                i += 3


if __name__ == '__main__':
    nums = [3, 4, 3, 3]
    solution = Solution()
    print("result: ", solution.singleNumber(nums))
