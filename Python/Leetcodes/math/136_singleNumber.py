#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
@Time    : 2021/2/26 7:48 上午
@Author  : luocai
@file    : 136_singleNumber.py
@concat  : 429546420@qq.com
@site    : 
@software: PyCharm Community Edition 
@desc    :

136. 只出现一次的数字
https://leetcode-cn.com/problems/single-number/
"""
from typing import List


class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        res = nums[0]

        for i in range(1, len(nums)):
            res ^= nums[i]

        return res


if __name__ == '__main__':
    solution = Solution()
    print("result: ", solution.singleNumber([4, 1, 2, 1, 2]))
