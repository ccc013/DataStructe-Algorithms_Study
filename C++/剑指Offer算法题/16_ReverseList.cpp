#include<iostream>

using std::cout;
using std::endl;
using std::cin;

struct ListNode{
	int m_nValue;
	ListNode* m_pNext;
};

// ��ת����
ListNode* ReverseList(ListNode* pHead){
	ListNode* pReverseHead = NULL;
	ListNode* pNode = pHead;
	ListNode* pPrev = NULL;
	while (pNode != NULL){
		ListNode* pNext = pNode->m_pNext;
		if (pNext == NULL)
			pReverseHead = pNode;

		pNode->m_pNext = pPrev;
		pPrev = pNode;
		pNode = pNext;
	}
	return pReverseHead;
}
// �ݹ�汾
ListNode* ReverseList_recursively(ListNode* pHead) {
	if (!pHead || !(pHead->m_pNext)) return pHead;
	ListNode* pNode = ReverseList_recursively(pHead->m_pNext);
	pHead->m_pNext->m_pNext = pHead;
	pHead->m_pNext = NULL;
	return pNode;
}
// �������β����һ�����
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
// �������
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

// ����
int main(void){
	ListNode* t = NULL;
	for (int i = 0; i < 10; i++)
		AddToTail(&t, i);
	cout << "List1:\n";
	printList(t);
	cout << "reverse List1: ";
	t = ReverseList(t);
	printList(t);
	cout << "reverse List1 againly:";
	t = ReverseList_recursively(t);
	printList(t);

	// һ����������
	ListNode* t1 = NULL;
	AddToTail(&t1, 3);
	cout << "List2:\n";
	printList(t1);
	cout << "reverse List2: ";
	t1 = ReverseList(t1);
	printList(t1);
	cout << "reverse List2 againly:";
	t1 = ReverseList_recursively(t1);
	printList(t1);

	// �����������
	ListNode *tNull = NULL;
	tNull = ReverseList(tNull);
	printList(tNull);
	tNull = ReverseList_recursively(tNull);
	printList(tNull);
	

	system("pause");
	return 0;
}