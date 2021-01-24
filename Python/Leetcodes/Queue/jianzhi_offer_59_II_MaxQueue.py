#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
@Time    : 2021/1/23 11:06 下午
@Author  : luocai
@file    : jianzhi_offer_59_II_MaxQueue.py
@concat  : 429546420@qq.com
@site    : 
@software: PyCharm Community Edition 
@desc    :

https://leetcode-cn.com/problems/dui-lie-de-zui-da-zhi-lcof/
剑指 offer 59 题 II 队列的最大值
"""
import queue


class MaxQueue:

    def __init__(self):
        self.q = queue.Queue()
        self.deque = queue.deque()

    def max_value(self) -> int:
        return self.deque[0] if self.deque else -1

    def push_back(self, value: int) -> None:
        self.q.put(value)
        # 将双向队列的队尾元素小于插入值的都弹出
        while self.deque and self.deque[-1] < value:
            self.deque.pop()
        self.deque.append(value)

    def pop_front(self) -> int:
        if self.q.empty():
            return -1
        value = self.q.get()
        if value == self.deque[0]:
            self.deque.popleft()
        return value
