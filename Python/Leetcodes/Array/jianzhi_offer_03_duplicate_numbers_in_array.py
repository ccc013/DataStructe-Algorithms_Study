#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
@Time    : 2020/11/25 7:02 上午
@Author  : luocai
@file    : jianzhi_offer_03_duplicate_numbers_in_array.py
@concat  : 429546420@qq.com
@site    : 
@software: PyCharm Community Edition 
@desc    :

https://leetcode-cn.com/problems/shu-zu-zhong-zhong-fu-de-shu-zi-lcof/
剑指 offer03 题--数组中重复的数字
"""


class Solution:
    # 采用一个额外的空间进行辅助, 时间复杂度O(n），空间复杂度 O(n)
    def findRepeatNumber(self, nums) -> int:
        tmp = set()
        for i in nums:
            if i in tmp:
                return i
            tmp.add(i)

    # 插入排序，时间复杂度O(n^2），空间复杂度 O(1)
    def findRepeatNumber2(self, nums) -> int:
        n = len(nums)
        for i in range(1, n):
            val = nums[i]
            j = i - 1
            while j >= 0 and nums[j] >= val:
                if nums[j] == val:
                    return val
                nums[j + 1] = nums[j]
                j -= 1
            nums[j + 1] = val

    # 直接排序,时间复杂度O(nlogn），空间复杂度 O(1)
    def findRepeatNumber3(self, nums) -> int:
        nums.sort()
        pre = nums[0]
        n = len(nums)
        for i in range(1, n):
            if pre == nums[i]:
                return pre
            pre = nums[i]

    # 判断 nums[i] 是否等于 i，时间复杂度 O(n),空间复杂度 O(1)
    def findRepeatNumber4(self, nums) -> int:
        n = len(nums)
        for i in range(n):
            while i != nums[i]:
                if nums[i] == nums[nums[i]]:
                    return nums[i]
                temp = nums[i]
                # #   注意这里不要写成nums[i], nums[nums[i]] = nums[nums[i]], nums[i]
                nums[i], nums[temp] = nums[temp], nums[i]


if __name__ == '__main__':
    array = [2, 3, 1, 0, 2, 5, 3]
    print("origin array: ", array)
    solution = Solution()
    print("duplicate num: ", solution.findRepeatNumber2(array))
