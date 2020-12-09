#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
@Time    : 2020/12/9 11:19 下午
@Author  : luocai
@file    : jianzhi_offer_50_firstUniqChar.py
@concat  : 429546420@qq.com
@site    : 
@software: PyCharm Community Edition 
@desc    :

https://leetcode-cn.com/problems/di-yi-ge-zhi-chu-xian-yi-ci-de-zi-fu-lcof/
剑指 offer50--第一个只出现一次的字符
"""
import collections


class Solution:
    def firstUniqChar(self, s: str) -> str:
        if not s:
            return " "
        res = {}
        for i in s:
            if i not in res:
                res[i] = 0
            res[i] += 1

        for i in s:
            if res[i] == 1:
                return i
        return " "

    def firstUniqChar2(self, s: str) -> str:
        # 有序哈希表
        res = collections.OrderedDict()
        for i in s:
            res[i] = not i in res
        for key, val in res.items():
            if val:
                return key
        return " "


if __name__ == '__main__':
    s = ""
    solution = Solution()
    print("result: ", solution.firstUniqChar2(s))
