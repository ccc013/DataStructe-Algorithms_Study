#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
@Time    : 2020/12/14 7:45 上午
@Author  : luocai
@file    : jianzhi_offer_68_2_lowestCommonAncestor.py
@concat  : 429546420@qq.com
@site    : 
@software: PyCharm Community Edition 
@desc    :

https://leetcode-cn.com/problems/er-cha-shu-de-zui-jin-gong-gong-zu-xian-lcof/
剑指 offer68 题 II，二叉树的最近公共祖先
"""


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def lowestCommonAncestor(self, root: TreeNode, p: TreeNode, q: TreeNode) -> TreeNode:
        if not root or p == root or q == root:
            return root
        left = self.lowestCommonAncestor(root.left, p, q)
        right = self.lowestCommonAncestor(root.right, p, q)
        if not right:
            return left
        if not left:
            return right
        return root
