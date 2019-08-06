#include<iostream>

using std::cout;
using std::endl;
using std::cin;

/*һ�������а����������ҳ�������ڽ�� */
struct ListNode{
	int m_nValue;
	ListNode* m_pNext;
};

// �������д��ڻ���ǰ�����ҵ�����ָ�������Ľ��
ListNode* MeetingNodes(ListNode* pHead){
	if (pHead == NULL)
		return NULL;
	ListNode *pSlow = pHead->m_pNext;
	if (pSlow == NULL)
		return false;
	ListNode* pFast = pSlow->m_pNext;
	while (pFast != NULL && pSlow != NULL){
		if (pFast == pSlow)
			return pFast;
		pSlow = pSlow->m_pNext;
		pFast = pFast->m_pNext;
		if (pFast != NULL)
			pFast = pFast->m_pNext;
	}
	return NULL;
}
// �ⷨ
ListNode* EntryNodeOfLoop(ListNode* pHead){
	ListNode* meetingNode = MeetingNodes(pHead);
	if (meetingNode == NULL)
		return NULL;
	// ��ȡ���н�������
	int nodesInLoop = 1;
	ListNode* pNode1 = meetingNode;
	while (pNode1->m_pNext != meetingNode){
		pNode1 = pNode1->m_pNext;
		++nodesInLoop;
	}
	// �Ƚ�һ��ָ���ƶ�n����n�ǻ��н�������
	pNode1 = pHead;
	for (int i = 0; i < nodesInLoop; ++i)
		pNode1 = pNode1->m_pNext;
	// ��ͬʱ�ƶ�����ָ�룬������ָ����ȵ�ʱ����ҵ���ڽ��
	ListNode* pNode2 = pHead;
	while (pNode1 != pNode2){
		pNode1 = pNode1->m_pNext;
		pNode2 = pNode2->m_pNext;
	}
	return pNode1;
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


void Test(ListNode* pHead){
	
	ListNode* pNode = EntryNodeOfLoop(pHead);
	if (pNode != NULL){
		cout << "Entry node of loop : " << pNode->m_nValue << endl;
	}
	else{
		cout << "no loop in link list.\n";
	}

}

// ����
int main(void){
	int a[] = { 1, 2, 3, 4, 5, 6 };
	ListNode* pHead = NULL;
	for (int i = 0; i < 6; i++)
		AddToTail(&pHead, a[i]);
	Test(pHead);

	ListNode* pHead2 = NULL;
	pHead2 = pHead->m_pNext->m_pNext;
	ListNode* pNode = pHead;
	while (pNode->m_pNext != NULL){
		pNode = pNode->m_pNext;
	}
	pNode->m_pNext = pHead2;
	Test(pHead);
	

	system("pause");
	return 0;
}