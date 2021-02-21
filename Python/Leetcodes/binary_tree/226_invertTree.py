#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
@Time    : 2021/2/21 4:11 下午
@Author  : luocai
@file    : 226_invertTree.py
@concat  : 429546420@qq.com
@site    : 
@software: PyCharm Community Edition 
@desc    :

226. 翻转二叉树
https://leetcode-cn.com/problems/invert-binary-tree/
"""
import collections


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def invertTree(self, root: TreeNode) -> TreeNode:
        if not root:
            return None
        root.left, root.right = root.right, root.left
        self.invertTree(root.left)
        self.invertTree(root.right)

        return root

    def invertTree2(self, root: TreeNode) -> TreeNode:
        if not root:
            return None
        q = collections.deque([root])

        while q:
            node = q.popleft()
            node.left, node.right = node.right, node.left
            if node.left:
                q.append(node.left)
            if node.right:
                q.append(node.right)
        return root
