#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
@Time    : 2021/1/2 10:11 下午
@Author  : luocai
@file    : jianzhi_offer_36_treeToDoublyList.py
@concat  : 429546420@qq.com
@site    : 
@software: PyCharm Community Edition 
@desc    :

https://leetcode-cn.com/problems/er-cha-sou-suo-shu-yu-shuang-xiang-lian-biao-lcof/
剑指 offer36 题--二叉搜索树与双向链表
"""


# Definition for a Node.
class Node:
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def treeToDoublyList(self, root: 'Node') -> 'Node':
        def dfs(cur):
            if not cur:
                return
            dfs(cur.left)
            if self.pre:
                # 修改
                self.pre.right, cur.left = cur, self.pre
            else:
                # 头节点
                self.head = cur
            self.pre = cur
            dfs(cur.right)

        if not root:
            return None
        self.pre = None
        dfs(root)
        self.head.left, self.pre.right = self.pre, self.head
        return self.head
