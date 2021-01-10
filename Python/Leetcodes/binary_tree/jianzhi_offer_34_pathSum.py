#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
@Time    : 2021/1/10 1:42 下午
@Author  : luocai
@file    : jianzhi_offer_34_pathSum.py
@concat  : 429546420@qq.com
@site    : 
@software: PyCharm Community Edition 
@desc    :

https://leetcode-cn.com/problems/er-cha-shu-zhong-he-wei-mou-yi-zhi-de-lu-jing-lcof/
剑指 offer34 题--二叉树中和为某一值的路径
"""
from typing import List


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def pathSum(self, root: TreeNode, sum: int) -> List[List[int]]:
        res, path = [], []

        def recur(root, target):
            if not root:
                return
            # 路径更新
            path.append(root.val)
            # 目标值更新
            target -= root.val
            # 判断是否符合条件
            if target == 0 and not root.left and not root.right:
                res.append(list(path))
            # 先序遍历
            recur(root.left, target)
            recur(root.right, target)
            # 回溯
            path.pop()

        recur(root, sum)
        return res
