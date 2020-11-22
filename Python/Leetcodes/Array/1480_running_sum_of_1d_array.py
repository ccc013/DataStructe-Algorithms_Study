#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
@Time    : 2020/11/22 6:44 下午
@Author  : luocai
@file    : 1480_running_sum_of_1d_array.py
@concat  : 429546420@qq.com
@site    : 
@software: PyCharm Community Edition 
@desc    :

https://leetcode-cn.com/problems/running-sum-of-1d-array/
1480题：一维数组的动态和
"""


class Solution:
    def runningSum(self, nums):
        # 累加和
        sums = 0
        n = len(nums)
        for i in range(n):
            sums += nums[i]
            nums[i] = sums

        return nums

    def runningSum2(self, nums):
        n = len(nums)
        for i in range(1, n):
            nums[i] += nums[i - 1]

        return nums


if __name__ == '__main__':
    array = [1, 2, 3, 4, 5]
    print("origin array: ", array)
    solution = Solution()
    print("after running sum of array: ", solution.runningSum(array))
