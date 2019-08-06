#include<iostream>

using std::cout;
using std::endl;
using std::cin;

/*请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。 */

// 扫描字符串中的0到9的数位
void scanDigits(char** string){
	while (**string != '\0' && **string >= '0' && **string <= '9')
		++(*string);
}
// 用于匹配用科学计数法表示的数值的结尾部分
bool isExponential(char **string){
	if (**string != 'e' && **string != 'E')
		return false;
	++(*string);
	if (**string == '+' || **string == '-')
		++(*string);
	if (**string == '\0')
		return false;
	scanDigits(string);
	return (**string == '\0') ? true : false;
}
// 解法
bool isNumeric(char* string){
	if (string == NULL)
		return false;
	if (*string == '+' || *string == '-')
		++string;
	if (*string == '\0')
		return false;
	bool numeric = true;
	scanDigits(&string);
	if (*string != '\0'){
		// 对于小数
		if (*string == '.'){
			++string;
			scanDigits(&string);
			if (*string == 'e' || *string == 'E')
				numeric = isExponential(&string);
		}
		else if (*string == 'e' || *string == 'E')
			// 整数使用了科学计数法
			numeric = isExponential(&string);
		else
			numeric = false;
	}
	return numeric && *string == '\0';
}

void Test(char* str){
	if (str){
		cout << "string: " << str;
	}
	else{
		cout << "Test null string or pattern: ";
	}
	if (isNumeric(str)){
		cout << " is numeric.\n";
	}
	else{
		cout << " isn't numeric.\n";
	}
}

// 测试
int main(void){
	char* str[] = { "123", "-124", "+12.56", "-1e2", "12E-5", "1.2e5", "1a3.14","1.2.3", "+-5", "12e" };
	for (int i = 0; i < 10; i++)
		Test(str[i]);
	

	system("pause");
	return 0;
}