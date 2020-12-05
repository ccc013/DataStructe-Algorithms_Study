#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
@Time    : 2020/12/5 10:58 上午
@Author  : luocai
@file    : jianzhi_offer_18_deleteNode.py
@concat  : 429546420@qq.com
@site    : 
@software: PyCharm Community Edition 
@desc    :

https://leetcode-cn.com/problems/shan-chu-lian-biao-de-jie-dian-lcof/
剑指 offer18 题--删除链表的节点
"""
from Linked_list.Linked_list import ListNode
from typing import List


class Solution():
    def deleteNode(self, head: ListNode, val: int) -> ListNode:
        if not head:
            return None
        cur = head

        while cur:
            if cur.val == val:
                cur.val = cur.next.val
                cur.next = cur.next.next
                break
            if cur.next.next:
                cur = cur.next
            else:
                # 需要删除的是尾结点
                cur.next = None
                break

        return head

    # 递归
    def deleteNode2(self, head: ListNode, val: int) -> ListNode:
        if not head:
            return None
        if head.val == val:
            return head.next
        head.next = self.deleteNode2(head.next, val)
        return head


if __name__ == '__main__':
    # 建立一个链表
    val_a = [1, 2, 3, 4, 5]
    linked_list_a = ListNode.build_linked_list(val_a)
    ListNode.print_linked_list(linked_list_a)
    solution = Solution()
    solution.deleteNode2(linked_list_a, 5)
    ListNode.print_linked_list(linked_list_a)
