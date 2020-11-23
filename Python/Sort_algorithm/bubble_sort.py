#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
@Time    : 2019/9/10 15:33
@Author  : luocai
@file    : bubble_sort.py
@concat  : 429546420@qq.com
@site    : 
@software: PyCharm Community Edition 
@desc    :

排序算法：
1. 冒泡排序

"""


def bubble_sort(datas):
    if len(datas) < 2:
        return datas

    nums = len(datas)

    for i in range(nums):
        # 判断当前操作是否有交换数据的操作
        flag = False
        for j in range(nums - i - 1):
            if datas[j] > datas[j + 1]:
                flag = True
                datas[j], datas[j + 1] = datas[j + 1], datas[j]
        if not flag:
            return datas


if __name__ == '__main__':
    test_data = [4, 5, 6, 3, 2, 1]
    print('待排序数组: ', test_data)
    sorted_data = bubble_sort(test_data)
    print('排序后的数组: ', sorted_data)
