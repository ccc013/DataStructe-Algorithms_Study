#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
@Time    : 2019/8/12 22:35
@Author  : luocai
@file    : 141_Linked_List_Cycle.py
@concat  : 429546420@qq.com
@site    : 
@software: PyCharm Community Edition 
@desc    :

https://leetcode.com/problems/linked-list-cycle/
检查链表是否存在环
"""


class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution(object):
    def hasCycle(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        # 快慢指针
        slow, fast = head, head
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
            if slow == fast:
                return True

        return False

    def hasCycle2(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        # 哈希列表
        node_list = list()
        cur = head
        while cur:
            if cur in node_list:
                return True
            node_list.append(cur)
            cur = cur.next

        return False


if __name__ == '__main__':
    # 建立一个链表
    val = [3, 2, 0, -1]
    old_node = None
    head = None
    pos = -1
    circle_node = None
    for i, _val in enumerate(val):
        node = ListNode(_val)
        if i > 0:
            old_node.next = node
            old_node = node
        else:
            head = node
            old_node = node
        if i == pos:
            circle_node = node
        if i == len(val) - 1:
            old_node.next = circle_node

    solution = Solution()
    print(solution.hasCycle(head))
    print(solution.hasCycle2(head))
