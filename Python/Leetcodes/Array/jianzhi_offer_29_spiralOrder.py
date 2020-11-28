#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
@Time    : 2020/11/28 12:00 上午
@Author  : luocai
@file    : jianzhi_offer_29_spiralOrder.py
@concat  : 429546420@qq.com
@site    : 
@software: PyCharm Community Edition 
@desc    :

https://leetcode-cn.com/problems/shun-shi-zhen-da-yin-ju-zhen-lcof/
剑指 offer29：顺时针打印矩阵
"""
from typing import List


class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        res = []
        while matrix:
            res += matrix.pop(0)
            # 转置+倒序实现
            matrix = list(zip(*matrix))[::-1]

        return res

    def spiralOrder2(self, matrix: List[List[int]]) -> List[int]:
        # 按层打印
        if not matrix or not matrix[0]:
            return []

        res = []
        left, right, top, bottom = 0, len(matrix[0]) - 1, 0, len(matrix) - 1
        while left <= right and top <= bottom:
            # 从左到右
            for col in range(left, right + 1, 1):
                res.append(matrix[top][col])
            # 从上到下
            for row in range(top + 1, bottom + 1, 1):
                res.append(matrix[row][right])
            if left < right and top < bottom:
                # 下方的从右到左和从下到上
                for col in range(right - 1, left, -1):
                    res.append(matrix[bottom][col])
                for row in range(bottom, top, -1):
                    res.append(matrix[row][left])
            left, right, top, bottom = left + 1, right - 1, top + 1, bottom - 1

        return res


if __name__ == '__main__':
    array = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
    print("origin array: ", array)
    solution = Solution()
    print("顺时针打印矩阵: ", solution.spiralOrder2(array))
