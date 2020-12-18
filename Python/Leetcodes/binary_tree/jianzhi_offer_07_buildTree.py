#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
@Time    : 2020/12/18 7:25 上午
@Author  : luocai
@file    : jianzhi_offer_07_buildTree.py
@concat  : 429546420@qq.com
@site    : 
@software: PyCharm Community Edition 
@desc    :

https://leetcode-cn.com/problems/zhong-jian-er-cha-shu-lcof/
剑指 offer07 题--重建二叉树
"""
from typing import List


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
        def recur(root, left, right):
            if left > right: return  # 递归终止
            node = TreeNode(preorder[root])  # 建立根节点
            i = dic[preorder[root]]  # 划分根节点、左子树、右子树
            node.left = recur(root + 1, left, i - 1)  # 开启左子树递归
            node.right = recur(i - left + root + 1, i + 1, right)  # 开启右子树递归
            return node  # 回溯返回根节点

        dic, preorder = {}, preorder
        for i in range(len(inorder)):
            dic[inorder[i]] = i
        return recur(0, 0, len(inorder) - 1)

    def buildTree2(self, preorder, inorder):
        # 递归 2
        if not preorder or not inorder:
            return None
        if len(preorder) != len(inorder):
            return None

        root = preorder[0]  # 第一个为根节点
        rootNode = TreeNode(root)  # 创建树
        pos = inorder.index(root)  # 在中序中找到对应索引值

        inorder_left = inorder[:pos]
        inorder_right = inorder[pos + 1:]

        preorder_left = preorder[1:1 + pos]
        preorder_right = preorder[pos + 1:]

        node_left = self.buildTree(preorder_left, inorder_left)
        node_right = self.buildTree(preorder_right, inorder_right)

        rootNode.left = node_left  # 添加左子树
        rootNode.right = node_right  # 添加右子树

        return rootNode

    def buildTree3(self, preorder, inorder):
        # 迭代
        if not preorder:
            return
        stack = []
        root = TreeNode(preorder[0])
        stack.append(root)
        cur = root
        # 中序遍历的索引
        j = 0
        for i in range(1, len(preorder)):
            if cur.val != inorder[j]:
                # 当前该中序遍历的节点是栈顶元素的左子树节点
                cur.left = TreeNode(preorder[i])
                stack.append(cur)
                cur = cur.left
            else:
                j += 1
                # 找到合适的 cur，确定其右子节点
                while stack and (stack[-1].val == inorder[j]):
                    cur = stack.pop()
                    j += 1
                cur.right = TreeNode(preorder[i])
                cur = cur.right

        return root
