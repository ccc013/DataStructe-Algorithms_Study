#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
@Time    : 2020/12/7 11:27 下午
@Author  : luocai
@file    : jianzhi_offer_52_getIntersectionNode.py
@concat  : 429546420@qq.com
@site    : 
@software: PyCharm Community Edition 
@desc    :

https://leetcode-cn.com/problems/liang-ge-lian-biao-de-di-yi-ge-gong-gong-jie-dian-lcof/
剑指 offer52 题--两个链表的第一个公共节点
"""
from Linked_list.Linked_list import ListNode
from typing import List


class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> ListNode:
        if not headA or not headB:
            return None
        node_a, node_b = headA, headB

        # 双指针，当走到末尾后，指针指向对方链表的头部，继续遍历
        while node_a != node_b:
            node_a = node_a.next if node_a else headB
            node_b = node_b.next if node_b else headA

        return node_a


if __name__ == '__main__':
    # 建立一个链表
    val_a = [4, 1, 8, 4, 5]
    val_b = [5, 0, 1, 8, 4, 5]
    linked_list_a = ListNode.build_linked_list(val_a)
    linked_list_b = ListNode.build_linked_list(val_b)
    ListNode.print_linked_list(linked_list_a)
    ListNode.print_linked_list(linked_list_b)

    solution = Solution()
    inserction_node = solution.getIntersectionNode(linked_list_a, linked_list_b)
    print(inserction_node)
