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
	OutOfBounds(){}
};

// ʹnew����NoMem�쳣������xalloc�쳣
void my_new_handler(){
	throw NoMem();
}

new_handler Old_Handler_ = std::set_new_handler(my_new_handler);

#endif