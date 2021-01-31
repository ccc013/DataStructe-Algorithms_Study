#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
@Time    : 2021/1/31 4:28 下午
@Author  : luocai
@file    : jianzhi_offer_67_strToInt.py
@concat  : 429546420@qq.com
@site    : 
@software: PyCharm Community Edition 
@desc    :

剑指 Offer 67. 把字符串转换成整数
https://leetcode-cn.com/problems/ba-zi-fu-chuan-zhuan-huan-cheng-zheng-shu-lcof/
"""


class Solution:
    def strToInt(self, str: str) -> int:
        res, i, sign, length = 0, 0, 1, len(str)
        int_max, int_min, binary = 2 ** 31 - 1, -2 ** 31, 2 ** 31 // 10
        # 非字符串，直接返回 0
        if not str:
            return 0
        # 遍历跳过空字符
        while str[i] == ' ':
            i += 1
            # 都是空字符
            if i == length:
                return 0

        # 判断是否有符号
        if str[i] == '-':
            sign = -1
        if str[i] in '+-':
            i += 1
        for c in str[i:]:
            if not '0' <= c <= '9':
                # 非数字字符，跳出
                break
            if res > binary or (res == binary and c > '7'):
                # 数字越界
                return int_max if sign == 1 else int_min
            res = 10 * res + ord(c) - ord('0')
        return sign * res


if __name__ == '__main__':
    solution = Solution()
    print("result: ", solution.strToInt("  -42"))
    print("result: ", solution.strToInt("4193 with words"))
    print("result: ", solution.strToInt("with words"))
    print("result: ", solution.strToInt("-91283472332"))
