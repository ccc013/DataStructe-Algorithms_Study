#include<iostream>
#include<list>
using std::list;
using std::cout;
using std::endl;
using std::cin;

/*求1+2+...+n，要求不能使用乘除法，for,while,if,else,switch,case等关键字及条件判断语句(A?B:C)*/
// 解法1，利用构造函数求解
class Temp{
public:
	Temp(){
		++N;
		Sum += N;
	}
	static void Reset(){
		N = 0;
		Sum = 0;
	}
	static unsigned int GetSum(){
		return Sum;
	}
private:
	static unsigned int N;
	static unsigned int Sum;
};
unsigned int Temp::N = 0;
unsigned int Temp::Sum = 0;

unsigned int Sum_Solution1(unsigned int n){
	Temp::Reset();
	
	Temp *a = new Temp[n];
	delete[] a;
	a = NULL;

	return Temp::GetSum();
}

// 解法2,利用虚函数求解
class A;
A* Array[2];

class A{
public:
	virtual unsigned int Sum(unsigned int n){
		return 0;
	}
};

class B : public A{
public:
	virtual unsigned int Sum(unsigned int n){
		return Array[!!n]->Sum(n - 1) + n;
	}
};

int Sum_Solution2(int n){
	A a;
	B b;
	Array[0] = &a;
	Array[1] = &b;

	int value = Array[1]->Sum(n);
	return value;
}

// 解法3，利用函数指针求解
typedef unsigned int(*fun)(unsigned int);

unsigned int Solution3_Teminator(unsigned int n){
	return 0;
}
unsigned int Sum_Solution3(unsigned int n){
	static fun f[2] = { Solution3_Teminator, Sum_Solution3 };
	return n + f[!!n](n - 1);
}

// 解法4，利用模板类型求解
template<unsigned int n> struct Sum_Solution4{
	enum Value {N = Sum_Solution4<n-1>::N+n};
};
template<> struct Sum_Solution4<1>{
	enum Value { N = 1 };
};

void Test(int numbers){
	cout << "from 1 to " << numbers << endl;
	cout << "Sum_Solution1 = " << Sum_Solution1(numbers) << endl;
	cout << "Sum_Solution2 = " << Sum_Solution2(numbers) << endl;
	cout << "Sum_Solution3 = " << Sum_Solution3(numbers) << endl;

}

// 测试
int main(void){
	Test(10);
	Test(0);
	Test(1);
	Test(5);
	

	system("pause");
	return 0;
}