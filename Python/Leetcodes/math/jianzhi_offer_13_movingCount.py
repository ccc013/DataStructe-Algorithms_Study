#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
@Time    : 2021/1/23 9:44 下午
@Author  : luocai
@file    : jianzhi_offer_13_movingCount.py
@concat  : 429546420@qq.com
@site    : 
@software: PyCharm Community Edition 
@desc    :

https://leetcode-cn.com/problems/ji-qi-ren-de-yun-dong-fan-wei-lcof/
剑指 offer 13 题--机器人的运动范围
"""


class Solution:
    def movingCount(self, m: int, n: int, k: int) -> int:
        # 深度优先遍历
        def dfs(i, j, si, sj):
            if i >= m or j >= n or (k < si + sj) or (i, j) in visited:
                return 0
            visited.add((i, j))
            return 1 + dfs(i + 1, j, si + 1 if (i + 1) % 10 else si - 8, sj) + dfs(i, j + 1, si,
                                                                                   sj + 1 if (j + 1) % 10 else sj - 8)

        visited = set()
        return dfs(0, 0, 0, 0)

    def movingCount2(self, m: int, n: int, k: int) -> int:
        # 广度优先遍历
        queue, visited = [(0, 0, 0, 0)], set()
        while queue:
            i, j, si, sj = queue.pop(0)
            if i >= m or j >= n or (k < si + sj) or (i, j) in visited:
                continue
            visited.add((i, j))
            queue.append((i + 1, j, si + 1 if (i + 1) % 10 else si - 8, sj))
            queue.append((i, j + 1, si, sj + 1 if (j + 1) % 10 else sj - 8))

        return len(visited)
