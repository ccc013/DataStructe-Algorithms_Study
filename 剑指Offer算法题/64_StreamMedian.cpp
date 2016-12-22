#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using std::vector;
using std::cout;
using std::endl;
using std::cin;


/* 获取数据流的中位数 */
template<typename T> class DynamicArray
{
public:
	void Insert(T num)
	{
		if (((min.size() + max.size()) & 1) == 0)
		{
			// 数据的总数是偶数
			if (max.size() > 0 && num < max[0])
			{
				max.push_back(num);
				push_heap(max.begin(), max.end(), std::less<T>());

				num = max[0];

				pop_heap(max.begin(), max.end(), std::less<T>());
				max.pop_back();
			}
			// 保证最小堆的数据都大于最大堆的数据
			min.push_back(num);
			push_heap(min.begin(), min.end(), std::greater<T>());
		}
		else
		{
			if (min.size() > 0 && min[0] < num)
			{
				min.push_back(num);
				push_heap(min.begin(), min.end(), std::greater<T>());

				num = min[0];

				pop_heap(min.begin(), min.end(), std::greater<T>());
				min.pop_back();
			}

			max.push_back(num);
			push_heap(max.begin(), max.end(), std::less<T>());
		}
	}
	// 左边的数据保存在最大堆，右边数据保存在最小堆，且数据是递增，因此，总数是奇数，中间数在最小堆中
	T GetMedian()
	{
		int size = min.size() + max.size();
		if (size == 0)
			throw std::exception("No numbers are available");

		T median = 0;
		if ((size & 1) == 1)
			median = min[0];
		else
			median = (min[0] + max[0]) / 2;

		return median;
	}

private:
	vector<T> min;
	vector<T> max;
};

// ==================== Test Code ====================
void Test(char* testName, DynamicArray<double>& numbers, double expected)
{
	if (testName != NULL)
		cout << testName <<" begins: ";

	if (abs(numbers.GetMedian() - expected) < 0.0000001)
		cout<<"Passed.\n";
	else
		cout << "FAILED.\n";
}

// 测试
int main(void){
	DynamicArray<double> numbers;

	cout << "Test1 begins: ";
	try
	{
		numbers.GetMedian();
		cout << "FAILED.\n";
	}
	catch (std::exception e)
	{
		cout << "Passed.\n";
	}

	numbers.Insert(5);
	Test("Test2", numbers, 5);

	numbers.Insert(2);
	Test("Test3", numbers, 3.5);

	numbers.Insert(3);
	Test("Test4", numbers, 3);

	numbers.Insert(4);
	Test("Test6", numbers, 3.5);

	numbers.Insert(1);
	Test("Test5", numbers, 3);

	numbers.Insert(6);
	Test("Test7", numbers, 3.5);

	numbers.Insert(7);
	Test("Test8", numbers, 4);

	numbers.Insert(0);
	Test("Test9", numbers, 3.5);

	numbers.Insert(8);
	Test("Test10", numbers, 4);

	system("pause");
	return 0;
}