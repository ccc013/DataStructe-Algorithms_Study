#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
@Time    : 2020/11/29 11:51 上午
@Author  : luocai
@file    : bucket_sort.py
@concat  : 429546420@qq.com
@site    : 
@software: PyCharm Community Edition 
@desc    :

桶排序
"""


def bucket_sort(array):
    num = len(array)
    if num < 2:
        return

    # 10个桶
    res = [[] for i in range(10)]
    for i in range(num):
        # 通过除以 10 来决定放到哪个桶中
        flag = int(array[i] / 10)
        res[flag].append(array[i])
        # 排序
        res[flag].sort()
    # 将排序好的数据重新读取，得到最终的排序数组
    k = 0
    for i in range(10):
        m = len(res[i])
        for j in range(m):
            array[k] = res[i][j]
            k += 1


if __name__ == '__main__':
    test_data = [20, 15, 31, 0, 12, 31, 40, 32]
    print('待排序数组: ', test_data)
    bucket_sort(test_data)
    print('排序好的数组: ', test_data)
