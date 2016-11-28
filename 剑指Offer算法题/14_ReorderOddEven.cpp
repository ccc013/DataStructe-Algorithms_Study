#include<iostream>

using std::cout;
using std::endl;
using std::cin;

// 判断是否是偶数
bool isEven(int n){
	return (n & 1) == 0;
}

// 重新排序
void Reorder(int *pData, unsigned int length, bool (*func)(int)){
	if (pData == NULL || length <= 0){
		return;
	}
	int *pBegin = pData;
	int *pEnd = pData + length - 1;
	while (pBegin < pEnd){
		// 向后移动 pBegin,直到它指向偶数
		while (pBegin < pEnd && !func(*pBegin))
			pBegin++;
		// 向前移动 pEnd,直到它指向奇数
		while (pBegin < pEnd && func(*pEnd))
			pEnd--;

		if (pBegin < pEnd){
			int temp = *pBegin;
			*pBegin = *pEnd;
			*pEnd = temp;
		}
	}
}

void ReorderOddEven(int *pData, unsigned int length){
	Reorder(pData, length, isEven);
}
// 输出数值
void printArray(int *a,int length){
	if (a == NULL || length <= 0){
		cout << "error!\n";
		return;
	}
	for (int i = 0; i < length; i++)
		cout << a[i]<<" ";
	cout << endl;

}

// 测试
int main(void){
	// 数值中的奇数、偶数交替出现
	int t1[] = { 1, 2, 3, 4, 5, 6 };
	cout << "origin: ";
	printArray(t1, 6);
	ReorderOddEven(t1, 6);
	cout << "after: ";
	printArray(t1, 6);
	// 偶数都在奇数前面
	int t2[] = { 2, 4, 6, 1, 5, 3 };
	cout << "origin: ";
	printArray(t2, 6);
	ReorderOddEven(t2, 6);
	cout << "after: ";
	printArray(t2, 6);
	// 偶数都在奇数后面
	int t3[] = { 1, 5, 3, 4, 2, 6 };
	cout << "origin: ";
	printArray(t3, 6);
	ReorderOddEven(t3, 6);
	cout << "after: ";
	printArray(t3, 6);

	system("pause");
	return 0;
}