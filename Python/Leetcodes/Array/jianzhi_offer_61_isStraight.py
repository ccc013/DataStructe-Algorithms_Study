#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
@Time    : 2020/12/24 11:21 下午
@Author  : luocai
@file    : jianzhi_offer_61_isStraight.py
@concat  : 429546420@qq.com
@site    : 
@software: PyCharm Community Edition 
@desc    :

https://leetcode-cn.com/problems/bu-ke-pai-zhong-de-shun-zi-lcof/
剑指 Offer 61. 扑克牌中的顺子
"""
from typing import List


class Solution:
    def isStraight(self, nums: List[int]) -> bool:
        # 集合+遍历
        repeat = set()
        min_val, max_val = 14, 0
        for num in nums:
            if num == 0:
                # 遇到 0 就跳过
                continue
            min_val = min(min_val, num)
            max_val = max(max_val, num)
            if num in repeat:
                # 出现重复
                return False
            repeat.add(num)
        # 第二个条件，最大值和最小值之差小于 5
        return max_val - min_val < 5

    def isStraight2(self, nums: List[int]) -> bool:
        # 排序+遍历
        min_index = 0
        # 排序
        nums.sort()
        for i in range(4):
            if nums[i] == 0:
                min_index += 1
            elif nums[i] == nums[i + 1]:
                return False
        return nums[4] - nums[min_index] < 5


if __name__ == '__main__':
    a = [0, 0, 1, 2, 5]
    solution = Solution()
    print("result: ", solution.isStraight2(a))
