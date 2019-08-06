#include<iostream>

using std::cout;
using std::endl;
using std::cin;

struct ListNode{
	int m_nValue;
	ListNode* m_pNext;
};

// Ѱ������ĵ�����k�����
ListNode* FindKthToTail(ListNode* pListHead, unsigned int k){
	if (pListHead == NULL || k == 0)
		return NULL;
	ListNode *pAhead = pListHead;
	ListNode *pBehind = NULL;
	// ��һ��ָ������ k-1��
	for (unsigned int i = 0; i < k - 1; ++i){
		if (pAhead->m_pNext != NULL)
			pAhead = pAhead->m_pNext;
		else
			// ����Ľ��������k��
			return NULL;
	}
	pBehind = pListHead;
	while (pAhead->m_pNext != NULL){
		pAhead = pAhead->m_pNext;
		pBehind = pBehind->m_pNext;
	}
	return pBehind;
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
// ���������м���
ListNode* getMiddelNode(ListNode* pListHead){
	if (pListHead == NULL)
		return NULL;
	ListNode *pAhead = pListHead;
	ListNode *pBehind = pListHead;
	while (pAhead && pAhead->m_pNext != NULL){
		pAhead = pAhead->m_pNext->m_pNext;
		pBehind = pBehind->m_pNext;
	}
	return pBehind;
}
// �ж������Ƿ��л�
bool hasCycle(ListNode *pListHead) {
	ListNode *fast = pListHead;
	ListNode *slow = pListHead;

	while (fast && fast->m_pNext){
		slow = slow->m_pNext;
		fast = fast->m_pNext->m_pNext;
		if (fast == slow)
			// there is a cycle in the linked list
			return true;
	}
	return false;
}

// ����
int main(void){
	ListNode* t = NULL;
	for (int i = 0; i < 10; i++)
		AddToTail(&t, i);
	cout << "List1:\n";
	printList(t);
	int testK[] = { 5, 10, 1 };
	for (int i = 0; i < 3; i++){
		ListNode *rNode = FindKthToTail(t, testK[i]);
		cout << "Find the last " << testK[i] << " value: " << rNode->m_nValue << endl;
	}
	
	// �����������
	ListNode *tNull = NULL;
	ListNode *r = FindKthToTail(tNull, 2);
	printList(r);
	// k=0
	r = FindKthToTail(t, 0);
	printList(r);
	// ������������k
	r = FindKthToTail(t, 12);
	printList(r);
	
	cout << "get the middle value = ";
	ListNode* pMiddle = getMiddelNode(t);
	cout << pMiddle->m_nValue << endl;
	ListNode* t2 = NULL;
	for (int i = 0; i < 5; i++)
		AddToTail(&t2, i);
	cout << "List2:\n";
	printList(t2);
	cout << "get the middle value = ";
	pMiddle = getMiddelNode(t2);
	cout << pMiddle->m_nValue << endl;

	system("pause");
	return 0;
}