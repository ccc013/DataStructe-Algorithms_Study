#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
@Time    : 2019/8/5 7:58
@Author  : luocai
@file    : array_stack.py
@concat  : 429546420@qq.com
@site    : 
@software: PyCharm Community Edition 
@desc    :

基于数组实现的栈
"""
from typing import Optional


class ArrayStack:
    def __init__(self, nums):
        # 初始化数组
        self._data = list()
        # 数组的大小
        self._nums = nums
        # 数组元素个数
        self._count = 0

    def push(self, data) -> bool:
        '''
        入栈
        :param data:
        :return:
        '''
        if (self._count + 1) == self._nums:
            # 栈已经满了
            return False

        self._data.append(data)
        self._count += 1
        return True

    def pop(self) -> Optional[int]:
        '''
        出栈
        :return:
        '''
        if self._count:
            value = self._data[self._count - 1]
            self._data.pop(self._count - 1)
            self._count -= 1
            return value

    def __repr__(self) -> str:
        '''
        打印栈
        :return:
        '''
        nums = reversed(self._data)

        return " ".join("[{}]".format(num) for num in nums)


if __name__ == '__main__':
    stack = ArrayStack(10)

    for i in range(15):
        stack.push(i)
    print(stack)

    for _ in range(5):
        stack.pop()
    print(stack)
