#include<iostream>

using std::cout;
using std::endl;
using std::cin;

/*在一个排序的链表中，删除重复的结点 */
struct ListNode{
	int m_nValue;
	ListNode* m_pNext;
};


// 解法
void deleteDuplication(ListNode** pHead){
	if (pHead == NULL || *pHead == NULL)
		return;
	ListNode* pPreNode = NULL;
	ListNode* pNode = *pHead;
	while (pNode != NULL){
		ListNode* pNext = pNode->m_pNext;
		bool needDelete = false;
		if (pNext != NULL && pNext->m_nValue == pNode->m_nValue)
			needDelete = true;

		if (!needDelete){
			// 当前结点和下一个结点不相同
			pPreNode = pNode;
			pNode = pNode->m_pNext;
		}
		else{
			int value = pNode->m_nValue;
			ListNode* pToBeDel = pNode;
			while (pToBeDel != NULL && pToBeDel->m_nValue == value){
				// 删除重复的结点
				pNext = pToBeDel->m_pNext;
				delete pToBeDel;
				pToBeDel = NULL;

				pToBeDel = pNext;
			}
			if (pPreNode == NULL)
				// 头结点重复被删除
				*pHead = pNext;
			else
				pPreNode->m_pNext = pNext;
			pNode = pNext;
		}
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


void Test(ListNode* pHead){
	if (pHead){
		cout << "linklist: ";
		printList(pHead);
	}
	else{
		cout << "null linklist:\n";
	}
	deleteDuplication(&pHead);
	cout << "after delete: ";
	printList(pHead);
}

// 测试
int main(void){
	int a[] = { 1, 2, 3, 4, 5, 6 };
	ListNode* pHead = NULL;
	for (int i = 0; i < 6; i++)
		AddToTail(&pHead, a[i]);
	Test(pHead);

	int a2[] = { 1, 2, 3, 4, 4, 6 };
	ListNode* pHead2 = NULL;
	for (int i = 0; i < 6; i++)
		AddToTail(&pHead2, a2[i]);
	Test(pHead2);
	
	Test(NULL);

	system("pause");
	return 0;
}