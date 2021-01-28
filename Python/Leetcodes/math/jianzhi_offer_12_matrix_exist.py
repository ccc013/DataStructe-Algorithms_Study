#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
@Time    : 2021/1/29 6:56 上午
@Author  : luocai
@file    : jianzhi_offer_12_matrix_exist.py
@concat  : 429546420@qq.com
@site    : 
@software: PyCharm Community Edition 
@desc    :


https://leetcode-cn.com/problems/ju-zhen-zhong-de-lu-jing-lcof/
剑指 Offer 12. 矩阵中的路径
"""
from typing import List


class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        def recur(i, j, w):
            if i < 0 or j < 0 or i >= rows or j >= cols or word[w] != board[i][j]:
                return False
            if w == len(word) - 1:
                return True

            board[i][j] = ''
            res = recur(i + 1, j, w + 1) or recur(i, j + 1, w + 1) or recur(i - 1, j, w + 1) or recur(i, j - 1, w + 1)
            board[i][j] = word[w]
            return res

        visited = set()
        rows, cols = len(board), len(board[0])
        for i in range(rows):
            for j in range(cols):
                if recur(i, j, 0):
                    return True

        return False


if __name__ == '__main__':
    print('start')
    board = [["A", "B", "C", "E"], ["S", "F", "C", "S"], ["A", "D", "E", "E"]]
    board2 = [["a", "b"], ["c", "d"]]
    board3 = [['A', 'B']]
    board4 = [["C", "A", "A"], ["A", "A", "A"], ["B", "C", "D"]]
    word = 'ABCCED'
    word2 = 'abcd'
    word3 = 'BA'
    word4 = 'AAB'
    solution = Solution()
    print("result: ", solution.exist(board, word))
    print("result: ", solution.exist(board2, word2))
    print("result: ", solution.exist(board3, word3))
    print("result: ", solution.exist(board4, word4))
