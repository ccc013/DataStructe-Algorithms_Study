#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
@Time    : 2021/1/24 11:44 上午
@Author  : luocai
@file    : jianzhi_offer_26_isSubStructure.py
@concat  : 429546420@qq.com
@site    : 
@software: PyCharm Community Edition 
@desc    :

https://leetcode-cn.com/problems/shu-de-zi-jie-gou-lcof/
剑指 Offer 26. 树的子结构
"""


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def isSubStructure(self, A: TreeNode, B: TreeNode) -> bool:
        def recur(A, B):
            if not B:
                return True
            if not A or A.val != B.val:
                return False
            return recur(A.left, B.left) and recur(A.right, B.right)

        return bool(A and B) and (recur(A, B) or self.isSubStructure(A.left, B) or self.isSubStructure(A.right, B))
