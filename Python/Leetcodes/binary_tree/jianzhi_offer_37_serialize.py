#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
@Time    : 2021/2/6 11:38 下午
@Author  : luocai
@file    : jianzhi_offer_37_serialize.py
@concat  : 429546420@qq.com
@site    : 
@software: PyCharm Community Edition 
@desc    :

剑指 Offer 37. 序列化二叉树

https://leetcode-cn.com/problems/xu-lie-hua-er-cha-shu-lcof/
"""


# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Codec:

    def serialize(self, root):
        """Encodes a tree to a single string.

        :type root: TreeNode
        :rtype: str
        """
        if not root:
            return "[]"
        res = []
        deque = [root]
        while deque:
            curr = deque.pop(0)
            if curr:
                res.append(str(curr.val))
                deque.append(curr.left)
                deque.append(curr.right)
            else:
                res.append("null")
        # 去掉多余的 null
        while res[-1] == 'null':
            res.pop()
        return "[" + ','.join(res) + "]"

    def deserialize(self, data):
        """Decodes your encoded data to tree.

        :type data: str
        :rtype: TreeNode
        """
        if data == "[]":
            return
        data_list, i = data[1:-1].split(","), 1
        root_val = int(data_list[0])
        root = TreeNode(root_val)
        deque = [root]
        while deque:
            node = deque.pop(0)
            if i < len(data_list) and data_list[i] != "null":
                node.left = TreeNode(int(data_list[i]))
                deque.append(node.left)
            i += 1
            if i < len(data_list) and data_list[i] != "null":
                node.right = TreeNode(int(data_list[i]))
                deque.append(node.right)
            i += 1

        return root


if __name__ == '__main__':
    tmp = "[1,2,3,null,null,4,5]"
    print(tmp[1:-1].split(","))
    codec = Codec()
    tree = codec.deserialize(tmp)
    tt = codec.serialize(tree)
    print(tt)
