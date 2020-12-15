#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
@Time    : 2020/12/15 11:20 下午
@Author  : luocai
@file    : jianzhi_offer_55_isBalanced.py
@concat  : 429546420@qq.com
@site    : 
@software: PyCharm Community Edition 
@desc    :

https://leetcode-cn.com/problems/ping-heng-er-cha-shu-lcof/
剑指 offer55 题平衡二叉树
"""


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def isBalanced(self, root: TreeNode) -> bool:
        # 后序遍历
        def recur(root):
            if not root:
                return 0
            left = recur(root.left)
            if left == -1:
                return -1
            right = recur(root.right)
            if right == -1:
                return -1
            return max(left, right) + 1 if abs(left - right) <= 1 else -1

        return recur(root) != -1

    def isBalanced2(self, root: TreeNode) -> bool:
        # 先序遍历
        def depth(root):
            if not root:
                return 0
            return max(depth(root.left), depth(root.right)) + 1

        if not root:
            return True
        return abs(depth(root.left) - depth(root.right)) <= 1 and self.isBalanced2(root.left) and self.isBalanced2(
            root.right)
