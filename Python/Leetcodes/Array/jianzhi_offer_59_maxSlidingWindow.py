#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
@Time    : 2020/12/12 2:17 下午
@Author  : luocai
@file    : jianzhi_offer_59_maxSlidingWindow.py
@concat  : 429546420@qq.com
@site    : 
@software: PyCharm Community Edition 
@desc    :

https://leetcode-cn.com/problems/hua-dong-chuang-kou-de-zui-da-zhi-lcof/
剑指 offer59 题--滑动窗口的最大值
"""
from typing import List
import collections


class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        n = len(nums)
        res = []
        if n < 1:
            return res
        for i in range(n - k + 1):
            res.append(max(nums[i:i + k]))
        return res

    def maxSlidingWindow2(self, nums: List[int], k: int) -> List[int]:
        # 单调队列
        n = len(nums)
        res = []
        if n < 1:
            return res
        deque = collections.deque()
        # 开始构建第一个窗口
        for i in range(k):
            while deque and deque[-1] < nums[i]:
                deque.pop()
            deque.append(nums[i])
        res.append(deque[0])
        # 开始进行滑动
        for i in range(k, n):
            if deque[0] == nums[i - k]:
                # 删除队首元素
                deque.popleft()
            while deque and deque[-1] < nums[i]:
                # 保证队列非严格递减
                deque.pop()
            deque.append(nums[i])
            # 队首元素就是当前窗口最大值
            res.append(deque[0])
        return res


if __name__ == '__main__':
    nums = [1, 3, -1, -3, 5, 3, 6, 7]
    k = 3
    solution = Solution()
    print("result: ", solution.maxSlidingWindow2(nums, k))
