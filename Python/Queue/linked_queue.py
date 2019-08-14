#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
@Time    : 2019/8/14 8:09
@Author  : luocai
@file    : linked_queue.py
@concat  : 429546420@qq.com
@site    : 
@software: PyCharm Community Edition 
@desc    :

基于链表实现的队列
"""
from typing import Optional


# 链表结点类
class Node:
    def __init__(self, data: int, next=None):
        self.data = data
        self.next = next


class LinkedQueue:
    def __init__(self):
        self.head = None
        self.tail = None

    def enqueue(self, val):
        new_node = Node(val)
        if self.tail:
            self.tail.next = new_node
        else:
            # 当前队列为空
            self.head = new_node
        self.tail = new_node

    def dequeue(self) -> bool:
        if self.head:
            val = self.head.data
            self.head = self.head.next
            if not self.head:
                self.tail = None
            return val

    def __repr__(self) -> str:
        cur = self.head
        vals = list()
        while cur != self.tail:
            vals.append(cur.data)
            cur = cur.next
        return '->'.join(str(v) for v in vals)


if __name__ == '__main__':
    datas = [2, 3, 11, 0]
    linked_queue = LinkedQueue()
    for i in datas:
        linked_queue.enqueue(i)
    print('打印队列: ', linked_queue)
    print('输出队列: ', linked_queue.dequeue())
    print('输出队列: ', linked_queue.dequeue())
    print('打印队列: ', linked_queue)
