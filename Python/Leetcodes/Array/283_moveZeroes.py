#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
@Time    : 2021/2/27 3:04 下午
@Author  : luocai
@file    : 283_moveZeroes.py
@concat  : 429546420@qq.com
@site    : 
@software: PyCharm Community Edition 
@desc    :

283. 移动零
https://leetcode-cn.com/problems/move-zeroes/
"""
from typing import List


class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        l, r = 0, 0
        n = len(nums)
        while r < n:
            if nums[r] != 0:
                nums[l], nums[r] = nums[r], nums[l]
                l += 1
            r += 1
