#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
@Time    : 2021/1/9 7:34 下午
@Author  : luocai
@file    : jianzhi_offer_32_III_levelOrder.py
@concat  : 429546420@qq.com
@site    : 
@software: PyCharm Community Edition 
@desc    :

https://leetcode-cn.com/problems/cong-shang-dao-xia-da-yin-er-cha-shu-iii-lcof/
剑指 offer32 题 III 从上到下打印二叉树
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
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        if not root:
            return []
        res = []
        deque = collections.deque()
        deque.append(root)
        level = 1
        while deque:
            nums = len(deque)
            tmp = []
            for _ in range(nums):
                node = deque.popleft()
                if level % 2 != 0:
                    tmp.append(node.val)
                else:
                    tmp.insert(0, node.val)
                if node.left:
                    deque.append(node.left)
                if node.right:
                    deque.append(node.right)
            res.append(tmp)
            level += 1
        return res

    def levelOrder2(self, root: TreeNode) -> List[List[int]]:
        if not root:
            return []
        res = []
        deque = collections.deque()
        deque.append(root)
        while deque:
            tmp = []
            # 打印奇数层
            nums = len(deque)
            for _ in range(nums):
                # 从左向右打印
                node = deque.popleft()
                tmp.append(node.val)
                # 从左到右保存下一层节点
                if node.left:
                    deque.append(node.left)
                if node.right:
                    deque.append(node.right)
            res.append(tmp)
            if not deque:
                break
            tmp = []
            # 打印偶数层
            nums = len(deque)
            for _ in range(nums):
                # 从右向坐打印
                node = deque.pop()
                tmp.append(node.val)
                # 从右到左保存下一层节点
                if node.right:
                    deque.appendleft(node.right)
                if node.left:
                    deque.appendleft(node.left)
            res.append(tmp)

        return res

    def levelOrder3(self, root: TreeNode) -> List[List[int]]:
        if not root: return []
        res, queue = [], collections.deque()
        queue.append(root)
        while queue:
            tmp = []
            for _ in range(len(queue)):
                node = queue.popleft()
                tmp.append(node.val)
                if node.left: queue.append(node.left)
                if node.right: queue.append(node.right)
            res.append(tmp[::-1] if len(res) % 2 else tmp)
        return res
