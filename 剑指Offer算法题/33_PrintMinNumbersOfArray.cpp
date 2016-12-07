#include<iostream>
#include<string>
#include<sstream>
#include<algorithm>
using std::string;
using std::cout;
using std::endl;
using std::cin;

/*输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出来的所有数字中最小的一个 */

// 比较拼接后的两种情况下的两个数的大小
bool compare(const string strNumber1, const string strNumber2)
{
	string str1 = strNumber1 + strNumber2;
	string str2 = strNumber2 + strNumber1;
	return str2>str1;
}

// 解法
void PrintMinNumber(int* numbers, int length){
	if (numbers == NULL || length <= 0){
		cout << "wrong input\n";
		return;
	}	
	std::stringstream ss;//用来数字和字符串转换；
	string* str = new string[length];
	// 将数字转换成字符串
	for (int i = 0; i < length; ++i)
	{
		ss.clear();
		ss << numbers[i];
		ss >> str[i];
	}
	// 使用库函数sort进行排序
	sort(str, str + length, compare);

	for (int i = 0; i < length; i++)
		cout << str[i];
	cout << endl;

	delete[] str;
}

void Test(int* numbers, int length){
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
	PrintMinNumber(numbers, length);
}

// 测试
int main(void){
	int t1[] = { 13, 32, 321 };
	Test(t1, 3);
	int t2[] = { 1, 23, 54 };
	Test(t2, 3);
	int t3[] = { 11, 23, 324, 9, 8 };
	Test(t3, 5);
	int t4[] = { 234 };
	Test(t4, 1);
	
	Test(NULL, 1);


	system("pause");
	return 0;
}