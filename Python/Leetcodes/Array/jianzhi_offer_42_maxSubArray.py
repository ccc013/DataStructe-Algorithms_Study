#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
@Time    : 2020/12/12 3:24 下午
@Author  : luocai
@file    : jianzhi_offer_42_maxSubArray.py
@concat  : 429546420@qq.com
@site    : 
@software: PyCharm Community Edition 
@desc    :

https://leetcode-cn.com/problems/lian-xu-zi-shu-zu-de-zui-da-he-lcof/
剑指 offer42 题连续子数组的最大和
"""
from typing import List


class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        # 暴力解法,时间复杂度 O(n^2)
        n = len(nums)
        if n < 1:
            return 0
        max_value = 0
        # 窗口大小
        for window in range(1, n + 1):
            for i in range(0, n - window + 1):
                max_v = sum(nums[i:i + window])
                if max_v > max_value:
                    max_value = max_v
        return max_value

    def maxSubArray2(self, nums: List[int]) -> int:
        # 动态规划，直接修改原数组
        for i in range(1, len(nums)):
            nums[i] += max(nums[i - 1], 0)
        return max(nums)

    def maxSubArray3(self, nums: List[int]) -> int:
        # 动态规划，不修改原数组，但是 O(1)空间复杂度
        pre = nums[0]
        cur = 0
        max_val = nums[0]
        for i in range(1, len(nums)):
            cur = nums[i]
            if pre > 0:
                cur += pre
            if cur > max_val:
                max_val = cur
            pre = cur
        return max_val

    def maxSubArray4(self, nums: List[int]) -> int:
        # 动态规划，采用额外的数组，非 O(1)空间复杂度
        dp = [nums[0]]
        max_val = nums[0]
        for i in range(1, len(nums)):
            dp.append(max(nums[i], nums[i]+dp[i-1]))
            if dp[i] > max_val:
                max_val = dp[i]
        return max_val


if __name__ == '__main__':
    nums = [-2, 1, -3, 4, -1, 2, 1, -5, 4]
    solution = Solution()
    print("result: ", solution.maxSubArray4(nums))
