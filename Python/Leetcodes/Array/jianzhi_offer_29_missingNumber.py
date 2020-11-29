#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
@Time    : 2020/11/29 8:20 下午
@Author  : luocai
@file    : jianzhi_offer_29_missingNumber.py
@concat  : 429546420@qq.com
@site    : 
@software: PyCharm Community Edition 
@desc    :

https://leetcode-cn.com/problems/que-shi-de-shu-zi-lcof/
剑指 offer29 题--找到 0~n-1 中缺失的数字
"""
from typing import List


class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        n = len(nums)

        # 直接循环遍历
        for i in range(n):
            if nums[i] != i:
                return i

        return n

    def missingNumber2(self, nums: List[int]) -> int:
        n = len(nums)
        # 二分查找
        left, right = 0, n - 1
        while left < right:
            mid = int(left + (right - left) / 2)
            if nums[mid] == mid:
                # 表示左侧没有缺失数字
                left = mid+1
            else:
                right = mid
        # 如果 0-n-1 都不缺值，缺的就是 n
        if (left == n-1) and (nums[left] == left):
            return left+1
        else:
            return left

    def missingNumber3(self, nums: List[int]) -> int:
        n = len(nums)
        # 异或法
        res = len(nums)
        for i in range(n):
            res ^= nums[i]
            res ^= i
        return res


if __name__ == '__main__':
    array = [0, 1, 3]
    print('array: ', array)
    solution = Solution()
    print('missing number: ', solution.missingNumber3(array))
