#include<iostream>
#include<set>
#include <functional>
#include<vector>
using std::vector;
using std::cout;
using std::endl;
using std::cin;
typedef std::multiset<int, std::greater<int> > intSet;
typedef std::multiset<int, std::greater<int> >::iterator setIterator;

/*求最小的k个数 */
bool g_bInputInvalid = false;

void swap(int &a, int &b)
{
	int temp = b;
	b = a;
	a = temp;
}
// 产生随机数
int RandomInRange(int start, int end){
	return rand() % (end - start + 1)+start;
}
int Partition(int* numbers, int length, int start, int end){
	if (numbers == NULL || length <= 0 || start < 0 || end >= length){
		cout << "Invalid Parameters!\n";
		g_bInputInvalid = true;
		return -1;
	}
	int index = RandomInRange(start, end);
	swap(numbers[index], numbers[end]);
	int small = start - 1;
	for (index = start; index < end; ++index){
		if (numbers[index] < numbers[end]){
			++small;
			if (small != index)
				swap(numbers[index], numbers[small]);
		}
	}
	++small;
	swap(numbers[small], numbers[end]);
	return small;
}
// 实现代码,解法1，O(n), 先对数组进行排序
void GetLeastNumbers(int* input, int n, int *output, int k){
	if (input == NULL || output == NULL || k > n || n <= 0 || k <= 0){
		g_bInputInvalid = true;
		return;
	}
	int start = 0;
	int end = n - 1;
	int index = Partition(input, n, start, end);
	while (index != k - 1){
		if (index > k - 1){
			end = index - 1;
			index = Partition(input, n, start, end);
		}
		else{
			start = index + 1;
			index = Partition(input, n, start, end);
		}
	}
	for (int i = 0; i < k; i++)
		output[i] = input[i];
}
// 解法2， O(nlogk)，使用容器multiset
void GetLeastNumbers(const vector<int>& data, intSet& leastNumbers, int k){
	leastNumbers.clear();
	if (k < 1 || data.size() < k){
		g_bInputInvalid = true;
		return;
	}
	vector<int>::const_iterator iter = data.begin();
	for (; iter != data.end(); ++iter){
		if (leastNumbers.size() < k)
			leastNumbers.insert(*iter);
		else{
			setIterator iterGreatest = leastNumbers.begin();
			if (*iter < *(leastNumbers.begin())){
				leastNumbers.erase(iterGreatest);
				leastNumbers.insert(*iter);
			}
		}
	}
}

void Test(int *numbers, int length, int *output, int k){
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
	cout << "k= " << k << endl;
	cout << "Solution1 result: ";
	GetLeastNumbers(numbers, length, output, k);
	if (g_bInputInvalid)
		cout << "wrong input!\n";
	else
		for (int i = 0; i < k; i++){
			cout << output[i];
			if (i == k - 1)
				cout << "\n";
			else
				cout << ", ";
		}
	cout << "Solution2 result: ";
	vector<int> data;
	if (numbers == NULL){
		cout << "array is Null\n";
		return;
	}
	for (int i = 0; i < length; i++){
		data.push_back(numbers[i]);
	}
	intSet leastNumbers;
	GetLeastNumbers(data, leastNumbers, k);
	if (g_bInputInvalid)
		cout << "wrong input!\n";
	else{
		setIterator iter = leastNumbers.begin();
		for (; iter != leastNumbers.end(); iter++){
			cout << *iter << " ";
		}
		cout << endl;
	}
}

// 测试
int main(void){
	int a1[] = { 1, 2, 2, 3, 4, 5, 6 };
	int o1[3];
	Test(a1, 7,o1,3);
	int a2[] = { 1,3,5,0,2,7,8 };
	Test(a2, 7,o1,3);
	int a3[] = { 1, 3, 5, 0, 2, 7, 8 };
	int o2[7];
	Test(a3, 7, o2, 7);
	int o3[1];
	Test(a3, 7, o3, 1);
	Test(a3, 7, o3, 0);
	Test(a3, 7, o3, 10);
	Test(NULL, 1,o1,3);


	system("pause");
	return 0;
}