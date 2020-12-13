#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
@Time    : 2020/12/13 12:52 下午
@Author  : luocai
@file    : binary_tree.py
@concat  : 429546420@qq.com
@site    : 
@software: PyCharm Community Edition 
@desc    :


"""


class TreeNode:

    def __init__(self, value):
        self.val = value
        self.left_node = None
        self.right_node = None

    # 前序遍历
    @staticmethod
    def pre_order(root):
        if not root:
            return None
        print(root.val)
        TreeNode.pre_order(root.left_node)
        TreeNode.pre_order(root.right_node)

    # 中序遍历
    @staticmethod
    def in_order(root):
        if not root:
            return None
        TreeNode.in_order(root.left_node)
        print(root.val)
        TreeNode.in_order(root.right_node)

    # 后序遍历
    @staticmethod
    def post_order(root):
        if not root:
            return None
        TreeNode.post_order(root.left_node)
        TreeNode.post_order(root.right_node)
        print(root.val)


if __name__ == '__main__':
    # 先构建一个二叉树
    root = TreeNode(1)
    tree_node2 = TreeNode(2)
    tree_node3 = TreeNode(3)
    root.left_node = tree_node2
    root.right_node = tree_node3
    tree_node4 = TreeNode(4)
    tree_node5 = TreeNode(5)
    tree_node2.left_node = tree_node4
    tree_node3.right_node = tree_node5

    # 前序遍历
    # TreeNode.pre_order(root)
    # 中序遍历
    # TreeNode.in_order(root)
    # 后序遍历
    TreeNode.post_order(root)

