#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
@Time    : 2020/12/5 12:29 上午
@Author  : luocai
@file    : jianzhi_offer_09_2StackToQueue.py
@concat  : 429546420@qq.com
@site    : 
@software: PyCharm Community Edition 
@desc    :

https://leetcode-cn.com/problems/yong-liang-ge-zhan-shi-xian-dui-lie-lcof/

剑指 offer09 题--用两个栈实现一个队列
"""


class CQueue:

    def __init__(self):
        # 栈 1，专门用来存放入队的元素
        self.stack_in = []
        # 栈 2，专门用来存放要出队的元素
        self.stack_out = []

    def appendTail(self, value: int) -> None:
        self.stack_in.append(value)

    def deleteHead(self) -> int:
        if not self.stack_out:
            if not self.stack_in:
                # 都是空
                return -1
            else:
                while self.stack_in:
                    # 将入栈的元素都放到出栈中
                    self.stack_out.append(self.stack_in.pop())

        return self.stack_out.pop()


if __name__ == '__main__':
    # action_list = ["CQueue", "appendTail", "deleteHead", "deleteHead"]
    action_list = ["CQueue", "deleteHead", "appendTail", "appendTail", "deleteHead", "deleteHead"]
    # val = [[], [3], [], []]
    val = [[], [], [5], [2], [], []]
    for i, action in enumerate(action_list):
        if action == "CQueue":
            obj = CQueue()
        elif action == "appendTail":
            insert_list = val[i]
            for v in insert_list:
                obj.appendTail(v)
        elif action == "deleteHead":
            print("delete head=", obj.deleteHead())
