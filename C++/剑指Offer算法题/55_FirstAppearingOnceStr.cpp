#include<iostream>
#include<limits>
using std::numeric_limits;
using std::cout;
using std::endl;
using std::cin;

/*��ʵ��һ�����������ҳ��ַ����еĵ�һ��ֻ����һ�ε��ַ� */
class CharStatistics{
public:
	CharStatistics() : index(0){
		for (int i = 0; i < 256; ++i)
			occurrence[i] = -1;
	}
	void Insert(char ch){
		if (occurrence[ch] == -1)
			occurrence[ch] = index;
		else if (occurrence[ch] >= 0)
			occurrence[ch] = -2;
		++index;
	}
	char FirstAppearingOnce(){
		char ch = '\0';
		int minIndex = numeric_limits<int>::max();
		for (int i = 0; i < 256; ++i){
			if (occurrence[i] >= 0 && occurrence[i] < minIndex){
				ch = (char)i;
				minIndex = occurrence[i];
			}
		}
		return ch;
	}
private:
	// occurrence[i]: һ��ASCIIֵΪi���ַ�
	// occurrence[i] = -1: ��ʾû���ҵ����ַ�
	// occurrence[i] = -2: ��ʾ���ַ����ֶ�� 
	// occurrence[i] >= 0: ��ʾ���ַ�������һ��
	int occurrence[256];
	int index;
};

void Test(char* str){
	if (str){
		cout << "string: " << str << endl;
	}
	else{
		cout << "Test null string or pattern: ";
	}
	CharStatistics cs;
	while (*str != '\0'){
		cs.Insert(*str);
		str++;
	}
	char res = cs.FirstAppearingOnce();
	if (res != '\0')
		cout << "first appear once char is " << res << endl;
	else
		cout << "no appear once char" << endl;
}

// ����
int main(void){
	char* str[] = { "abcd","google","hellooleh" };
	for (int i = 0; i < 3; i++)
		Test(str[i]);
	

	system("pause");
	return 0;
}