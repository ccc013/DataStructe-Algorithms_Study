#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
@Time    : 2019/8/8 22:29
@Author  : luocai
@file    : 206_Reverse_Linked_List.py
@concat  : 429546420@qq.com
@site    : 
@software: PyCharm Community Edition 
@desc    :

https://leetcode.com/problems/reverse-linked-list/
链表反转
"""


class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        pre, cur = None, head
        while cur:
            pre, pre.next, cur = cur, pre, cur.next
        return pre


if __name__ == '__main__':
    # 建立一个链表
    val = [3, 2, 0, -1]
    old_node = None
    head = None
    for i, _val in enumerate(val):
        node = ListNode(_val)
        if i > 0:
            old_node.next = node
            old_node = node
        else:
            head = node
            old_node = node

    solution = Solution()
    reversed_head = solution.reverseList(head)
    while reversed_head:
        print(reversed_head.val, end=', ')
        reversed_head = reversed_head.next
