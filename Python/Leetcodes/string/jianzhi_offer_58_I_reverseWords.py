#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
@Time    : 2020/12/24 7:43 上午
@Author  : luocai
@file    : jianzhi_offer_58_I_reverseWords.py
@concat  : 429546420@qq.com
@site    : 
@software: PyCharm Community Edition 
@desc    :

https://leetcode-cn.com/problems/fan-zhuan-dan-ci-shun-xu-lcof/
剑指 offer58 题 翻转单词顺序
"""


class Solution:
    def reverseWords(self, s: str) -> str:
        res = [ss.strip() for ss in s.strip().split(" ") if ss != '']
        return " ".join(res[::-1])

    def reverseWords2(self, s: str) -> str:
        # 双指针法
        s = s.strip()
        i = j = len(s) - 1
        res = []
        while i >= 0:
            # 搜索首个字母
            while i >= 0 and s[i] != ' ':
                i -= 1
            res.append(s[i + 1:j + 1])
            # 跳过单词空格
            while s[i] == ' ':
                i -= 1
            # j 指向下个单词的尾字母
            j = i
        return ' '.join(res)


if __name__ == '__main__':
    s = "a good   example"
    solution = Solution()
    print("result:", solution.reverseWords2(s))
