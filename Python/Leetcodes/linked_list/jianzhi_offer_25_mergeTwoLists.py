#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
@Time    : 2021/2/10 6:18 下午
@Author  : luocai
@file    : jianzhi_offer_25_mergeTwoLists.py
@concat  : 429546420@qq.com
@site    : 
@software: PyCharm Community Edition 
@desc    :

剑指 Offer 25. 合并两个排序的链表
https://leetcode-cn.com/problems/he-bing-liang-ge-pai-xu-de-lian-biao-lcof/
"""


# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        if not l1:
            return l2
        if not l2:
            return l1

        if l1.val <= l2.val:
            new_head = cur = l1
            l1 = l1.next
        else:
            new_head = cur = l2
            l2 = l2.next
        while l1 or l2:
            if l1 is None:
                cur.next = l2
                return new_head
            if l2 is None:
                cur.next = l1
                return new_head
            if l1.val <= l2.val:
                cur.next = l1
                l1 = l1.next
            else:
                cur.next = l2
                l2 = l2.next
            cur = cur.next

        return new_head
