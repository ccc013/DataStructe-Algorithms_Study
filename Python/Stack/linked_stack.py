#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
@Time    : 2019/8/5 7:47
@Author  : luocai
@file    : linked_stack.py
@concat  : 429546420@qq.com
@site    : 
@software: PyCharm Community Edition 
@desc    :  Stack based upon linked list--基于链表实现的栈

参考 https://github.com/wangzheng0822/algo/blob/master/python/08_stack/linked_stack.py


"""
from typing import Optional


# 链表结点类
class Node:
    def __init__(self, data: int, next=None):
        self._data = data
        self._next = next


class LinkedStack:
    """
    链表实现的栈
    """

    def __init__(self):
        self._top = None

    def push(self, value: int):
        '''
        入栈，将新结点放在链表首部
        :param value:
        :return:
        '''
        new_top = Node(value)
        new_top._next = self._top
        self._top = new_top

    def pop(self) -> Optional[int]:
        if self._top:
            value = self._top._data
            self._top = self._top._next
            return value

    def __repr__(self) -> str:
        '''
        打印栈元素
        :return:
        '''
        current = self._top
        nums = []
        while current:
            nums.append(current._data)
            current = current._next
        return " ".join("[{}]".format(num) for num in nums)


if __name__ == '__main__':
    stack = LinkedStack()
    # 入栈
    for i in range(9):
        stack.push(i)
    print('入栈结果: ', stack)
    # 出栈
    for _ in range(3):
        stack.pop()
    print('出栈结果: ', stack)
