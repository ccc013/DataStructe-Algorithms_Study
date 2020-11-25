#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
@Time    : 2020/11/26 7:19 上午
@Author  : luocai
@file    : 34_searchRange.py
@concat  : 429546420@qq.com
@site    : 
@software: PyCharm Community Edition 
@desc    :


https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/
leetcode 34题--在排序数组中查找元素的第一个和最后一个位置
"""


class Solution:
    def searchRange(self, nums, target: int):
        res = [-1, -1]
        n = len(nums)
        left, right = 0, n - 1
        while left < right:
            mid = int((left + right) / 2)
            if nums[mid] >= target:
                right = mid
            else:
                left = mid + 1
        while left < n and nums[left] == target:
            if res[0] == -1:
                res[0] = left
            left += 1
        if res[0] != -1:
            res[1] = left - 1
        return res


if __name__ == '__main__':
    array = [5, 7, 7, 8, 8, 10]
    print("origin array: ", array)
    solution = Solution()
    print("range: ", solution.searchRange(array, 9))
