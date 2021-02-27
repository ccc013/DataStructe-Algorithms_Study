#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
@Time    : 2021/2/27 2:03 下午
@Author  : luocai
@file    : 169_majorityElement.py
@concat  : 429546420@qq.com
@site    : 
@software: PyCharm Community Edition 
@desc    :

169. 多数元素
https://leetcode-cn.com/problems/majority-element/
"""
from typing import List


class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        # 哈希表
        dic = {}
        n = len(nums)
        for i in nums:
            if i not in dic:
                dic[i] = 0
            dic[i] += 1
            if dic[i] > n / 2:
                return i

    def majorityElement2(self, nums: List[int]) -> int:
        # 记录当前元素和其出现次数
        res, count = nums[0], 1
        # 遍历数组，当元素和当前记录元素一样，计数+1，否则计数-1，变成 0 的时候，修改记录的元素为当前元素¬
        for i in range(len(nums)):
            if nums[i] == res:
                count += 1
            else:
                count -= 1
            if count == 0:
                res = nums[i]
                count = 1
        return res


if __name__ == '__main__':
    solution = Solution()
    print("result: ", solution.majorityElement2([2, 2, 1, 1, 1, 2, 2]))
