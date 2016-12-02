#include<iostream>
#include<stack>
#include <assert.h>
using std::stack;
using std::cout;
using std::endl;
using std::cin;

/* 输入两个整数序列，一个是栈的输入序列，判断第二个序列是否是栈的弹出顺序 */
bool isPopOrder(const int* pPush, const int* pPop, int length){
	bool bPossible = false;
	if (pPush != NULL && pPop != NULL && length > 0){
		const int* pNextPush = pPush;
		const int* pNextPop = pPop;

		stack<int> stackData;
		while (pNextPop - pPop < length){
			while (stackData.empty() || stackData.top() != *pNextPop){
				if (pNextPush - pPush == length)
					break;
				stackData.push(*pNextPush);
				pNextPush++;
			}
			if (stackData.top() != *pNextPop)
				break;
			stackData.pop();
			pNextPop++;
		}
		if (stackData.empty() && pNextPop - pPop == length)
			bPossible = true;
	}
	return bPossible;
}
// 测试
int main(void){
	int push[] = { 1, 2, 3, 4, 5 };
	int pop1[] = { 4, 5, 3, 2, 1 };
	int pop2[] = { 4, 3, 5, 1, 2 };
	if (isPopOrder(push, pop1, 5))
		cout << "pop1 is popOrder\n";
	else
		cout << "pop2 isn't popOrder\n";

	if (isPopOrder(NULL, NULL, 5))
		cout << "pop1 is popOrder\n";
	else
		cout << "pop2 isn't popOrder\n";
	


	system("pause");
	return 0;
}