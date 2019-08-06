#include<iostream>

using std::cout;
using std::endl;
using std::cin;

/* ���һ�����ܱ��̳е��� */

// �ⷨ1�������캯����Ϊ˽�к���
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

// �ⷨ2����������̳�
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
	// ���ܵõ����ϵ�ʵ�������ܵõ�ջ�ϵ�ʵ��
	SealedClass1* seal =SealedClass1::GetInstance(num);
	cout << "class number = "<<seal->num << endl;
	// �ⷨ2���Եõ��Ѻ�ջ�ϵ�ʵ��
	SealedClass2 seal2;
	seal2.output(10);
	SealedClass2* pSeal2 = new SealedClass2();
	pSeal2->output(15);
}

// ����
int main(void){
	Test(10);
	

	system("pause");
	return 0;
}