#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
@Time    : 2020/12/21 7:49 上午
@Author  : luocai
@file    : jianzhi_offer_11_minArray.py
@concat  : 429546420@qq.com
@site    : 
@software: PyCharm Community Edition 
@desc    :

https://leetcode-cn.com/problems/xuan-zhuan-shu-zu-de-zui-xiao-shu-zi-lcof/
剑指 offer11 题--旋转数组的最小数字
"""
from typing import List


class Solution:
    def minArray(self, numbers: List[int]) -> int:
        # 二分查找
        low, high = 0, len(numbers) - 1
        while low < high:
            pivot = low + (high - low) // 2
            if numbers[pivot] < numbers[high]:
                high = pivot
            elif numbers[pivot] > numbers[high]:
                low = pivot + 1
            else:
                high -= 1
        return numbers[low]
