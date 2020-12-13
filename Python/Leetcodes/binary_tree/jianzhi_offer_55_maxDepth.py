#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
@Time    : 2020/12/13 5:12 下午
@Author  : luocai
@file    : jianzhi_offer_55_maxDepth.py
@concat  : 429546420@qq.com
@site    : 
@software: PyCharm Community Edition 
@desc    :

https://leetcode-cn.com/problems/er-cha-shu-de-shen-du-lcof/
剑指 offer55 题二叉树的深度
"""
import collections


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def maxDepth(self, root: TreeNode) -> int:
        # 递归实现
        if not root:
            return 0
        return max(self.maxDepth(root.left), self.maxDepth(root.right)) + 1

    def maxDepth2(self, root: TreeNode) -> int:
        # 辅助栈
        if not root:
            return 0
        stack = [(root, 1)]
        res = 0
        while stack:
            cur, depth = stack.pop()
            res = max(res, depth)
            if cur.right:
                stack.append((cur.right, depth + 1))
            if cur.left:
                stack.append((cur.left, depth + 1))
        return res

    def maxDepth3(self, root: TreeNode) -> int:
        # 层次遍历
        if not root:
            return 0
        deque = [root]
        res = 0
        while deque:
            tmp = []
            for r in deque:
                if r.left:
                    tmp.append(r.left)
                if r.right:
                    tmp.append(r.right)
            deque = tmp
            res += 1

        return res
