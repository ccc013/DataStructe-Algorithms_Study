#include<iostream>
#include<stack>
using std::cout;
using std::endl;
using std::cin;

struct ListNode{
	int m_nValue;
	ListNode* m_pNext;
};

// 在链表结尾插入一个结点
void AddToTail(ListNode** pHead, int value){
	ListNode* pNew = new ListNode();
	pNew->m_nValue = value;
	pNew->m_pNext = NULL;

	if (*pHead == NULL){
		*pHead = pNew;
	}
	else
	{
		ListNode* pNode = *pHead;

		while (pNode->m_pNext != NULL)
			pNode = pNode->m_pNext;

		pNode->m_pNext = pNew;
	}
}
// 删除给定数值的结点
void RemoveNode(ListNode** pHead, int value){
	if (pHead == NULL || *pHead == NULL)
		return;
	ListNode* pToBeDeleted = NULL;
	if ((*pHead)->m_nValue == value){
		pToBeDeleted = *pHead;
		*pHead = (*pHead)->m_pNext;
	}
	else{
		ListNode* pNode = *pHead;
		while (pNode->m_pNext != NULL && pNode->m_pNext->m_nValue != value)
			pNode = pNode->m_pNext;

		if (pNode->m_pNext != NULL && pNode->m_pNext->m_nValue == value){
			pToBeDeleted = pNode->m_pNext;
			pNode->m_pNext = pNode->m_pNext->m_pNext;
		}
	}
	if (pToBeDeleted != NULL){
		delete pToBeDeleted;
		pToBeDeleted = NULL;
	}
}
// 从尾到头打印链表，迭代输出
void PrintListReversingly_Iteratively(ListNode* pHead){
	std::stack<ListNode*> nodes;
	ListNode* pNode = pHead;
	while (pNode != NULL){
		nodes.push(pNode);
		pNode = pNode->m_pNext;
	}
	while (!nodes.empty()){
		pNode = nodes.top();
		cout<<pNode->m_nValue<<" ";
		nodes.pop();
	}
	cout << endl;
}
// 递归版本
void PrintListReversingly_Recursively(ListNode* pHead){
	if (pHead != NULL){
		if (pHead->m_pNext != NULL){
			PrintListReversingly_Recursively(pHead->m_pNext);
		}
		cout << pHead->m_nValue << " ";
	}
}

// 测试
int main(void){
	ListNode* t = NULL;
	for (int i = 0; i < 10;i++)
		AddToTail(&t, i);
	RemoveNode(&t, 8);
	ListNode* p = t;
	while (p != NULL){
		cout << p->m_nValue;
		if (p->m_pNext == NULL)
			cout << "\n";
		else{
			cout << ", ";	
		}
		p = p->m_pNext;
	}
	// 输入的链表有多个结点
	PrintListReversingly_Iteratively(t);
	PrintListReversingly_Recursively(t);
	cout << endl;
	// 输入的链表只有1个结点
	ListNode*p2 = NULL;
	AddToTail(&p2, 5);
	PrintListReversingly_Iteratively(p2);
	PrintListReversingly_Recursively(p2);
	cout << endl;
	// 输入的链表头结点指针是NULL
	ListNode* p3 = NULL;
	PrintListReversingly_Iteratively(p3);
	PrintListReversingly_Recursively(p3);
	cout << endl;

	system("pause");
	return 0;
}

