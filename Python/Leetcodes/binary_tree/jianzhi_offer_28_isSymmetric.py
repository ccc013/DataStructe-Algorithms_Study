#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
@Time    : 2020/12/15 7:07 上午
@Author  : luocai
@file    : jianzhi_offer_28_isSymmetric.py
@concat  : 429546420@qq.com
@site    : 
@software: PyCharm Community Edition 
@desc    :

https://leetcode-cn.com/problems/dui-cheng-de-er-cha-shu-lcof/
剑指 offer28 题 对称的二叉树
"""
import collections


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def isSymmetric(self, root: TreeNode) -> bool:
        def recur(L, R):
            # 都是空，是对称的
            if not L and not R:
                return True
            # 任意一个为空或者值不相等，都是不对称的
            if not L or not R or L.val != R.val:
                return False
            return recur(L.left, R.right) and recur(L.right, R.left)

        if not root:
            return True
        return recur(root.left, root.right)

    def isSymmetric2(self, root: TreeNode) -> bool:
        if not root:
            return True

        queue = collections.deque()
        # 加入根节点的左右子节点
        queue.append(root.left)
        queue.append(root.right)
        while queue:
            left_node = queue.popleft()
            right_node = queue.popleft()
            if not left_node and not right_node:
                continue

            if not left_node or not right_node or (left_node.val != right_node.val):
                return False

            queue.append(left_node.left)
            queue.append(right_node.right)
            queue.append(left_node.right)
            queue.append(right_node.left)

        return True


if __name__ == '__main__':
    root = TreeNode(1)
    root_left = TreeNode(2)
    root_right = TreeNode(2)
    root.left = root_left
    root.right = root_right

    root_left.left = TreeNode(3)
    root_left.right = TreeNode(4)

    root_right.left = TreeNode(4)
    root_right.right = TreeNode(3)
    solution = Solution()
    print(solution.isSymmetric2(root))
