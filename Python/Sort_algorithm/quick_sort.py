#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
@Time    : 2020/11/27 11:05 下午
@Author  : luocai
@file    : quick_sort.py
@concat  : 429546420@qq.com
@site    : 
@software: PyCharm Community Edition 
@desc    :

快速排序
"""
import random
from typing import List


def quick_sort(a: List[int]):
    _quick_sort_between(a, 0, len(a) - 1)


def _quick_sort_between(a: List[int], low: int, high: int):
    if low < high:
        # get a random position as the pivot
        k = random.randint(low, high)
        a[low], a[k] = a[k], a[low]

        m = _partition(a, low, high)  # a[m] is in final position
        _quick_sort_between(a, low, m - 1)
        _quick_sort_between(a, m + 1, high)


def _partition(a: List[int], low: int, high: int):
    pivot, j = a[low], low
    for i in range(low + 1, high + 1):
        if a[i] <= pivot:
            j += 1
            a[j], a[i] = a[i], a[j]  # swap
    a[low], a[j] = a[j], a[low]
    return j


if __name__ == '__main__':
    test_data = [4, 5, 6, 3, 2, 1]
    print('待排序数组: ', test_data)
    quick_sort(test_data)
    print("排序好的数组: ", test_data)
