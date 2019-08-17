#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
@Time    : 2019/8/17 11:14
@Author  : luocai
@file    : 21_Merge_Two_Sorted_Lists.py
@concat  : 429546420@qq.com
@site    : 
@software: PyCharm Community Edition 
@desc    :

题目：合并两个有序链表
https://leetcode.com/problems/merge-two-sorted-lists/

"""


class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution(object):
    def mergeTwoLists(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        if l1 is None:
            return l2
        if l2 is None:
            return l1
        # 确定第一个结点
        if l1.val <= l2.val:
            new_head = cur = l1
            l1 = l1.next
        else:
            new_head = cur = l2
            l2 = l2.next
        while l1 or l2:
            # 任意一个链表为空，都可以不需要再循环
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
    val_a = [1, 2, 4]
    val_b = [1, 3, 4]
    linked_list_a = build_linked_list(val_a)
    linked_list_b = build_linked_list(val_b)
    print_linked_list(linked_list_a)
    print_linked_list(linked_list_b)

    solution = Solution()
    new_linked_list = solution.mergeTwoLists(linked_list_a, linked_list_b)
    print_linked_list(new_linked_list)

