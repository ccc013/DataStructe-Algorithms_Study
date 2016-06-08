#ifndef XCEPT_H_
#define XCEPT_H_
#include<iostream>

// 内存不足
class NoMem{
public:
	NoMem(){}
};

// 超过期望的范围
class OutOfBounds{
public:
	OutOfBounds(){}
};

// 使new引发NoMem异常而不是xalloc异常
void my_new_handler(){
	throw NoMem();
}

new_handler Old_Handler_ = std::set_new_handler(my_new_handler);

#endif