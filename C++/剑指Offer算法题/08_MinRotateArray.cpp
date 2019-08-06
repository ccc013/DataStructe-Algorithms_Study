#include<iostream>

using std::cout;
using std::endl;
using std::cin;
// 顺序查找
int MinInOrder(int* numbers, int index1, int index2){
	int result = numbers[index1];
	for (int i = index1 + 1; i < index2; i++){
		if (result>numbers[i])
			result = numbers[i];
	}
	return result;
}
// 寻找旋转数组的最小值
int Min(int* numbers, int length){
	if (numbers == NULL || length <= 0){
		throw new std::exception("Invaild parameters.\n");
	}

	int index1 = 0;
	int index2 = length - 1;
	int indexMid = index1;
	while (numbers[index1] >= numbers[index2]){
		if (index2 - index1 == 1){
			indexMid = index2;
			break;
		}
		indexMid = (index1 + index2) / 2;
		// 如果下标为index1，index2和indexMid指向的数字都相等，只能使用顺序查找
		if (numbers[index1] == numbers[index2]
			&& numbers[index1] == numbers[indexMid])
			return MinInOrder(numbers, index1, index2);

		if (numbers[indexMid] > numbers[index1])
			index1 = indexMid;
		else if (numbers[indexMid] <= numbers[index2])
			index2 = indexMid;
	}

	return numbers[indexMid];
		
}

// 测试
int main(void){
	// 升序排序数组的一个选择数组
	int a1[5] = { 3, 4, 5, 1, 2 };
	cout << "min = " << Min(a1, 5) << endl;
	// 有重复数字
	int a2[5] = { 3, 4, 5, 1, 1 };
	cout << "min = " << Min(a2, 5) << endl;
	// 升序排序数组
	int a3[5] = { 2, 3, 4, 5, 6 };
	cout << "min = " << Min(a3, 5) << endl;
	// 只有一个数字
	int a4[1] = { 4 };
	cout << "min = " << Min(a4, 1) << endl;
	// 特例测试
	int a5[5] = { 1, 0, 1, 1, 1 };
	cout << "min = " << Min(a5, 5) << endl;
	int a6[] = { 1, 1, 1, 0, 1 };
	cout << "min = " << Min(a6, 5) << endl;

	system("pause");
	return 0;
}