#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
@Time    : 2020/12/3 10:37 下午
@Author  : luocai
@file    : jianzhi_offer_39_majorityElement.py
@concat  : 429546420@qq.com
@site    : 
@software: PyCharm Community Edition 
@desc    :

https://leetcode-cn.com/problems/shu-zu-zhong-chu-xian-ci-shu-chao-guo-yi-ban-de-shu-zi-lcof/
剑指 offer 39 题--数组中出现次数超过一半的数字
"""
from typing import List


class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        # 先排序，然后返回数组中间的数值
        nums.sort()
        middle = int(len(nums) / 2)

        return nums[middle]

    def majorityElement2(self, nums: List[int]) -> int:
        # 哈希表法
        num_dict = {}
        n = len(nums)
        for val in nums:
            if val not in num_dict:
                num_dict[val] = 0
            num_dict[val] += 1
            if num_dict[val] > n / 2:
                return val

    def majorityElement3(self, nums: List[int]) -> int:
        # 摩尔投票法
        votes = 0
        for n in nums:
            if votes == 0:
                x = n
            votes += 1 if n == x else -1

        return x


if __name__ == '__main__':
    array = [1, 2, 3, 2, 2, 2, 5, 4, 2]
    print('array: ', array)
    solution = Solution()
    print("数组出现次数超过数组长度一半的数字:", solution.majorityElement3(array))
