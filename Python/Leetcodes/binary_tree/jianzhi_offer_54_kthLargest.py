#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
@Time    : 2020/12/13 8:45 下午
@Author  : luocai
@file    : jianzhi_offer_54_kthLargest.py
@concat  : 429546420@qq.com
@site    : 
@software: PyCharm Community Edition 
@desc    :

https://leetcode-cn.com/problems/er-cha-sou-suo-shu-de-di-kda-jie-dian-lcof/
剑指 offer54 题二叉搜索树的第 k 大节点
"""
import collections

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def kthLargest(self, root: TreeNode, k: int) -> int:
        # 递归，中序遍历的倒序
        def dfs(root):
            if not root:
                return
            dfs(root.right)
            # k=0 的情况
            if self.k == 0:
                return
            self.k -= 1
            if self.k == 0:
                self.res = root.val
            dfs(root.left)

        self.k = k
        dfs(root)

        return self.res

    def kthLargest2(self, root: TreeNode, k: int) -> int:
        # 非递归实现
        stack, p, count = [], root, 0
        while p or stack:
            while p:
                stack.append(p)
                p = p.right
            curr = stack.pop()
            count += 1
            if count == k:
                return curr.val
            p = curr.left



if __name__ == '__main__':
    root = TreeNode(3)
    root.left = TreeNode(1)
    root.right = TreeNode(4)
    root_left = root.left
    root_right = root.right
    root_left.left = TreeNode(0)
    root_right.right = TreeNode(5)
    solution = Solution()
    print("result: ", solution.kthLargest(root, 2))
