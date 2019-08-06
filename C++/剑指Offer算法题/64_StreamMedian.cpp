#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using std::vector;
using std::cout;
using std::endl;
using std::cin;


/* ��ȡ����������λ�� */
template<typename T> class DynamicArray
{
public:
	void Insert(T num)
	{
		if (((min.size() + max.size()) & 1) == 0)
		{
			// ���ݵ�������ż��
			if (max.size() > 0 && num < max[0])
			{
				max.push_back(num);
				push_heap(max.begin(), max.end(), std::less<T>());

				num = max[0];

				pop_heap(max.begin(), max.end(), std::less<T>());
				max.pop_back();
			}
			// ��֤��С�ѵ����ݶ��������ѵ�����
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
	// ��ߵ����ݱ��������ѣ��ұ����ݱ�������С�ѣ��������ǵ�������ˣ��������������м�������С����
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

// ����
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