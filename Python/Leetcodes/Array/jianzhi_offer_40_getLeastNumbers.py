#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
@Time    : 2020/12/19 5:53 下午
@Author  : luocai
@file    : jianzhi_offer_40_getLeastNumbers.py
@concat  : 429546420@qq.com
@site    : 
@software: PyCharm Community Edition 
@desc    :

https://leetcode-cn.com/problems/zui-xiao-de-kge-shu-lcof/
剑指 offer40 题--最小的 k 个数
"""
from typing import List
import random


class Solution:
    def getLeastNumbers(self, arr: List[int], k: int) -> List[int]:
        # 排序然后返回结果
        res = sorted(arr)

        return res[:k]

    def partition(self, nums, l, r):
        pivot = nums[r]
        i = l - 1
        for j in range(l, r):
            if nums[j] <= pivot:
                i += 1
                nums[i], nums[j] = nums[j], nums[i]
        nums[i + 1], nums[r] = nums[r], nums[i + 1]
        return i + 1

    def randomized_partition(self, nums, l, r):
        i = random.randint(l, r)
        nums[r], nums[i] = nums[i], nums[r]
        return self.partition(nums, l, r)

    def randomized_selected(self, arr, l, r, k):
        pos = self.randomized_partition(arr, l, r)
        num = pos - l + 1
        if k < num:
            self.randomized_selected(arr, l, pos - 1, k)
        elif k > num:
            self.randomized_selected(arr, pos + 1, r, k - num)

    def getLeastNumbers2(self, arr: List[int], k: int) -> List[int]:
        if k == 0:
            return list()
        self.randomized_selected(arr, 0, len(arr) - 1, k)
        return arr[:k]


if __name__ == '__main__':
    arr = [3, 2, 1]
    k = 2
    solution = Solution()
    print("result: ", solution.getLeastNumbers2(arr, k))
