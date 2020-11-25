#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
@Time    : 2020/11/25 7:45 上午
@Author  : luocai
@file    : jianzhi_offer_53_find_numbers_in_sorted_array.py
@concat  : 429546420@qq.com
@site    : 
@software: PyCharm Community Edition 
@desc    :

https://leetcode-cn.com/problems/zai-pai-xu-shu-zu-zhong-cha-zhao-shu-zi-lcof/
剑指 offer53--查找目标元素在数组中出现的次数
"""


class Solution:
    def search(self, nums, target: int) -> int:
        if target not in nums:
            return 0
        count = 0
        n = len(nums)
        for i in range(n):
            if target == nums[i]:
                count += 1
            elif count > 0:
                break
        return count

    def search2(self, nums, target: int) -> int:
        # 二分查找
        n = len(nums)
        left, right = 0, n-1
        count = 0
        while left < right:
            mid = int((left+right)/2)
            if nums[mid] >= target:
                right = mid
            else:
                left = mid + 1
        while left < n and nums[left] == target:
            count += 1
            left += 1
        return count


if __name__ == '__main__':
    array = [5, 7, 8, 8, 8, 10]
    print("origin array: ", array)
    solution = Solution()
    print("numbers: ", solution.search2(array, 8))
