#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
@Time    : 2021/1/29 7:42 上午
@Author  : luocai
@file    : jianzhi_offer_4_findNumberIn2DArray.py
@concat  : 429546420@qq.com
@site    : 
@software: PyCharm Community Edition 
@desc    :

https://leetcode-cn.com/problems/er-wei-shu-zu-zhong-de-cha-zhao-lcof/
剑指 offer04 题 二维数组的查找
"""
from typing import List


class Solution:
    def findNumberIn2DArray(self, matrix: List[List[int]], target: int) -> bool:
        # 左下角开始查找
        i, j = len(matrix)-1, 0
        while i >= 0 and j < len(matrix[0]):
            if matrix[i][j] > target:
                # 消除当前行
                i -= 1
            elif matrix[i][j] < target:
                # 消除当前列
                j +=1
            else:
                return True
        return False