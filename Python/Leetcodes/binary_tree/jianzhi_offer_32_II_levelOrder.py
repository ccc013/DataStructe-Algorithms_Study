#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
@Time    : 2020/12/16 7:53 上午
@Author  : luocai
@file    : jianzhi_offer_32_II_levelOrder.py
@concat  : 429546420@qq.com
@site    : 
@software: PyCharm Community Edition 
@desc    :


https://leetcode-cn.com/problems/cong-shang-dao-xia-da-yin-er-cha-shu-ii-lcof/
剑指 offer32 题 II--从上到下打印二叉树
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
        deque, res = collections.deque(), []
        deque.append(root)
        # 记录当前层的节点数量
        count = len(deque)
        # 保存当前层的结果
        tmp = []
        while deque:
            node = deque.popleft()
            count -= 1
            tmp.append(node.val)
            if node.left:
                deque.append(node.left)
            if node.right:
                deque.append(node.right)

            if count == 0:
                # 遍历完一层的结果
                res.append(tmp)
                tmp = []
                count = len(deque)
        return res

    def levelOrder2(self, root: TreeNode) -> List[int]:
        # 层次遍历
        if not root:
            return []
        deque, res = collections.deque(), []
        deque.append(root)
        while deque:
            tmp = []
            for _ in range(len(deque)):
                node = deque.popleft()
                tmp.append(node.val)
                if node.left:
                    deque.append(node.left)
                if node.right:
                    deque.append(node.right)
            res.append(tmp)
        return res
