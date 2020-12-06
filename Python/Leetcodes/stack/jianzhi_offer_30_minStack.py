#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
@Time    : 2020/12/6 11:05 上午
@Author  : luocai
@file    : jianzhi_offer_30_minStack.py
@concat  : 429546420@qq.com
@site    : 
@software: PyCharm Community Edition 
@desc    :

https://leetcode-cn.com/problems/bao-han-minhan-shu-de-zhan-lcof/
剑指 offer30--包含 min 函数的栈
"""


# 辅助栈
class MinStack:

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.stack = []
        self.min_stack = []

    def push(self, x: int) -> None:
        self.stack.append(x)
        if not self.min_stack or x <= self.min_stack[-1]:
            self.min_stack.append(x)

    def pop(self) -> None:
        if self.stack.pop() == self.min_stack[-1]:
            self.min_stack.pop()

    def top(self) -> int:
        return self.stack[-1]

    def min(self) -> int:
        return self.min_stack[-1]


# 单栈实现 1
class Minstack2:

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.stack = []
        self.min_val = float('inf')

    def push(self, x: int) -> None:
        # 新元素小于最小值，更新最小值，并将之前的最小值插入栈中
        if x <= self.min_val:
            self.stack.append(self.min_val)
            self.min_val = x

        self.stack.append(x)

    def pop(self) -> None:
        if self.stack.pop() == self.min_val:
            # 栈顶元素就是最小值，更新最小值
            self.min_val = self.stack.pop()

    def top(self) -> int:
        return self.stack[-1]

    def min(self) -> int:
        return self.min_val


# 单栈实现，差值法
class Minstack3:

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.stack = []
        self.min_val = float('inf')

    def push(self, x: int) -> None:
        # 每次保存插入元素和最小值的差值
        self.stack.append(x - self.min_val)
        if x < self.min_val:
            self.min_val = x

    def pop(self) -> None:
        if not self.stack:
            return
        tmp = self.stack.pop()
        # 如果弹出的是负值，说明当前栈顶元素是最小值，需要更新最小值
        if tmp < 0:
            self.min_val -= tmp

    def top(self) -> int:
        if not self.stack:
            return
        tmp = self.stack[-1]
        # 如果弹出的是负值,那么此时的栈顶元素就是当前最小值
        if tmp < 0:
            return self.min_val
        else:
            return self.min_val + tmp

    def min(self) -> int:
        return self.min_val


if __name__ == '__main__':
    min_stack = Minstack2()
    for i in [-2, 0, -3]:
        min_stack.push(i)
    print("min: ", min_stack.min())
    min_stack.pop()
    print("top: ", min_stack.top())
    print("min: ", min_stack.min())
