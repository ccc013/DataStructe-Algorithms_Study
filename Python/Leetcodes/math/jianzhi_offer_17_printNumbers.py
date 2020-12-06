#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
@Time    : 2020/12/6 1:20 下午
@Author  : luocai
@file    : jianzhi_offer_17_printNumbers.py
@concat  : 429546420@qq.com
@site    : 
@software: PyCharm Community Edition 
@desc    :

https://leetcode-cn.com/problems/da-yin-cong-1dao-zui-da-de-nwei-shu-lcof/
剑指 offer17 题--打印从 1 到最大的 n 位数
"""
from typing import List


class Solution:
    def printNumbers(self, n: int) -> List[int]:
        # 最大的 n 位数
        max_n = pow(10, n)
        return [i for i in range(1, max_n)]

    # 更简洁的写法
    def printNumbers2(self, n: int) -> List[int]:
        return list(range(1, 10 ** n))

    # 大数解法
    # 参考 https://leetcode-cn.com/problems/da-yin-cong-1dao-zui-da-de-nwei-shu-lcof/solution/mian-shi-ti-17-da-yin-cong-1-dao-zui-da-de-n-wei-2/
    def printNumbers3(self, n: int) -> [int]:
        def dfs(x):
            if x == n:
                s = ''.join(num[self.start:])
                if s != '0': res.append(int(s))
                if n - self.start == self.nine: self.start -= 1
                return
            for i in range(10):
                if i == 9: self.nine += 1
                num[x] = str(i)
                dfs(x + 1)
            self.nine -= 1

        num, res = ['0'] * n, []
        self.nine = 0
        self.start = n - 1
        dfs(0)
        return res


if __name__ == '__main__':
    n = 1
    solution = Solution()
    print(solution.printNumbers3(n))
