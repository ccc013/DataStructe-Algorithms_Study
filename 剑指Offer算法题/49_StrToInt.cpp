#include<iostream>

using std::cout;
using std::endl;
using std::cin;

/* 字符串转换成整数 */
enum Status {kValid = 0, kInvalid};
int g_nStatus = kValid;

long long StrToIntCore(const char* digit, bool minus){
	long long num = 0;

	while (*digit != '\0'){
		if (*digit >= '0' && *digit <= '9'){
			int flag = minus ? -1 : 1;
			num = num * 10 + flag * (*digit - '0');

			if ((!minus && num > 0x7FFFFFFF)
				|| (minus && num < (signed int)0x80000000)){
				// 检查溢出问题
				num = 0;
				break;
			}
			digit++;
		}
		else{
			num = 0;
			break;
		}
	}
	if (*digit == '\0')
		g_nStatus = kValid;

	return num;
}

int StrToInt(const char* str){
	g_nStatus = kInvalid;
	long long num = 0;

	if (str != NULL && *str != '\0'){
		bool minus = false;
		if (*str == '+')
			str++;
		else if (*str == '-'){
			str++;
			minus = true;
		}

		if (*str != '\0')
			num = StrToIntCore(str, minus);
	}
	return (int)num;
}

void Test(const char* str){
	if (str != NULL)
		cout << "Test string is " << str << endl;
	else
		cout << "Test for NULL string: ";
	int num = StrToInt(str);
	if (!g_nStatus)
		cout << "result num = " << num << endl;
	else
		cout << "wrong input\n";
}

// 测试
int main(void){
	char *str[] = { "123", "+23", "-25", "+", "12ab32", "", NULL };
	for (int i = 0; i < 7; i++)
		Test(str[i]);
	

	system("pause");
	return 0;
}