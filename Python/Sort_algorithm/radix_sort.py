#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
@Time    : 2020/11/29 4:39 下午
@Author  : luocai
@file    : radix_sort.py
@concat  : 429546420@qq.com
@site    :
@software: PyCharm Community Edition
@desc    :

基数排序
"""


def radix_sort(array):
    num = len(array)
    if num < 2:
        return

    # 最大的位数
    max_bits = find_max_bits(array)
    # 建立桶集合，总共 10 个桶
    res = [[] for i in range(10)]
    div = 1
    # 从低位到高位循环迭代
    for i in range(max_bits):
        for val in array:
            # 获取当前元素要分配到的桶
            bit = int(val / div) % 10
            res[bit].append(val)
        # 更高一位
        div *= 10

        # 重新排序
        k = 0
        for ii in range(10):
            m = len(res[ii])
            for j in range(m):
                array[k] = res[ii][j]
                k += 1
        # 清空桶的内容
        res = [[] for i in range(10)]


# 找到数组中最多的位数
def find_max_bits(array):
    _max = 0

    for val in array:
        d = 0
        while val > 1:
            val /= 10
            d += 1

        _max = _max if _max > d else d

    return _max


if __name__ == '__main__':
    test_data = [20, 15, 31, 0, 12, 31, 40, 32]
    print('待排序数组: ', test_data)
    radix_sort(test_data)
    print('排序好的数组: ', test_data)
