#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
@Time    : 2020/12/8 11:31 下午
@Author  : luocai
@file    : jianzhi_offer_57_twoSum.py
@concat  : 429546420@qq.com
@site    : 
@software: PyCharm Community Edition 
@desc    :

https://leetcode-cn.com/problems/he-wei-sde-liang-ge-shu-zi-lcof/
剑指 offer57 题--和为 s 的两个数字
"""
from typing import List


class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        # 哈希表法
        res = {}
        for i in nums:
            if i in res:
                return [i, res[i]]
            else:
                res[target - i] = i
        return []

    def twoSum2(self, nums: List[int], target: int) -> List[int]:
        # 双指针法
        i, j = 0, len(nums) - 1
        while i < j:
            s = nums[i] + nums[j]
            if s == target:
                return [nums[i], nums[j]]
            elif s < target:
                i += 1
            else:
                j -= 1
        return []

    def twoSum3(self, nums: List[int], target: int) -> List[int]:
        # 二分查找法
        n = len(nums) - 1
        for i in range(n):
            t = target - nums[i]
            left, right = i + 1, len(nums) - 1
            while left <= right:
                mid = (left + right) >> 1
                if nums[mid] == t:
                    return [nums[i], t]
                elif nums[mid] < t:
                    left = mid + 1
                else:
                    right = mid - 1
        return []


if __name__ == '__main__':
    nums = [10, 26, 30, 31, 47, 60]
    target = 40
    solution = Solution()
    print(solution.twoSum3(nums, target))
