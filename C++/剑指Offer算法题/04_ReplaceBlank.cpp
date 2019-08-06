#include<iostream>
using std::cout;
using std::endl;
using std::cin;

// �滻�ո�,length���ַ�����string��������
void ReplaceBlank(char string[], int length){
	if (string == NULL || length <= 0){
		return;
	}
	// �ַ���string��ʵ�ʳ���
	int originLength = 0;
	int numberOfBlank = 0;
	int i = 0;
	// ͳ�ƿո���������ַ�������
	while (string[i] != '\0'){
		++originLength;
		if (string[i] == ' ')
			++numberOfBlank;
		++i;
	}
	// �滻�ո����ַ����³���
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

// ����
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
	// �ո�λ���ַ�������ǰ��
	cout << "origin: " << str;
	ReplaceBlank(str, 10);
	cout << ",--> " << str << endl;
	// �ո�λ���ַ����������
	cout << "origin: " << str2;
	ReplaceBlank(str2, 10);
	cout << ",--> " << str2 << endl;
	// �ո�λ���ַ������м�
	cout << "origin: " << str3;
	ReplaceBlank(str3, 10);
	cout << ",--> " << str3 << endl;
	// �ַ������ж�������ո�
	cout << "origin: " << str4;
	ReplaceBlank(str4, 30);
	cout << ",--> " << str4 << endl;
	// ������ַ���û�пո�
	cout << "origin: " << str5;
	ReplaceBlank(str5, 30);
	cout << ",--> " << str5 << endl;
	// �ַ����ǿ�ָ��
	//	cout << "origin: " << str6;
	ReplaceBlank(str6, 10);
	//	cout << ",--> " << str6 << endl;
	// �ַ����ǿ��ַ���
	cout << "origin: " << str7;
	ReplaceBlank(str7, 10);
	cout << ",--> " << str7 << endl;
	// �ַ���ֻ��һ���ո��ַ�
	cout << "origin: " << str8;
	ReplaceBlank(str8, 10);
	cout << ",--> " << str8 << endl;
	// �ַ�����ֻ�ж�������ո�
	cout << "origin: " << str9;
	ReplaceBlank(str9, 20);
	cout << ",--> " << str9 << endl;

	system("pause");
	return 0;
}