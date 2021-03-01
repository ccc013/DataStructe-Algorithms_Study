#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
@Time    : 2021/3/2 7:27 上午
@Author  : luocai
@file    : 155_minStack.py
@concat  : 429546420@qq.com
@site    : 
@software: PyCharm Community Edition 
@desc    :

155. 最小栈
https://leetcode-cn.com/problems/min-stack/
"""


class MinStack:

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.stack = []
        self.min_vals = []

    def push(self, x: int) -> None:
        self.stack.append(x)
        if not self.min_vals or x <= self.min_vals[-1]:
            self.min_vals.append(x)

    def pop(self) -> None:
        if self.stack.pop() == self.min_vals[-1]:
            self.min_vals.pop()

    def top(self) -> int:
        return self.stack[-1]

    def getMin(self) -> int:
        return self.min_vals[-1]


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(x)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()

if __name__ == '__main__':
    min_stack = MinStack()
    min_stack.push(-2)
    min_stack.push(0)
    min_stack.push(-3)
    print(min_stack.getMin())
    print(min_stack.pop())
    print(min_stack.top())
    print(min_stack.getMin())
