#include<iostream>

using std::cout;
using std::endl;
using std::cin;

struct ListNode{
	int m_nValue;
	ListNode* m_pNext;
};

// 在O(1)时间内删除给定结点
void DeleteNode(ListNode** pListHead, ListNode* pToBeDeleted){
	if (!pListHead || !pToBeDeleted)
		return;
	if (pToBeDeleted->m_pNext != NULL){
		// 要删除的结点不是尾结点
		ListNode* pNext = pToBeDeleted->m_pNext;
		pToBeDeleted->m_nValue = pNext->m_nValue;
		pToBeDeleted->m_pNext = pNext->m_pNext;

		delete pNext;
		pNext = NULL;
	}
	else if (*pListHead == pToBeDeleted){
		// 链表只有一个结点，删除头结点，也就是尾结点
		delete pToBeDeleted;
		pToBeDeleted = NULL;
		*pListHead = NULL;
	}
	else{
		// 链表有多个结点，删除尾结点,采取从头开始遍历
		ListNode* pNode = *pListHead;
		while (pNode->m_pNext != pToBeDeleted){
			pNode = pNode->m_pNext;
		}
		pNode->m_pNext = NULL;
		delete pToBeDeleted;
		pToBeDeleted = NULL;
	}
}

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
// 输出链表
void printList(ListNode* pHead){
	ListNode* p = pHead;
	if (!p)
		cout << "List is empty!\n";
	while (p != NULL){
		cout << p->m_nValue;
		if (p->m_pNext == NULL)
			cout << "\n";
		else{
			cout << ", ";
		}
		p = p->m_pNext;
	}
}

// 测试
int main(void){
	ListNode* t = NULL;
	for (int i = 0; i < 10; i++)
		AddToTail(&t, i);
	cout << "List1:\n";
	printList(t);
	// 删除多个结点链表中的一个结点
	ListNode* pNode1 = t->m_pNext;
	DeleteNode(&t, pNode1);
	printList(t);
	// 删除多个结点链表中的头结点
	ListNode* pNode2 = t;
	DeleteNode(&t, pNode2);
	printList(t);
	// 删除多个结点链表中的尾结点
	ListNode* pNode3 = t;
	while (pNode3->m_pNext != NULL)
		pNode3 = pNode3->m_pNext;
	DeleteNode(&t, pNode3);
	printList(t);
	// 从只有一个结点的链表中删除唯一的结点
	ListNode* t2 = NULL;
	AddToTail(&t2, 2);
	cout << "List2:";
	printList(t2);
	DeleteNode(&t2, t2);
	printList(t2);
	// 指向链表头结点指针的是NULL指针
	DeleteNode(&t2, t2);
	// 指向要删除结点的是NULL指针
	pNode3 = NULL;
	DeleteNode(&t, pNode3);

	system("pause");
	return 0;
}