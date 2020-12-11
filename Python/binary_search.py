#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
@Time    : 2020/12/11 11:47 下午
@Author  : luocai
@file    : binary_search.py
@concat  : 429546420@qq.com
@site    : 
@software: PyCharm Community Edition 
@desc    :

二分查找
"""
from typing import List


# 非递归实现方式
def binary_search(array: List[int], target: int) -> int:
    num = len(array)
    low, high = 0, num - 1
    while low <= high:
        mid = low + ((high - low) >> 1)
        if array[mid] == target:
            return mid
        elif array[mid] > target:
            high = mid - 1
        else:
            low = mid + 1

    return -1


# 递归实现
def binary_search_recursive(array: List[int], target: int) -> int:
    return bsearch(array, 0, len(array) - 1, target)


def bsearch(array, low, high, target):
    if low > high:
        return -1
    mid = low + ((high - low) >> 1)
    if array[mid] == target:
        return mid
    elif array[mid] > target:
        return bsearch(array, low, mid - 1, target)
    else:
        return bsearch(array, mid + 1, high, target)


# 查找第一个等于给定值的元素
def find_first_equal_value(array, target):
    num = len(array)
    low, high = 0, num - 1
    while low <= high:
        mid = low + ((high - low) >> 1)
        if array[mid] > target:
            high = mid - 1
        elif array[mid] < target:
            low = mid + 1
        else:
            if (mid == 0) | (array[mid - 1] != target):
                return mid
            else:
                high = mid - 1
    return -1


# 查找最后一个值等于给定值的元素
def find_last_equal_value(array, target):
    num = len(array)
    low, high = 0, num - 1
    while low <= high:
        mid = low + ((high - low) >> 1)
        if array[mid] > target:
            high = mid - 1
        elif array[mid] < target:
            low = mid + 1
        else:
            if (mid == num - 1) | (array[mid + 1] != target):
                return mid
            else:
                low = mid + 1
    return -1


# 查找第一个大于等于给定值的元素
def find_first_large_equal_value(array, target):
    num = len(array)
    low, high = 0, num - 1
    while low <= high:
        mid = low + ((high - low) >> 1)
        if array[mid] >= target:
            if (mid == 0) | (array[mid - 1] < target):
                return mid
            else:
                high = mid - 1
        else:
            low = mid + 1

    return -1


# 查找最后一个小于等于给定值的元素
def find_last_less_equal_value(array, target):
    num = len(array)
    low, high = 0, num - 1
    while low <= high:
        mid = low + ((high - low) >> 1)
        if array[mid] > target:
            high = mid - 1
        else:
            if (mid == num - 1) | (array[mid + 1] > target):
                return mid
            else:
                low = mid + 1
    return -1


if __name__ == '__main__':
    array = [1, 2, 3, 3, 3, 4, 4, 5]
    print("find_first_value result1: ", find_first_equal_value(array, 4))
    print("find_last_value result1: ", find_last_equal_value(array, 4))
    print("find_first_large_equal_value result1: ", find_first_large_equal_value(array, 4))
    print("find_last_less_equal_value result1: ", find_last_less_equal_value(array, 4))
