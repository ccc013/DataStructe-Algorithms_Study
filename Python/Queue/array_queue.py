#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
@Time    : 2019/8/14 7:42
@Author  : luocai
@file    : array_queue.py
@concat  : 429546420@qq.com
@site    : 
@software: PyCharm Community Edition 
@desc    :

基于数组实现的顺序队列
"""
from typing import Optional


class ArrayQueue:
    def __init__(self, numbers):
        self.items = list()
        # 顺序队列的大小
        self.n = numbers
        # 指向队头，用于出队操作
        self.head = 0
        # 指向队尾，用于进行入队操作
        self.tail = 0

    def is_empty(self):
        return self.head == self.tail

    def enqueue(self, val) -> bool:
        '''
        入队操作
        :param val:
        :return:
        '''
        # tail==n 表示队列满了
        if self.tail == self.n:
            # head==0 表示队列确实已满，不存在空闲位置
            if self.head == 0:
                return False
            else:
                # 当前队列存在空闲位置，进行数据搬移
                # method 1，for 循环
                # for index in range(self.head, self.tail):
                #     self.items[index - self.head] = self.items[index]
                # method 2，切片方式
                self.items[0: self.tail - self.head] = self.items[self.head:self.tail]
                self.tail -= self.head
                self.head = 0

        if self.tail == len(self.items):
            self.items.append(val)
        else:
            # 数据搬移后
            self.items[self.tail] = val
        self.tail += 1
        return True

    def dequeue(self) -> Optional[int]:
        '''
        出队
        :return:
        '''
        if self.is_empty():
            return None

        val = self.items[self.head]
        self.head += 1
        return val

    def __repr__(self):
        '''
        打印队列
        :return:
        '''
        cur = self.head
        vals = list()
        while cur < self.tail:
            vals.append(self.items[cur])
            cur += 1
        return ' '.join('{},'.format(v) for v in vals)


if __name__ == '__main__':
    queue_numbers = 10
    array_queue = ArrayQueue(queue_numbers)
    print('刚开始建立顺序队列，判断队列是否为空: ', array_queue.is_empty())
    for i in range(queue_numbers):
        array_queue.enqueue(i)
    print('打印队列: ', array_queue)
    print('出队: ', array_queue.dequeue())
    print('出队: ', array_queue.dequeue())
    print('出队: ', array_queue.dequeue())
    print('打印队列: ', array_queue)
    array_queue.enqueue(11)
    array_queue.enqueue(13)
    array_queue.enqueue(15)
    print('打印队列: ', array_queue)