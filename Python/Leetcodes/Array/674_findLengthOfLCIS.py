#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
@Time    : 2021/3/6 9:39 上午
@Author  : luocai
@file    : 674_findLengthOfLCIS.py
@concat  : 429546420@qq.com
@site    : 
@software: PyCharm Community Edition 
@desc    :

674. 最长连续递增序列
https://leetcode-cn.com/problems/longest-continuous-increasing-subsequence/
"""
from typing import List


class Solution:
    def findLengthOfLCIS(self, nums: List[int]) -> int:
        if not nums:
            return 0
        n = len(nums)
        max_length = 1
        for i in range(n):
            j = i + 1
            while j < n and nums[j - 1] < nums[j]:
                j += 1
            max_length = max(max_length, j-i)
            if j < n:
                i = j

        return max_length
