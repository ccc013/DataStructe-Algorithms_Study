#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
@Time    : 2020/11/27 10:44 下午
@Author  : luocai
@file    : merge_sort.py
@concat  : 429546420@qq.com
@site    : 
@software: PyCharm Community Edition 
@desc    :

归并排序
"""


def merge_sort(array):
    _merge_sort_between(array, 0, len(array) - 1)


# 递归分解数组
def _merge_sort_between(arr, left, right):
    if left < right:
        mid = left + (right - left) // 2
        _merge_sort_between(arr, left, mid)
        _merge_sort_between(arr, mid + 1, right)
        _merge(arr, left, mid, right)


# 排序&合并数组
def _merge(arr, left, mid, right):
    i, j = left, mid + 1
    tmp = []
    while i <= mid and j <= right:
        if arr[i] <= arr[j]:
            tmp.append(arr[i])
            i += 1
        else:
            tmp.append(arr[j])
            j += 1
    # 处理剩余的数组
    start = i if i <= left else j
    end = mid if i <= left else right
    tmp.extend(arr[start:end + 1])
    arr[left:right + 1] = tmp


if __name__ == '__main__':
    test_data = [4, 5, 6, 3, 2, 1]
    print('待排序数组: ', test_data)
    merge_sort(test_data)
    print("排序好的数组: ", test_data)
