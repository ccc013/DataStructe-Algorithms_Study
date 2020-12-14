#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
@Time    : 2020/12/14 7:18 上午
@Author  : luocai
@file    : jianzhi_offer_68_lowestCommonAncestor.py
@concat  : 429546420@qq.com
@site    : 
@software: PyCharm Community Edition 
@desc    :

https://leetcode-cn.com/problems/er-cha-sou-suo-shu-de-zui-jin-gong-gong-zu-xian-lcof/
剑指 offer68 题--二叉搜索树的最近公共祖先
"""


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        while root:
            if p.val < root.val and q.val < root.val:
                # 都在 root 的左子树
                root = root.left
            elif p.val > root.val and q.val > root.val:
                # 都在 root 的右子树
                root = root.right
            else:
                break
        return root

    def lowestCommonAncestor2(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        # 优化迭代, 确保 p.val > q.val
        if p.val < q.val:
            p, q = q, p
        while root:
            if root.val > p.val:
                # 都在 root 的左子树
                root = root.left
            elif root.val < q.val:
                # 都在 root 的右子树
                root = root.right
            else:
                break
        return root

    def lowestCommonAncestor3(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        # 递归
        if p.val < root.val and q.val < root.val:
            return self.lowestCommonAncestor3(root.left, p, q)
        if p.val > root.val and q.val > root.val:
            return self.lowestCommonAncestor3(root.right, p, q)
        return root
