#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
@Time    : 2019/8/6 21:52
@Author  : luocai
@file    : simple_browser.py
@concat  : 429546420@qq.com
@site    : 
@software: PyCharm Community Edition 
@desc    :

实现简单的浏览器前进和后退功能:
我们使用两个栈，X 和 Y，我们把首次浏览的页面依次压入栈 X，当点击后退按钮时，再依次从栈 X 中出栈，
并将出栈的数据依次放入栈 Y。当我们点击前进按钮时，我们依次从栈 Y 中取出数据，放入栈 X 中。
当栈 X 中没有数据时，那就说明没有页面可以继续后退浏览了。当栈 Y 中没有数据，
那就说明没有页面可以点击前进按钮浏览了。

https://github.com/wangzheng0822/algo/blob/master/python/08_stack/simple_browser.py
"""

from Stack.linked_stack import LinkedStack
import copy


class NewLinkedStack(LinkedStack):
    def is_empty(self):
        return not self._top


class Browser():
    def __init__(self):
        # forward_stack 保存打开浏览器或者前进时候的页面
        self.forward_stack = NewLinkedStack()
        # back_stack 保存后退时候从 forward_stack 弹出的页面
        self.back_stack = NewLinkedStack()

    def can_forward(self):
        if self.back_stack.is_empty():
            return False
        return True

    def can_back(self):
        if self.forward_stack.is_empty():
            return False
        return True

    def open(self, url):
        print('Open new url {}'.format(url))
        self.forward_stack.push(url)

    def back(self):
        if self.forward_stack.is_empty():
            return
        # 点击后退按钮，从 forward_stack 中弹出当前页面，并保存到 back_stack 中
        top = self.forward_stack.pop()
        self.back_stack.push(top)
        print('back to {}'.format(top))

    def forward(self):
        if self.back_stack.is_empty():
            return
        # 点击前进按钮，从　back_stack 中弹出，然后保存到 forward_stack 中
        top = self.back_stack.pop()
        self.forward_stack.push(top)
        print('forward to {}'.format(top))

    def __repr__(self):
        copy_forward_stack = copy.deepcopy(self.forward_stack)
        url_list = list()
        while not copy_forward_stack.is_empty():
            url_list.append(copy_forward_stack.pop())
        return " ".join("{}".format(url) for url in url_list)


if __name__ == '__main__':
    browser = Browser()
    browser.open('a')
    browser.open('b')
    browser.open('c')
    print('open the browser: {}'.format(browser))
    if browser.can_back():
        browser.back()

    if browser.can_forward():
        browser.forward()

    browser.back()
    browser.back()
    browser.back()
    print('browser: {}'.format(browser))
