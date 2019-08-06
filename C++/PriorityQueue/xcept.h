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
	OutOfBounds(){
		std::cerr << "Out of the range!\n";
	}
};

// 初始化出错
class BadInitializers{
public:
	BadInitializers(){
		std::cerr << "Bad initialize!\n";
	}
};

// 尺寸不匹配
class SizeMismatch{
public:
	SizeMismatch(){
		std::cerr << "Size not match!\n";
	}
};

class MustBeZero{
public:
	MustBeZero(){
		std::cerr << "it must be zero!\n";
	}
};

class BadInput{
public:
	BadInput(){
		std::cerr << "Bad input!\n";
	}
};

// 使new引发NoMem异常而不是xalloc异常
void my_new_handler(){
	throw NoMem();
}

new_handler Old_Handler_ = std::set_new_handler(my_new_handler);

#endif