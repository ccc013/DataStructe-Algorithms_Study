#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
@Time    : 2021/1/31 5:12 下午
@Author  : luocai
@file    : jianzhi_offer_20_isNumber.py
@concat  : 429546420@qq.com
@site    : 
@software: PyCharm Community Edition 
@desc    :

剑指 Offer 20. 表示数值的字符串
https://leetcode-cn.com/problems/biao-shi-shu-zhi-de-zi-fu-chuan-lcof/
"""


class Solution:
    def isNumber(self, s: str) -> bool:
        # 标记是否遇到 e 或者 E，. 符号，数位
        isE_or_e, isDot, isNum = False, False, False
        if not s or len(s) < 1:
            return False
        # 清除字符串首尾的空字符
        s = s.strip()
        num = len(s)
        for i in range(num):
            if '0' <= s[i] <= '9':
                # 遇到数字
                isNum = True
            elif s[i] == '.':
                # 遇到 . 符号，之前不能出现过 . 符号或者 e,E
                if isDot or isE_or_e:
                    return False
                isDot = True
            elif s[i] == 'e' or s[i] == 'E':
                # 遇到 e/E，前一位必须是数字，不能是 e/E
                if not isNum or isE_or_e:
                    return False
                isE_or_e = True
                # 重置数字，防止出现 '123e' 或者 '123e+' 的非法情况
                isNum = False
            elif s[i] == '+' or s[i] == '-':
                # +-只能是第一位或者前面是 e/E
                if i != 0 and s[i - 1] != 'e' and s[i - 1] != 'E':
                    return False
            else:
                # 其他符号都是非法的
                return False
        # 最后判断最后一位是不是数字
        return isNum


if __name__ == '__main__':
    solution = Solution()
    print("result: ", solution.isNumber("+100"))
    print("result: ", solution.isNumber("1.21"))
    print("result: ", solution.isNumber("5e2"))
    print("result: ", solution.isNumber("5e"))
    print("result: ", solution.isNumber("1.2.3"))
    print("result: ", solution.isNumber("1a2"))
    print("result: ", solution.isNumber("+-5"))
    print("result: ", solution.isNumber("12e+5.4"))
