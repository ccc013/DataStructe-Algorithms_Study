#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
@Time    : 2021/2/27 3:34 下午
@Author  : luocai
@file    : 160_getIntersectionNode.py
@concat  : 429546420@qq.com
@site    : 
@software: PyCharm Community Edition 
@desc    :

160. 相交链表
https://leetcode-cn.com/problems/intersection-of-two-linked-lists/
"""


# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> ListNode:
        if not headA or not headB:
            return None
        pa, pb = headA, headB
        while pa != pb:
            pa = pa.next if pa else headB
            pb = pb.next if pb else headA

        return pa
