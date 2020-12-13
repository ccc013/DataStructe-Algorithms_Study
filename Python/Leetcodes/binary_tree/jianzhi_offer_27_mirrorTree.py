#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
@Time    : 2020/12/13 3:54 下午
@Author  : luocai
@file    : jianzhi_offer_27_mirrorTree.py
@concat  : 429546420@qq.com
@site    : 
@software: PyCharm Community Edition 
@desc    :

https://leetcode-cn.com/problems/er-cha-shu-de-jing-xiang-lcof/
剑指 offer27 题二叉树的镜像
"""


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def mirrorTree(self, root: TreeNode) -> TreeNode:
        # 递归法
        if not root:
            return None
        # 交换位置
        root.left, root.right = root.right, root.left
        self.mirrorTree(root.left)
        self.mirrorTree(root.right)
        return root

    def mirrorTree(self, root: TreeNode) -> TreeNode:
        # 栈
        if not root:
            return None
        stack = []
        stack.append(root)
        while stack:
            tmp = stack.pop()
            if not tmp:
                continue
            tmp.left, tmp.right = tmp.right, tmp.left
            if tmp.right:
                stack.append(tmp.right)
            if tmp.left:
                stack.append(tmp.left)
        return root



if __name__ == '__main__':
    pass
