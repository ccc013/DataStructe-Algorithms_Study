#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
@Time    : 2021/2/1 11:14 下午
@Author  : luocai
@file    : jianzhi_offer_41_MedianFinder.py
@concat  : 429546420@qq.com
@site    : 
@software: PyCharm Community Edition 
@desc    :

剑指 Offer 41. 数据流中的中位数
https://leetcode-cn.com/problems/shu-ju-liu-zhong-de-zhong-wei-shu-lcof/
"""
from heapq import *


class MedianFinder:

    def __init__(self):
        """
        initialize your data structure here.
        """
        # 小顶堆，保存较大的一半
        self.A = []
        # 大顶堆，保存较小的一半
        self.B = []

    def addNum(self, num: int) -> None:
        if len(self.A) != len(self.B):
            heappush(self.B, -heappushpop(self.A, num))
        else:
            heappush(self.A, -heappushpop(self.B, -num))

    def findMedian(self) -> float:
        return self.A[0] if len(self.A) != len(self.B) else (self.A[0] - self.B[0]) / 2.0
