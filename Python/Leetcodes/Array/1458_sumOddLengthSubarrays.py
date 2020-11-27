#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
@Time    : 2020/11/26 7:51 上午
@Author  : luocai
@file    : 1458_sumOddLengthSubarrays.py
@concat  : 429546420@qq.com
@site    : 
@software: PyCharm Community Edition 
@desc    :

https://leetcode-cn.com/problems/sum-of-all-odd-length-subarrays/
1458题--所有奇数长度子数组的和
"""


class Solution:
    # 暴力解法，滑动窗口
    def sumOddLengthSubarrays(self, arr) -> int:
        num = len(arr)
        res = 0
        # 确定窗口长度
        for window in range(1, num + 1, 2):
            L = 0
            # 滑动窗口
            for R in range(L + window, num + 1):
                # 计算
                res += sum(arr[L:R])
                L += 1
        return res

    def sumOddLengthSubarrays2(self, arr) -> int:
        num = len(arr)
        res = 0
        # 确定窗口长度
        for window in range(1, num + 1, 2):
            # 滑动窗口
            for i in range(num):
                if i+window <= num:
                    # 计算
                    res += sum(arr[i:i+window])

        return res


if __name__ == '__main__':
    array = [1, 4, 2, 5, 3]
    print("origin array: ", array)
    solution = Solution()
    print("sum: ", solution.sumOddLengthSubarrays(array))
