#include<iostream>

using std::cout;
using std::endl;
using std::cin;

/* дһ������������������֮�ͣ�Ҫ�����㺯�����ڲ���ʹ�üӼ��˳�����������š�*/

int Add(int num1, int num2){
	int sum, carry;
	do{
		// ��������ÿ��λ
		sum = num1 ^ num2;
		// λ�����㣬���λ
		carry = (num1 & num2) << 1;

		num1 = sum;
		num2 = carry;
	} while (num2 != 0);

	return num1;
}

void Test(int num1, int num2){
	cout << num1 << " + " << num2 << " = " << Add(num1, num2) << endl;
}

// ����
int main(void){
	Test(12, 14);
	Test(2, 0);
	Test(1, -2);
	Test(0, -2);
	Test(-2, -5);
	

	system("pause");
	return 0;
}