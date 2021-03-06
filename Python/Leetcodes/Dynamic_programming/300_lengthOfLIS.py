#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
@Time    : 2021/3/6 9:09 上午
@Author  : luocai
@file    : 300_lengthOfLIS.py
@concat  : 429546420@qq.com
@site    : 
@software: PyCharm Community Edition 
@desc    :

300. 最长递增子序列
https://leetcode-cn.com/problems/longest-increasing-subsequence/
"""
from typing import List


class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        if not nums:
            return 0
        n = len(nums)
        dp = [1 for i in range(n)]

        for i in range(1, n):
            # 遍历每个子序列
            for j in range(i):
                if nums[i] > nums[j]:
                    dp[i] = max(dp[i], dp[j] + 1)

        return max(dp)


if __name__ == '__main__':
    solution = Solution()
    print(solution.lengthOfLIS([10, 9, 2, 5, 3, 7, 101, 18]))
