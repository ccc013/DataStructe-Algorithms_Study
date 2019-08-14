#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
@Time    : 2019/8/14 8:27
@Author  : luocai
@file    : circular_queue.py
@concat  : 429546420@qq.com
@site    : 
@software: PyCharm Community Edition 
@desc    :

基于数组实现的循环队列
参考：https://github.com/wangzheng0822/algo/blob/master/python/09_queue/circular_queue.py
"""
from itertools import chain


class CircularQueue:
    def __init__(self, numbers):
        self.items = list()
        # 循环队列的大小，在计划的大小添加 1，因为队列满的判断条件问题
        self.n = numbers + 1
        # 指向队头，用于出队操作
        self.head = 0
        # 指向队尾，用于进行入队操作
        self.tail = 0

    def enqueue(self, val) -> bool:
        '''
        入队
        :param val:
        :return:
        '''
        if (self.tail + 1) % self.n == self.head:
            return False
        self.items.append(val)
        self.tail = (self.tail + 1) % self.n
        print('tail=', self.tail)
        return True

    def dequeue(self):
        '''
        出队
        :return:
        '''
        if self.head == self.tail:
            return None
        val = self.items[self.head]
        self.head = (self.head + 1) % self.n
        return val

    def __repr__(self):
        if self.tail >= self.head:
            return " ".join(item for item in self.items[self.head: self.tail])
        else:
            return " ".join(item for item in chain(self.items[self.head:], self.items[:self.tail]))


if __name__ == '__main__':
    q = CircularQueue(5)
    for i in range(5):
        q.enqueue(str(i))
    print('打印循环队列: ', q)
    q.dequeue()
    q.dequeue()
    q.enqueue(str(5))
    print('打印循环队列: ', q)
