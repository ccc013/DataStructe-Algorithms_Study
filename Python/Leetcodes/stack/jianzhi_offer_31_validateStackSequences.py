#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
@Time    : 2020/12/6 9:18 上午
@Author  : luocai
@file    : jianzhi_offer_31_validateStackSequences.py
@concat  : 429546420@qq.com
@site    : 
@software: PyCharm Community Edition 
@desc    :

https://leetcode-cn.com/problems/zhan-de-ya-ru-dan-chu-xu-lie-lcof/
剑指 offer31 题--栈的压入、弹出序列
"""
from typing import List


class Solution:
    def validateStackSequences(self, pushed: List[int], popped: List[int]) -> bool:
        if not pushed or not popped:
            return True
        pop_n = len(popped)
        # 保存当前入栈元素最大的索引位置
        max_index = pushed.index(popped[0])
        # 遍历弹出序列
        for i in range(1, pop_n):
            index = pushed.index(popped[i])
            if index > max_index:
                # 当前弹出元素是目前最大的入栈顺序
                max_index = index
                continue
            else:
                # 当前弹出元素必须比前一个元素先压入栈中，而且不是出栈第一个位置
                if pushed.index(popped[i]) > pushed.index(popped[i - 1]):
                    return False

        return True

    def validateStackSequences2(self, pushed: List[int], popped: List[int]) -> bool:
        if not pushed or not popped:
            return True
        # 辅助栈
        stack = []
        # 弹出栈的索引
        p = 0
        for i in pushed:
            stack.append(i)
            # 循环判断弹出序列当前元素是否等于辅助栈的栈顶元素
            while stack and stack[-1] == popped[p]:
                p += 1
                stack.pop()

        return not stack


if __name__ == '__main__':
    pushed = [1, 2, 3, 4, 5]
    popped = [4, 5, 3, 1, 2]
    solution = Solution()
    print("result: ", solution.validateStackSequences2(pushed, popped))
