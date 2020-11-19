#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
@Time    : 2020/11/17 10:52 下午
@Author  : luocai
@file    : jianzhi_offer_22_getKthFromEnd.py
@concat  : 429546420@qq.com
@site    : 
@software: PyCharm Community Edition 
@desc    :

https://leetcode-cn.com/problems/lian-biao-zhong-dao-shu-di-kge-jie-dian-lcof/
剑指 offer 的 22 题，链表中倒数第 K 个节点
"""

class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def getKthFromEnd(self, head: ListNode, k: int) -> ListNode:
        # 哨兵指针
        dummy = ListNode(None)
        dummy.next = head
        # 快慢指针
        p = q = dummy
        # 快指针先走 k+1 步
        for i in range(k+1):
            p = p.next
        # 同时走
        while p:
            p, q = p.next, q.next
        return q.next


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


def print_linked_list(head):
    cur = head
    vals = list()
    while cur:
        vals.append(cur.val)
        cur = cur.next
    print('->'.join('{}'.format(val) for val in vals))


if __name__ == '__main__':
    # 建立一个链表
    val_a = [1, 2, 3, 4, 5]

    linked_list = build_linked_list(val_a)
    print_linked_list(linked_list)

    solution = Solution()
    new_linked_list = solution.getKthFromEnd(linked_list, 2)
    print_linked_list(new_linked_list)
