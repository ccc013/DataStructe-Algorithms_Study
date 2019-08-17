#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
@Time    : 2019/8/17 14:29
@Author  : luocai
@file    : 876_Middle_of_the_Linked_List.py
@concat  : 429546420@qq.com
@site    : 
@software: PyCharm Community Edition 
@desc    :

返回链表的中间结点
https://leetcode.com/problems/middle-of-the-linked-list
"""


class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution(object):
    def middleNode(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        slow = head
        fast = head
        while fast and fast.next:
            fast = fast.next.next
            slow = slow.next
        return slow


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
    val_a = [1, 2, 3, 4, 5, 6]
    linked_list_a = build_linked_list(val_a)
    print_linked_list(linked_list_a)

    solution = Solution()
    middle = solution.middleNode(linked_list_a)
    print(middle.val)
