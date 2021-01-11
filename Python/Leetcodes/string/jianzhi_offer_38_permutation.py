#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
@Time    : 2021/1/11 7:58 上午
@Author  : luocai
@file    : jianzhi_offer_38_permutation.py
@concat  : 429546420@qq.com
@site    : 
@software: PyCharm Community Edition 
@desc    :

https://leetcode-cn.com/problems/zi-fu-chuan-de-pai-lie-lcof/
剑指 offer 38 题--字符串的排列
"""
from typing import List


class Solution:
    def permutation(self, s: str) -> List[str]:
        if not s:
            return []
        res = []

        # 回溯法
        def perm(strs, path):
            if not strs:
                res.append(''.join(path))
                return
            seen = set()
            for i in range(len(strs)):
                if strs[i] in seen:
                    continue
                seen.add(strs[i])
                perm(strs[:i] + strs[i + 1:], path+strs[i])

        perm(s, '')
        return res


if __name__ == '__main__':
    s = 'aab'
    solution = Solution()
    print("result", solution.permutation(s))
