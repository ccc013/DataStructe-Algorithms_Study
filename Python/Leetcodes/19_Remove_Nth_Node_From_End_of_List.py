#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
@Time    : 2019/8/17 12:17
@Author  : luocai
@file    : 19_Remove_Nth_Node_From_End_of_List.py
@concat  : 429546420@qq.com
@site    : 
@software: PyCharm Community Edition 
@desc    :

删除链表倒数第 n 个结点
https://leetcode.com/problems/remove-nth-node-from-end-of-list

"""


class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution(object):
    def removeNthFromEnd(self, head, n):
        """
        :type head: ListNode
        :type n: int
        :rtype: ListNode
        """
        # 采用辅助list 保存遍历过的结点
        linked_list = list()
        cur = head
        while cur:
            linked_list.append(cur.val)
            cur = cur.next
        # 正向的顺序
        num = len(linked_list) - n + 1
        new_head = cur = None
        for index, val in enumerate(linked_list):
            if (index + 1) == num:
                # 指定删除的结点
                continue
            node = ListNode(val)
            if new_head is None:
                new_head = node
                cur = node
            else:
                cur.next = node
                cur = node
        return new_head

    def removeNthFromEnd2(self, head, n):
        # 双重遍历
        # 虚拟结点
        dummy = ListNode(0)
        dummy.next = head
        cur = head
        length = 0
        # 统计链表长度
        while cur:
            length += 1
            cur = cur.next
        # 再次遍历
        length -= n
        cur = dummy
        while length:
            length -= 1
            cur = cur.next
        cur.next = cur.next.next
        return dummy.next

    def removeNthFromEnd3(self, head, n):
        # 一遍遍历的方法，采用两个指针
        dummy = ListNode(0)
        dummy.next = head
        p = dummy
        q = dummy
        # 先移动第一个指针，保证和第二个指针之间相差 n 个结点
        for i in range(n + 1):
            p = p.next
        # 同时移动两个指针
        while p:
            p = p.next
            q = q.next
        q.next = q.next.next
        return dummy.next


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
    linked_list_a = build_linked_list(val_a)
    print_linked_list(linked_list_a)
    n = 1
    solution = Solution()
    new_linked_list = solution.removeNthFromEnd3(linked_list_a, n)
    print_linked_list(new_linked_list)
