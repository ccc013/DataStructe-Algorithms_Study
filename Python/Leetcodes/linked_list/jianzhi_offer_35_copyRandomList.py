#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
@Time    : 2020/12/26 3:29 下午
@Author  : luocai
@file    : jianzhi_offer_35_copyRandomList.py
@concat  : 429546420@qq.com
@site    : 
@software: PyCharm Community Edition 
@desc    :

https://leetcode-cn.com/problems/fu-za-lian-biao-de-fu-zhi-lcof/
剑指 offer 35 题复杂链表的复制
"""


# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random


class Solution:
    def copyRandomList(self, head: 'Node') -> 'Node':
        # 哈希表
        if head is None:
            return None
        dic = {}
        cur = head
        # 保存每个节点
        while cur:
            dic[cur] = Node(cur.val)
            cur = cur.next
        # 开始复制
        cur = head
        while cur:
            dic[cur].next = dic.get(cur.next)
            dic[cur].random = dic.get(cur.random)
            cur = cur.next
        return dic[head]

    def copyRandomList2(self, head: 'Node') -> 'Node':
        # 拼接+拆分
        if head is None:
            return None
        # 复制节点，构建新链表
        cur = head
        while cur:
            tmp = Node(cur.val)
            tmp.next = cur.next
            cur.next = tmp
            cur = tmp.next

        cur = head
        # 处理 random 指向
        while cur:
            if cur.random:
                cur.next.random = cur.random.next
            cur = cur.next.next

        # 拆分链表
        cur = res = head.next
        pre = head
        while cur.next:
            pre.next = pre.next.next
            cur.next = cur.next.next
            pre = pre.next
            cur = cur.next
        # 单独处理原链表尾结点
        pre.next = None
        return res
