#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
@Time    : 2020/12/9 8:11 上午
@Author  : luocai
@file    : jianzhi_offer_21_exchange.py
@concat  : 429546420@qq.com
@site    : 
@software: PyCharm Community Edition 
@desc    :

https://leetcode-cn.com/problems/diao-zheng-shu-zu-shun-xu-shi-qi-shu-wei-yu-ou-shu-qian-mian-lcof/
剑指 offer21 题--调整数组顺序使奇数位于偶数前面
"""
from typing import List


class Solution:
    def exchange(self, nums: List[int]) -> List[int]:
        # 双指针
        n = len(nums)
        i, j = 0, n - 1
        while i < j:
            if nums[j] % 2 == 0:
                # 尾部的元素是偶数
                j -= 1
            elif nums[i] % 2 == 0:
                # 同时满足 i 位置是偶数，j 位置是奇数，进行交换
                nums[i], nums[j] = nums[j], nums[i]
                j -= 1
            else:
                i += 1
        return nums

    def exchange2(self, nums: List[int]) -> List[int]:
        # 辅助数组
        odd_list, even_list = [], []
        for i in nums:
            if i % 2 == 0:
                even_list.append(i)
            else:
                odd_list.append(i)
        return odd_list + even_list


if __name__ == '__main__':
    nums = [1, 2, 3, 4]
    solution = Solution()
    print("origin array: ", nums)
    print("exchange: ", solution.exchange2(nums))
