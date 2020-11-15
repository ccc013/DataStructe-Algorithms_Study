#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
@Time    : 2020/11/15 8:12 下午
@Author  : luocai
@file    : 24_swap_nodes_in_pairs.py
@concat  : 429546420@qq.com
@site    : 
@software: PyCharm Community Edition 
@desc    :

https://leetcode-cn.com/problems/swap-nodes-in-pairs/
两两交换链表中的节点
"""


class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def swapPairs(self, head: ListNode) -> ListNode:
        pre, pre.next = self, head
        while pre.next and pre.next.next:
            a = pre.next
            b = a.next
            # 进行交换
            pre.next, a.next, b.next = b, b.next, a
            pre = a
        return self.next


if __name__ == '__main__':
    # 建立一个链表
    val = [1, 2, 3, 4]
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
    reversed_head = solution.swapPairs(head)
    while reversed_head:
        print(reversed_head.val, end=', ')
        reversed_head = reversed_head.next
