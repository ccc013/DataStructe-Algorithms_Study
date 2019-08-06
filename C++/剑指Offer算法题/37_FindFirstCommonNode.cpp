#include<iostream>

using std::cout;
using std::endl;
using std::cin;

/*�������������ҳ����ǵĵ�һ��������㡣 */
struct ListNode{
	int m_nValue;
	ListNode* m_pNext;
};
// �ⷨ
// ��ȡ������
unsigned int GetListLength(ListNode* pHead){
	unsigned int nLength = 0;
	ListNode* pNode = pHead;
	while (!pNode){
		++nLength;
		pNode = pNode->m_pNext;
	}
	return nLength;
}
ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2){
	// �õ���������ĳ���
	unsigned int nLength1 = GetListLength(pHead1);
	unsigned int nLength2 = GetListLength(pHead2);

	int nLengthDif = nLength1 - nLength2;
	ListNode* pListHeadLong = pHead1;
	ListNode* pListHeadShort = pHead2;
	if (nLength2 > nLength1){
		pListHeadLong = pHead2;
		pListHeadShort = pHead1;
		nLengthDif = nLength2 - nLength1;
	}
	// ���ڳ��������߼���
	for (int i = 0; i < nLengthDif; ++i){
		pListHeadLong = pListHeadLong->m_pNext;
	}
	// ��ʼ��������Ѱ�ҹ������
	while (pListHeadLong != NULL && pListHeadShort != NULL && pListHeadLong != pListHeadShort){
		pListHeadLong = pListHeadLong->m_pNext;
		pListHeadShort = pListHeadShort->m_pNext;
	}
	ListNode* pFirstCommonNode = pListHeadLong;
	return pFirstCommonNode;
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

void Test(ListNode* pHead1, ListNode* pHead2){
	cout << "Test list1: ";
	printList(pHead1);
	cout << "Test list2: ";
	printList(pHead2);
	if (pHead1 == NULL || pHead2 == NULL)
		return;
	cout << "common node value = ";
	ListNode* pCommonNode = FindFirstCommonNode(pHead1, pHead2);
	cout << pCommonNode->m_nValue << endl;
}

// ����
int main(void){
	int t1[] = { 1, 3, 5, 7, 8, 9 };
	int t2[] = { 2, 4, 5, 10, 11 };
	int t3[] = { 2, 4, 9 };
	int t4[] = { 12, 14, 18, 20 };
	ListNode* p1 = NULL;
	for (int i = 0; i < 6; i++)
		AddToTail(&p1, t1[i]);
	ListNode* p2 = NULL;
	for (int i = 0; i < 5; i++)
		AddToTail(&p2, t2[i]);
	// ���Ե����������й�����㣬��һ����������м�
	Test(p1, p2);

	ListNode* p3 = NULL;
	for (int i = 0; i < 3; i++)
		AddToTail(&p3, t3[i]);
	// ���Ե����������й�����㣬��һ��������Ľ�β
	Test(p1, p3);

	ListNode* p4 = NULL;
	for (int i = 0; i < 4; i++)
		AddToTail(&p4, t4[i]);
	// ���Ե���������û�й������
	Test(p1, p4);
	// ���������ͷ�����NULL
	Test(p1, NULL);


	system("pause");
	return 0;
}