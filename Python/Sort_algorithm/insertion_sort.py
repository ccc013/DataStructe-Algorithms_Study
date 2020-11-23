#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
@Time    : 2020/11/23 10:51 下午
@Author  : luocai
@file    : insertion_sort.py
@concat  : 429546420@qq.com
@site    : 
@software: PyCharm Community Edition 
@desc    :

插入排序
"""


def insertion_sort(datas):
    n = len(datas)
    if n < 2:
        return datas
    for i in range(1, n):
        val = datas[i]
        j = i - 1
        # 查找插入的位置
        while j >= 0 and datas[j] > val:
            # 往后移动一位
            datas[j + 1] = datas[j]

            j -= 1
        # 插入数据
        datas[j + 1] = val

    return datas


if __name__ == '__main__':
    test_data = [4, 5, 6, 3, 2, 1]
    print('待排序数组: ', test_data)
    sorted_data = insertion_sort(test_data)
    print('排序后的数组: ', sorted_data)
