#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
@Time    : 2021/1/25 7:34 上午
@Author  : luocai
@file    : jianzhi_offer_48_lengthOfLongestSubstring.py
@concat  : 429546420@qq.com
@site    : 
@software: PyCharm Community Edition 
@desc    :

https://leetcode-cn.com/problems/zui-chang-bu-han-zhong-fu-zi-fu-de-zi-zi-fu-chuan-lcof/
剑指 Offer 48. 最长不含重复字符的子字符串
"""


class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        # 动态规划+哈希表
        dic = dict()
        res = dp = 0
        num = len(s)
        for j in range(num):
            # 获取索引 i
            i = dic.get(s[j], -1)
            # 更新哈希表
            dic[s[j]] = j
            # dp[j - 1] -> dp[j]
            dp = dp + 1 if dp < j - i else j - i
            # max(dp[j-1], dp[j])
            res = max(res, dp)
        return res

    def lengthOfLongestSubstring2(self, s: str) -> int:
        # 动态规划+线性遍历
        res = dp = 0
        num = len(s)
        for j in range(num):
            i = j - 1
            # 线性遍历上一个和 s[j] 重复的字符位置
            while i >= 0 and s[i] != s[j]:
                i -= 1
            # dp[j - 1] -> dp[j]
            dp = dp + 1 if dp < j - i else j - i
            # max(dp[j-1], dp[j])
            res = max(res, dp)
        return res

    def lengthOfLongestSubstring3(self, s: str) -> int:
        # 双指针+哈希表
        dic, res, i = {}, 0, -1
        num = len(s)
        for j in range(num):
            if s[j] in dic:
                # 更新左指针 i
                i = max(dic[s[j]], i)
            dic[s[j]] = j
            res = max(res, j - i)

        return res
