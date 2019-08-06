#include<iostream>
#include<vector>
using std::vector;
using std::cout;
using std::endl;
using std::cin;

/*计数排序 */

//获得未排序数组中最大的一个元素值
int GetMaxVal(int* arr, int len)
{
	int maxVal = arr[0]; //假设最大为arr[0]

	for (int i = 1; i < len; i++)  //遍历比较，找到大的就赋值给maxVal
	{
		if (arr[i] > maxVal)
			maxVal = arr[i];
	}

	return maxVal;  //返回最大值
}
void CountSort(int *numbers, int length, int max){
	if (numbers == NULL || length <= 0){
		cout << "wrong input!";
		return;
	}
	vector<int> bucket(max, 0);
	/*for (int i = 0; i < length + 1; i++){
	bucket[i] = 0;
	}*/
	// 计算数组中每个元素出现的次数
	for (int i = 0; i < length; i++){
		bucket[numbers[i]] ++;
	}
	// 排序
	int count = 0;
	for (int i = 0; i < max; i++){
		if (bucket[i] > 0){
			for (int j = 0; j < bucket[i]; j++){
				numbers[count++] = i;
			}
		}
	}
}
// 第二种计数排序方法
int ctsort(int *data, int size, int k)
{
	int * counts = NULL,/*计数数组*/
		*temp = NULL;/*保存排序后的数组*/
	int i = 0;
	/*申请数组空间*/
	if ((counts = (int *)malloc(k * sizeof(int))) == NULL)
		return -1;
	if ((temp = (int *)malloc(k * sizeof(int))) == NULL)
		return -1;
	/*初始化计数数组*/
	for (i = 0; i < k; i++)
		counts[i] = 0;
	/*数组中出现的元素，及出现次数记录*/
	for (i = 0; i < size; i++)
		counts[data[i]] += 1;
	/*调整元素计数中，加上前一个数，记录不比该位置的元素i大的个数*/
	for (i = 1; i < k; i++)
		counts[i] += counts[i - 1];
	/*使用计数数组中的记录数值，来进行排序，排序后保存的temp*/
	for (i = size - 1; i >= 0; i--){
		// 减一是减去data[i]本身
		counts[data[i]] -= 1;
		temp[counts[data[i]]] = data[i];
	}

	memcpy(data, temp, size * sizeof(int));
	free(counts);
	free(temp);
	return 0;
}


void Test(int *numbers, int length){
	if (numbers == NULL)
		cout << "Test for NULL:";
	else{
		cout << "Test for array:{";
		for (int i = 0; i < length; i++){
			cout << numbers[i];
			if (i == length - 1)
				cout << "}\n";
			else
				cout << ", ";
		}
	}
	int max = GetMaxVal(numbers, length) + 1;
	CountSort(numbers, length,max);
	if (numbers != NULL){
		cout << "after using BucketSort: ";
		for (int i = 0; i < length; i++){
			cout << numbers[i];
			if (i == length - 1)
				cout << "\n";
			else
				cout << ", ";
		}
	}
}

// 测试
int main(void){
	int t1[] = { 1, 3, 5, 2, 4, 8, 10, 9 };
	int t2[] = { 1, 1, 3, 2, 2, 5, 6, 2, 10, 12, 8, 3 };
	Test(t1, 8);
	Test(t2, 12);
	Test(NULL, 2);


	system("pause");
	return 0;
}