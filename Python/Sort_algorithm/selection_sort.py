#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
@Time    : 2020/11/23 11:03 下午
@Author  : luocai
@file    : selection_sort.py
@concat  : 429546420@qq.com
@site    : 
@software: PyCharm Community Edition 
@desc    :

选择排序
"""


def selection_sort(datas):
    n = len(datas)
    if n < 2:
        return datas
    for i in range(n):
        min_val = datas[i]
        min_index = i
        # 查找未排序区域的最小值
        for j in range(i + 1, n):
            if datas[j] < min_val:
                min_val = datas[j]
                min_index = j
        # 和未排序区域第一个元素进行交换
        datas[i], datas[min_index] = min_val, datas[i]

    return datas


if __name__ == '__main__':
    test_data = [4, 5, 6, 3, 2, 1]
    print('待排序数组: ', test_data)
    sorted_data = selection_sort(test_data)
    print('排序后的数组: ', sorted_data)
