#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
@Time    : 2021/3/1 10:14 下午
@Author  : luocai
@file    : 448_findDisappearedNumbers.py
@concat  : 429546420@qq.com
@site    : 
@software: PyCharm Community Edition 
@desc    :

448. 找到所有数组中消失的数字
https://leetcode-cn.com/problems/find-all-numbers-disappeared-in-an-array/
"""
from typing import List


class Solution:
    def findDisappearedNumbers(self, nums: List[int]) -> List[int]:
        n = len(nums)
        dic = {i: 0 for i in range(1, n + 1)}
        res = []

        for e in nums:
            dic[e] += 1
        for i, count in dic.items():
            if count < 1:
                res.append(i)
        return res

    def findDisappearedNumbers2(self, nums: List[int]) -> List[int]:
        n = len(nums)
        for num in nums:
            # 还原该位置的原始数值
            x = (num - 1) % n
            # +n 表示出现过一次
            nums[x] += n

        res = [i + 1 for i, num in enumerate(nums) if num <= n]
        return res
