#include<iostream>

using std::cout;
using std::endl;
using std::cin;

/*��ʵ��һ����������ƥ�����'.' �� '*' ��������ʽ��ģʽ�е��ַ� '.' ��ʾ����һ���ַ�����'*' ��ʾ��ǰ����ַ����Գ��������������0�Σ��� */

bool matchCore(char* str, char* pattern){
	if (*str == '\0' && *pattern == '\0')
		return true;
	if (*str != '\0' && *pattern == '\0')
		return false;
	if (*(pattern + 1) == '*'){
		// ƥ�䵽'*'�����
		if (*pattern == *str || (*pattern == '.' && *str != '\0'))
			// ������һ��״̬
			return matchCore(str + 1, pattern + 2)
			// ����ģʽ����
			|| matchCore(str + 1, pattern)
			// ���� '*'
			|| matchCore(str, pattern + 2);
		else
			// �ַ�����ǰֵ��ģʽֵ���ȵ���������� '*'
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

// ����
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