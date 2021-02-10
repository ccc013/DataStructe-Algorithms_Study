#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
@Time    : 2020/12/13 1:27 下午
@Author  : luocai
@file    : binary_search_tree.py
@concat  : 429546420@qq.com
@site    : 
@software: PyCharm Community Edition 
@desc    :

二叉查找树
"""


class TreeNode:

    def __init__(self, value):
        self.val = value
        self.left_node = None
        self.right_node = None


class Binary_search_tree:

    def __init__(self, val_list):
        self.root = None

    def find(self, data):
        # 查找
        ret = []

        r = self.root
        while r:
            if r.val < data:
                r = r.left_node
            else:
                if r.val == data:
                    ret.append(r)
                r = r.right_node
        return ret

    def insert(self, data):
        if not self.root:
            tree = TreeNode(data)
            self.root = tree
            return

        node = self.root
        while node:
            if data > node.val:
                # 从右子树开始查找
                if not node.right_node:
                    node.right_node = TreeNode(data)
                    return
                node = node.right_node
            else:
                if not node.left_node:
                    node.left_node = TreeNode(data)
                node = node.left_node

    def delete(self, data):
        # 指向要删除的节点，初始化为根节点
        p = self.root
        # 记录 p 的父节点
        pp = None
        # 开始遍历查找要删除的节点
        while p and p.val != data:
            pp = p
            if data > p.val:
                p = p.right_node
            else:
                p = p.left_node
        # 不存在被删除的节点
        if not p:
            return
        # 被删除的节点有两个子节点,开始查找右子树中的最小节点
        if not p.left_node and p.right_node:
            min_p = p.right_node
            min_pp = p
            while p.right_node:
                min_pp = min_p
                min_p = min_p.left_node
            # 找到最小子节点，将其数据替换为要被删除的节点 p
            p.val = min_p.val
            p = min_p
            pp = min_pp

        # 被删除的节点只有一个子节点或者不存在子节点
        if p.left_node:
            child = p.left_node
        elif p.right_node:
            child = p.right_node
        else:
            child = None

        if not pp:
            # 删除的是根节点
            self.root = child
        elif pp.left == p:
            pp.left_node = child
        else:
            pp.right_node = child
