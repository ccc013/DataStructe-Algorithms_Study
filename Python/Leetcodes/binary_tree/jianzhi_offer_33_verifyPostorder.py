#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
@Time    : 2021/1/17 6:00 下午
@Author  : luocai
@file    : jianzhi_offer_33_verifyPostorder.py
@concat  : 429546420@qq.com
@site    : 
@software: PyCharm Community Edition 
@desc    :

https://leetcode-cn.com/problems/er-cha-sou-suo-shu-de-hou-xu-bian-li-xu-lie-lcof/
剑指 offer33 题 二叉搜索树的后序遍历序列
"""
from typing import List


class Solution:
    def verifyPostorder(self, postorder: List[int]) -> bool:
        # 递归分治
        def recur(i, j):
            if i >= j:
                return True
            p = i
            # 划分左右子树，寻找第一个大于根节点的节点
            while postorder[p] < postorder[j]:
                p += 1
            m = p
            while postorder[p] > postorder[j]:
                p += 1
            return (p == j) and recur(i, m - 1) and recur(m, j - 1)

        return recur(0, len(postorder) - 1)
