#include<iostream>

using std::cout;
using std::endl;
using std::cin;

struct ListNode{
	int m_nValue;
	ListNode* m_pNext;
};

// ��O(1)ʱ����ɾ���������
void DeleteNode(ListNode** pListHead, ListNode* pToBeDeleted){
	if (!pListHead || !pToBeDeleted)
		return;
	if (pToBeDeleted->m_pNext != NULL){
		// Ҫɾ���Ľ�㲻��β���
		ListNode* pNext = pToBeDeleted->m_pNext;
		pToBeDeleted->m_nValue = pNext->m_nValue;
		pToBeDeleted->m_pNext = pNext->m_pNext;

		delete pNext;
		pNext = NULL;
	}
	else if (*pListHead == pToBeDeleted){
		// ����ֻ��һ����㣬ɾ��ͷ��㣬Ҳ����β���
		delete pToBeDeleted;
		pToBeDeleted = NULL;
		*pListHead = NULL;
	}
	else{
		// �����ж����㣬ɾ��β���,��ȡ��ͷ��ʼ����
		ListNode* pNode = *pListHead;
		while (pNode->m_pNext != pToBeDeleted){
			pNode = pNode->m_pNext;
		}
		pNode->m_pNext = NULL;
		delete pToBeDeleted;
		pToBeDeleted = NULL;
	}
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
	// ɾ�������������е�һ�����
	ListNode* pNode1 = t->m_pNext;
	DeleteNode(&t, pNode1);
	printList(t);
	// ɾ�������������е�ͷ���
	ListNode* pNode2 = t;
	DeleteNode(&t, pNode2);
	printList(t);
	// ɾ�������������е�β���
	ListNode* pNode3 = t;
	while (pNode3->m_pNext != NULL)
		pNode3 = pNode3->m_pNext;
	DeleteNode(&t, pNode3);
	printList(t);
	// ��ֻ��һ������������ɾ��Ψһ�Ľ��
	ListNode* t2 = NULL;
	AddToTail(&t2, 2);
	cout << "List2:";
	printList(t2);
	DeleteNode(&t2, t2);
	printList(t2);
	// ָ������ͷ���ָ�����NULLָ��
	DeleteNode(&t2, t2);
	// ָ��Ҫɾ��������NULLָ��
	pNode3 = NULL;
	DeleteNode(&t, pNode3);

	system("pause");
	return 0;
}