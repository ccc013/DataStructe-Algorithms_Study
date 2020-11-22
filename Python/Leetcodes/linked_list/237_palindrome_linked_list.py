#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
@Time    : 2020/11/22 3:22 下午
@Author  : luocai
@file    : 237_palindrome_linked_list.py
@concat  : 429546420@qq.com
@site    : 
@software: PyCharm Community Edition 
@desc    :


https://leetcode-cn.com/problems/palindrome-linked-list/
237 题，判断回文链表
"""
from Linked_list.Linked_list import ListNode


class Solution:
    def isPalindrome(self, head: ListNode) -> bool:
        # O(n)时间复杂度和 O(n)空间复杂度
        cur = head
        link_list = []
        # 列表保存当前结点
        while cur:
            link_list.append(cur)
            cur = cur.next
        # 对比前一半的结点即可
        nums = len(link_list)
        i = nums - 1
        cur = head
        while cur:
            if cur.val != link_list[i].val:
                return False
            i -= 1
            if i < (nums - 1) / 2:
                break
            cur = cur.next
        return True

    def isPalindrome2(self, head: ListNode) -> bool:
        # O(n)时间复杂度和 O(1)空间复杂度
        fast = slow = head
        prev = None
        # 寻找链表中点
        while fast:
            slow = slow.next
            if fast.next:
                fast = fast.next.next
            else:
                fast = fast.next
        # 反转后半段链表
        while slow:
            prev, slow.next, slow = slow, prev, slow.next
        # 对比，判断是否回文
        while head and prev:
            if head.val != prev.val:
                return False
            head, prev = head.next, prev.next
        return True


if __name__ == '__main__':
    # 建立一个链表
    val_a = [1, 3, 3, 1]
    linked_list_a = ListNode.build_linked_list(val_a)
    ListNode.print_linked_list(linked_list_a)
    n = 2
    solution = Solution()
    print(solution.isPalindrome2(linked_list_a))
