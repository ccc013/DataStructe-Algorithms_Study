#include<iostream>
using std::cout;
using std::endl;
using std::cin;

// 替换空格,length是字符数组string的总容量
void ReplaceBlank(char string[], int length){
	if (string == NULL || length <= 0){
		return;
	}
	// 字符串string的实际长度
	int originLength = 0;
	int numberOfBlank = 0;
	int i = 0;
	// 统计空格的数量和字符的数量
	while (string[i] != '\0'){
		++originLength;
		if (string[i] == ' ')
			++numberOfBlank;
		++i;
	}
	// 替换空格后的字符串新长度
	int newLength = originLength + numberOfBlank * 2;
	if (newLength > length)
		return;

	int indexOfOriginal = originLength;
	int indexOfNew = newLength;
	while (indexOfOriginal >= 0 && indexOfNew > indexOfOriginal){
		if (string[indexOfOriginal] == ' '){
			string[indexOfNew--] = '0';
			string[indexOfNew--] = '2';
			string[indexOfNew--] = '%';
		}
		else{
			string[indexOfNew--] = string[indexOfOriginal];
		}
		indexOfOriginal--;
	}
}

// 测试
int main(void){
	char str[10] = " hello";
	char str2[10] = "he llo";
	char str3[10] = "hello ";
	char str4[30] = "We  are  happy.";
	char str5[30] = "helloWorld.";
	char *str6 = NULL;
	char str7[10] = "";
	char str8[10] = " ";
	char str9[20] = "     ";
	// 空格位于字符串的最前面
	cout << "origin: " << str;
	ReplaceBlank(str, 10);
	cout << ",--> " << str << endl;
	// 空格位于字符串的最后面
	cout << "origin: " << str2;
	ReplaceBlank(str2, 10);
	cout << ",--> " << str2 << endl;
	// 空格位于字符串的中间
	cout << "origin: " << str3;
	ReplaceBlank(str3, 10);
	cout << ",--> " << str3 << endl;
	// 字符串中有多个连续空格
	cout << "origin: " << str4;
	ReplaceBlank(str4, 30);
	cout << ",--> " << str4 << endl;
	// 输入的字符串没有空格
	cout << "origin: " << str5;
	ReplaceBlank(str5, 30);
	cout << ",--> " << str5 << endl;
	// 字符串是空指针
	//	cout << "origin: " << str6;
	ReplaceBlank(str6, 10);
	//	cout << ",--> " << str6 << endl;
	// 字符串是空字符串
	cout << "origin: " << str7;
	ReplaceBlank(str7, 10);
	cout << ",--> " << str7 << endl;
	// 字符串只有一个空格字符
	cout << "origin: " << str8;
	ReplaceBlank(str8, 10);
	cout << ",--> " << str8 << endl;
	// 字符串中只有多个连续空格
	cout << "origin: " << str9;
	ReplaceBlank(str9, 20);
	cout << ",--> " << str9 << endl;

	system("pause");
	return 0;
}