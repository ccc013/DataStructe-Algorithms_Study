#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
@Time    : 2020/11/22 3:08 下午
@Author  : luocai
@file    : interview_0203_delete_middle_node.py
@concat  : 429546420@qq.com
@site    : 
@software: PyCharm Community Edition 
@desc    :

https://leetcode-cn.com/problems/delete-middle-node-lcci/

面试题 0203 实现一种算法，删除单向链表中间的某个节点（即不是第一个或最后一个节点），假定你只能访问该节点。
"""
from Linked_list.Linked_list import ListNode


class Solution:
    def deleteNode(self, node):
        """
        :type node: ListNode
        :rtype: void Do not return anything, modify node in-place instead.
        """
        node.val = node.next.val
        node.next = node.next.next


if __name__ == '__main__':
    # 建立一个链表
    val_a = [1, 2, 3, 4, 5]
    linked_list_a = ListNode.build_linked_list(val_a)
    ListNode.print_linked_list(linked_list_a)
    n = 2
    solution = Solution()
    solution.deleteNode(linked_list_a.next)
    ListNode.print_linked_list(linked_list_a)
