#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
@Time    : 2020/11/19 7:46 上午
@Author  : luocai
@file    : interview_0202_kth_node_from_end_of_list.py
@concat  : 429546420@qq.com
@site    : 
@software: PyCharm Community Edition 
@desc    :

https://leetcode-cn.com/problems/kth-node-from-end-of-list-lcci/
面试题 02.02 返回倒数第 k 个节点
"""
from Linked_list.Linked_list import ListNode


class Solution:
    def kthToLast(self, head: ListNode, k: int) -> int:
        dummy = ListNode(None)
        dummy.next = head
        fast = slow = dummy
        for i in range(k + 1):
            fast = fast.next
        while fast:
            fast, slow = fast.next, slow.next
        return slow.next.val


if __name__ == '__main__':
    # 建立一个链表
    val_a = [1, 2, 3, 4, 5]
    linked_list_a = ListNode.build_linked_list(val_a)
    ListNode.print_linked_list(linked_list_a)
    n = 2
    solution = Solution()
    n_node_val = solution.kthToLast(linked_list_a, n)
    print(n_node_val)
