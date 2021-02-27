#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
@Time    : 2021/2/27 12:42 下午
@Author  : luocai
@file    : 104_maxDepth.py
@concat  : 429546420@qq.com
@site    : 
@software: PyCharm Community Edition 
@desc    :

104. 二叉树的最大深度
https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/
"""
import collections


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def maxDepth(self, root: TreeNode) -> int:
        # 深度优先遍历
        if not root:
            return 0
        else:
            left = self.maxDepth(root.left)
            right = self.maxDepth(root.right)
            return max(left, right) + 1

    def maxDepth2(self, root: TreeNode) -> int:
        # 广度优先遍历
        if not root:
            return 0

        d = collections.deque([root])
        count = 0
        while d:
            length = len(d)
            while length > 0:
                node = d.popleft()
                if node.left:
                    d.append(node.left)
                if node.right:
                    d.append(node.right)
                length -= 1

            count += 1
        return count
