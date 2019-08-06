#include<iostream>

using std::cout;
using std::endl;
using std::cin;

/*请实现一个函数用来匹配包含'.' 和 '*' 的正则表达式。模式中的字符 '.' 表示任意一个字符，而'*' 表示它前面的字符可以出现任意次数（含0次）。 */

bool matchCore(char* str, char* pattern){
	if (*str == '\0' && *pattern == '\0')
		return true;
	if (*str != '\0' && *pattern == '\0')
		return false;
	if (*(pattern + 1) == '*'){
		// 匹配到'*'的情况
		if (*pattern == *str || (*pattern == '.' && *str != '\0'))
			// 跳到下一个状态
			return matchCore(str + 1, pattern + 2)
			// 保持模式不变
			|| matchCore(str + 1, pattern)
			// 忽略 '*'
			|| matchCore(str, pattern + 2);
		else
			// 字符串当前值与模式值不等的情况，忽略 '*'
			return matchCore(str, pattern + 2);
	}
	if (*str == *pattern || (*pattern == '.' && *str != '\0'))
		return matchCore(str + 1, pattern + 1);

	return false;
}

bool match(char* str, char* pattern){
	if (str == NULL || pattern == NULL)
		return false;
	return matchCore(str, pattern);
}

void Test(char* str, char* pattern){
	if (str && pattern){
		cout << "string: " << str << ", pattern: " << pattern << endl;
	}
	else{
		cout << "Test null string or pattern: ";
	}
	if (match(str, pattern))
		cout << "Match!" << endl;
	else
		cout << "Don't match." << endl;
}

// 测试
int main(void){
	char *str[] = { "aba", "accad" };
	char *pa[] = { "a.a", "ab*a", "ac*ad" };
	Test(str[0], pa[0]);
	Test(str[0], pa[1]);
	Test(str[1], pa[0]);
	Test(str[1], pa[1]);
	Test(str[1], pa[2]);
	Test(NULL, pa[0]);
	Test(str[1], NULL);
	Test(NULL, NULL);
	

	system("pause");
	return 0;
}