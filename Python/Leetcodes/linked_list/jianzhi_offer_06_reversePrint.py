#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
@Time    : 2020/12/3 8:00 上午
@Author  : luocai
@file    : jianzhi_offer_06_reversePrint.py
@concat  : 429546420@qq.com
@site    : 
@software: PyCharm Community Edition 
@desc    :

https://leetcode-cn.com/problems/cong-wei-dao-tou-da-yin-lian-biao-lcof/
剑指 offer06 题--从尾到头打印链表
"""

from Linked_list.Linked_list import ListNode
from typing import List


class Solution:
    def reversePrint(self, head: ListNode) -> List[int]:
        res = []
        # 先反转链表
        prev, cur = None, head
        while cur:
            res.insert(0, cur.val)
            prev, cur.next, cur = cur, prev, cur.next

        # 遍历链表，并保存数值到数组
        # while prev:
        #     res.append(prev.val)
        #     prev = prev.next

        return res

    def reversePrint2(self, head: ListNode) -> List[int]:
        res = []

        while head:
            res.append(head.val)
            head = head.next

        return res[::-1]

    def reversePrint3(self, head: ListNode) -> List[int]:
        return self.reversePrint3(head.next) + [head.val] if head else []


if __name__ == '__main__':
    # 建立一个链表
    val_a = [1, 2, 3, 4, 5]
    linked_list_a = ListNode.build_linked_list(val_a)
    ListNode.print_linked_list(linked_list_a)
    solution = Solution()
    print("反转的链表:", solution.reversePrint3(linked_list_a))
