#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
@Time    : 2020/11/29 12:32 下午
@Author  : luocai
@file    : counting_sort.py
@concat  : 429546420@qq.com
@site    : 
@software: PyCharm Community Edition 
@desc    :

计数排序
"""


def counting_sort(array):
    n = len(array)
    if n <= 1:
        return array

    # 1. 找到最大值
    max_val = array[0]
    for i in range(1, n):
        max_val = array[i] if array[i] > max_val else max_val

    # 2. 统计不同取值的个数并保存
    c = [0 for i in range(max_val + 1)]
    for a_v in array:
        c[a_v] += 1

    # 3. 按顺序求和
    for i in range(1, max_val + 1):
        c[i] += c[i - 1]

    # 4. 开始排序
    r = [0 for i in range(n)]
    for i in range(n - 1, -1, -1):
        index = c[array[i]] - 1
        r[index] = array[i]
        c[array[i]] -= 1

    return r


if __name__ == '__main__':
    test_data = [2, 5, 3, 0, 2, 3, 0, 3]
    print('待排序数组: ', test_data)
    sorted_array = counting_sort(test_data)
    print('排序好的数组: ', sorted_array)
