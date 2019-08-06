#ifndef XCEPT_H_
#define XCEPT_H_
#include<iostream>

// �ڴ治��
class NoMem{
public:
	NoMem(){}
};

// ���������ķ�Χ
class OutOfBounds{
public:
	OutOfBounds(){
		std::cerr << "Out of the range!\n";
	}
};

// ��ʼ������
class BadInitializers{
public:
	BadInitializers(){
		std::cerr << "Bad initialize!\n";
	}
};

// �ߴ粻ƥ��
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

// ʹnew����NoMem�쳣������xalloc�쳣
void my_new_handler(){
	throw NoMem();
}

new_handler Old_Handler_ = std::set_new_handler(my_new_handler);

#endif