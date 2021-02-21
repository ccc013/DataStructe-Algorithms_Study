#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
@Time    : 2021/2/21 2:19 下午
@Author  : luocai
@file    : 617_mergeTrees.py
@concat  : 429546420@qq.com
@site    : 
@software: PyCharm Community Edition 
@desc    :

617. 合并二叉树
https://leetcode-cn.com/problems/merge-two-binary-trees/
"""
import collections


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def mergeTrees(self, root1: TreeNode, root2: TreeNode) -> TreeNode:
        # 深度优先遍历
        if not root1:
            return root2
        if not root2:
            return root1
        merge_t = TreeNode(root1.val + root2.val)
        merge_t.left = self.mergeTrees(root1.left, root2.left)
        merge_t.right = self.mergeTrees(root1.right, root2.right)

        return merge_t

    def mergeTrees2(self, root1: TreeNode, root2: TreeNode) -> TreeNode:
        # 广度优先遍历
        if not root1:
            return root2
        if not root2:
            return root1

        merge_t = TreeNode(root1.val + root2.val)
        q = collections.deque([merge_t])
        q1 = collections.deque([root1])
        q2 = collections.deque([root2])

        while q1 and q2:
            node, node1, node2 = q.popleft(), q1.popleft(), q2.popleft()
            left1, left2 = node1.left, node2.left
            right1, right2 = node1.right, node2.right
            if left1 or left2:
                if left1 and left2:
                    node.left = TreeNode(left1.val + left2.val)
                    q.append(node.left)
                    q1.append(left1)
                    q2.append(left2)
                elif left1:
                    node.left = left1
                else:
                    node.left = left2
            if right1 or right2:
                if right1 and right2:
                    node.right = TreeNode(right1.val + right2.val)
                    q.append(node.right)
                    q1.append(right1)
                    q2.append(right2)
                elif right1:
                    node.right = right1
                else:
                    node.right = right2

        return merge_t
