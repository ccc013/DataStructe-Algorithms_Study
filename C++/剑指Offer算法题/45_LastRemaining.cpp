#include<iostream>
#include<list>
using std::list;
using std::cout;
using std::endl;
using std::cin;

/*0,1��...,n-1��n�������ų�һ��ԲȦ��������0��ʼ����ɾ����m�����֣���ʣ�µ����һ������*/

// �ⷨ1���û�������ģ��ԲȦ,ʱ�临�Ӷ���O(mn)
int LastRemaining(unsigned int n, unsigned int m){
	if (n < 1 || m < 1)
		return -1;
	unsigned int i = 0;
	// ʹ��ģ����е�listģ�⻷������
	list<int> numbers;
	for (i = 0; i < n; i++)
		numbers.push_back(i);
	list<int>::iterator current = numbers.begin();
	while (numbers.size() > 1){
		for (int i = 1; i < m; ++i){
			// �ҵ���m�����֣�����ҵ�ĩβ����Ҫ��ͷ��ʼ����
			current++;
			if (current == numbers.end())
				current = numbers.begin();
		}
		list<int>::iterator next = ++current;
		if (next == numbers.end())
			next = numbers.begin();
		--current;
		// ɾ������
		numbers.erase(current);
		current = next;
	}
	return *(current);
}

// �ⷨ2��ʱ�临�Ӷ���O(n)
int LastRemaining_2(unsigned int n, unsigned int m){
	if (n < 1 || m < 1)
		return -1;

	int last = 0;
	for (int i = 2; i <= n; i++)
		last = (last + m) % i;

	return last;
}

void Test(int numbers, int m){
	cout << "numbers = " << numbers << ", delete " << m << " values." << endl;
	cout << "Solution1: ";
	int resVal = LastRemaining(numbers, m);
	if (resVal > -1)
		cout << "the last remaining values = " << resVal << endl;
	else
		cout << "wrong input\n";

	cout << "Solution2: ";
	resVal = LastRemaining_2(numbers, m);
	if (resVal > -1)
		cout << "the last remaining values = " << resVal << endl;
	else
		cout << "wrong input\n";
}

// ����
int main(void){
	Test(5, 2);
	Test(5, 3);
	Test(6, 8);
	Test(0, 2);
	Test(3000, 1250);
	

	system("pause");
	return 0;
}