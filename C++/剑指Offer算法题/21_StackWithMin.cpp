#include<iostream>
#include<stack>
#include <assert.h>
using std::stack;
using std::cout;
using std::endl;
using std::cin;

/* ���һ��ջ�����ݽṹ���ڸ�ջ��ʵ��һ���ܹ��õ�ջ����СԪ�ص�min����������min,push��pop��ʱ�临�Ӷȶ���O(1) */
class StackWithMin{
public:
	StackWithMin(){}
	~StackWithMin(){}
	void push(const int value);
	void pop();
	const int min() const;
private:
	stack<int> m_data;
	stack<int> m_min;
};

void StackWithMin::push(const int value){
	m_data.push(value);
	if (m_min.size() == 0 || value < m_min.top())
		m_min.push(value);
	else
		m_min.push(m_min.top());
}

void StackWithMin::pop(){
	assert(m_data.size() > 0 && m_min.size() > 0);

	m_data.pop();
	m_min.pop();
}

const int StackWithMin::min() const{
	assert(m_data.size() > 0 && m_min.size() > 0);
	return m_min.top();
}

// ����
int main(void){
	StackWithMin stack1;
	int test[] = { 1, 4, 5 };
	for (int i = 0; i < 3; i++){
		stack1.push(test[i]);
	}
	cout << "current min_value = " << stack1.min() << endl;
	cout << "push numbers = " << 3 << ", ";
	stack1.push(3);
	cout << "current min_value = " << stack1.min() << endl;
	cout << "push numbers = " << 0 << ", ";
	stack1.push(0);
	cout << "current min_value = " << stack1.min() << endl;
	cout << "push numbers = " << 6 << ", ";
	stack1.push(6);
	cout << "current min_value = " << stack1.min() << endl;
	stack1.pop();
	cout << "pop a value, current min value = " << stack1.min() << endl;
	stack1.pop();
	cout << "pop a value, current min value = " << stack1.min() << endl;
	stack1.pop();
	cout << "pop a value, current min value = " << stack1.min() << endl;


	system("pause");
	return 0;
}