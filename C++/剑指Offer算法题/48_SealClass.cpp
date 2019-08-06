#include<iostream>

using std::cout;
using std::endl;
using std::cin;

/* 设计一个不能被继承的类 */

// 解法1，将构造函数设为私有函数
class SealedClass1{
public:
	int num;
	static SealedClass1* GetInstance(int n){
		SealedClass1 *pa = new SealedClass1;
		pa->num = n;
		cout << "num is:" << pa->num << endl;
		return pa;
	}
	static void DeleteInstance(SealedClass1* pInstance){
		delete pInstance;
	}
private:
	SealedClass1() {}
	~SealedClass1() {}
};

// 解法2，利用虚拟继承
template<typename T> class MakeSealed{
	friend T;
private:
	MakeSealed() {}
	~MakeSealed() {}
};

class SealedClass2 : virtual public MakeSealed<SealedClass2>{
public:
	SealedClass2(){}
	~SealedClass2() {}
	void output(int n){
		cout << "input number is " << n << endl;
	}
};

void Test(int num){
	// 仅能得到堆上的实例，不能得到栈上的实例
	SealedClass1* seal =SealedClass1::GetInstance(num);
	cout << "class number = "<<seal->num << endl;
	// 解法2可以得到堆和栈上的实例
	SealedClass2 seal2;
	seal2.output(10);
	SealedClass2* pSeal2 = new SealedClass2();
	pSeal2->output(15);
}

// 测试
int main(void){
	Test(10);
	

	system("pause");
	return 0;
}