#include<iostream>

using std::cout;
using std::endl;
using std::cin;

/*��ʵ��һ�����������ж��ַ����Ƿ��ʾ��ֵ������������С������ */

// ɨ���ַ����е�0��9����λ
void scanDigits(char** string){
	while (**string != '\0' && **string >= '0' && **string <= '9')
		++(*string);
}
// ����ƥ���ÿ�ѧ��������ʾ����ֵ�Ľ�β����
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
// �ⷨ
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
		// ����С��
		if (*string == '.'){
			++string;
			scanDigits(&string);
			if (*string == 'e' || *string == 'E')
				numeric = isExponential(&string);
		}
		else if (*string == 'e' || *string == 'E')
			// ����ʹ���˿�ѧ������
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

// ����
int main(void){
	char* str[] = { "123", "-124", "+12.56", "-1e2", "12E-5", "1.2e5", "1a3.14","1.2.3", "+-5", "12e" };
	for (int i = 0; i < 10; i++)
		Test(str[i]);
	

	system("pause");
	return 0;
}