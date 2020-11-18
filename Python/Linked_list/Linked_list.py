#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
@Time    : 2020/11/19 7:48 上午
@Author  : luocai
@file    : Linked_list.py
@concat  : 429546420@qq.com
@site    : 
@software: PyCharm Community Edition 
@desc    :

链表的基类
"""


class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

    @staticmethod
    def build_linked_list(vals):
        cur = None
        head = None
        for i, _val in enumerate(vals):
            node = ListNode(_val)
            if i > 0:
                cur.next = node
                cur = node
            else:
                head = node
                cur = node
        return head

    @staticmethod
    def print_linked_list(head):
        cur = head
        vals = list()
        while cur:
            vals.append(cur.val)
            cur = cur.next
        print('->'.join('{}'.format(val) for val in vals))


if __name__ == '__main__':
    print("test")
    link_list = ListNode.build_linked_list([1, 2, 3])
    ListNode.print_linked_list(link_list)
