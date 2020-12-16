#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
@Time    : 2020/12/16 7:28 上午
@Author  : luocai
@file    : jianzhi_offer_32_levelOrder.py
@concat  : 429546420@qq.com
@site    : 
@software: PyCharm Community Edition 
@desc    :

https://leetcode-cn.com/problems/cong-shang-dao-xia-da-yin-er-cha-shu-lcof/
剑指 offer32 题 I--从上到下打印二叉树
"""
from typing import List
import collections


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def levelOrder(self, root: TreeNode) -> List[int]:
        # 层次遍历
        if not root:
            return []
        deque = [root]
        res = []
        while deque:
            tmp = []
            for r in deque:
                res.append(r.val)
                if r.left:
                    tmp.append(r.left)
                if r.right:
                    tmp.append(r.right)
            deque = tmp
        return res

    def levelOrder2(self, root: TreeNode) -> List[int]:
        # 层次遍历2
        if not root:
            return []
        deque, res = collections.deque(), []
        deque.append(root)
        while deque:
            node = deque.popleft()
            res.append(node.val)
            if node.left:
                deque.append(node.left)
            if node.right:
                deque.append(node.right)
        return res

