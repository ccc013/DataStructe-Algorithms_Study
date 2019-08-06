#include<iostream>
#include<vector>
using std::vector;
using std::cout;
using std::endl;
using std::cin;

/* ����һ������A[0,1,...,n-1],�빹��һ������B[0,1,...,n-1],����B[i]=A[0]*A[1]*...A[i-1]*A[i+1]*...*A[n-1]������ʹ�ó��� */
void multiply(const vector<double>& array1, vector<double>& array2){
	int length1 = array1.size();
	int length2 = array2.size();
	if (length1 == length2 && length2 > 1){
		array2[0] = 1;
		for (int i = 1; i < length1; ++i){
			array2[i] = array2[i - 1] * array1[i - 1];
		}
		double temp = 1;
		for (int i = length1 - 2; i >= 0; --i){
			temp *= array1[i + 1];
			array2[i] *= temp;
		}
	}
}

void Test(const vector<double>& array1){
	if (array1.size() > 0){
		cout << "Test array: ";
		for (int i = 0; i < array1.size(); i++)
			cout << array1[i] << " ";
		cout << endl;
	}
	else
		cout << "Test Null array: ";
	vector<double> array2(array1.size());
	multiply(array1, array2);
	if (array2.size() > 0){
		for (int i = 0; i < array2.size(); i++)
			cout << array2[i] << " ";
		cout << endl;
	}
	
}

// ����
int main(void){
	vector<double> t1 = { 1, 2, 3, 4, 5};
	Test(t1);
	

	system("pause");
	return 0;
}