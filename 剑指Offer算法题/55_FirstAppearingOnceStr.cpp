#include<iostream>
#include<limits>
using std::numeric_limits;
using std::cout;
using std::endl;
using std::cin;

/*请实现一个函数用来找出字符流中的第一个只出现一次的字符 */
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
	// occurrence[i]: 一个ASCII值为i的字符
	// occurrence[i] = -1: 表示没有找到该字符
	// occurrence[i] = -2: 表示该字符出现多次 
	// occurrence[i] >= 0: 表示该字符仅出现一次
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

// 测试
int main(void){
	char* str[] = { "abcd","google","hellooleh" };
	for (int i = 0; i < 3; i++)
		Test(str[i]);
	

	system("pause");
	return 0;
}