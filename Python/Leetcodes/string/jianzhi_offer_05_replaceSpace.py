#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
@Time    : 2020/12/4 11:05 下午
@Author  : luocai
@file    : jianzhi_offer_05_replaceSpace.py
@concat  : 429546420@qq.com
@site    : 
@software: PyCharm Community Edition 
@desc    :

https://leetcode-cn.com/problems/ti-huan-kong-ge-lcof/
剑指 offer05 题--替换空格
"""


class Solution:
    def replaceSpace(self, s: str) -> str:
        # 用一个新的字符串保存结果
        res = ""
        for i in s:
            if i == " ":
                res += "%20"
            else:
                res += i

        return res

    def replaceSpace2(self, s: str) -> str:
        return s.replace(" ", "%20")


if __name__ == '__main__':
    input_str = "We are happy."
    print("origin string: " + input_str)
    solution = Solution()
    print("replace space: " + solution.replaceSpace2(input_str))
