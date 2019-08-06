#include<iostream>

using std::cout;
using std::endl;
using std::cin;

struct ListNode{
	int m_nValue;
	ListNode* m_pNext;
};

// 合并两个有序的链表,递归版本
ListNode* Merge_recursively(ListNode* pHead1, ListNode* pHead2){
	if (pHead1 == NULL)
		return pHead2;
	else if (pHead2 == NULL)
		return pHead1;

	ListNode* pMergeHead = NULL;
	if (pHead1->m_nValue < pHead2->m_nValue){
		pMergeHead = pHead1;
		pMergeHead->m_pNext = Merge_recursively(pHead1->m_pNext, pHead2);
	}
	else{
		pMergeHead = pHead2;
		pMergeHead->m_pNext = Merge_recursively(pHead1, pHead2->m_pNext);
	}
	return pMergeHead;
}
// 迭代版本
ListNode* Merge(ListNode* l1, ListNode* l2) {
	if (!l1)
		return l2;
	else if (!l2)
		return l1;
	ListNode *tmp = new ListNode();
	tmp->m_pNext = NULL;
	ListNode *head = tmp;
	while (l1 || l2){
		if (l1 == NULL){
			tmp->m_pNext = l2;
			break;
		}
		else if (l2 == NULL){
			tmp->m_pNext = l1;
			break;
		}
		else if (l1->m_nValue < l2->m_nValue){
			tmp->m_pNext = new ListNode();
			tmp->m_pNext->m_nValue = l1->m_nValue;
			tmp = tmp->m_pNext;
			l1 = l1->m_pNext;
		}
		else{
			tmp->m_pNext = new ListNode();
			tmp->m_pNext->m_nValue = l2->m_nValue;
			tmp = tmp->m_pNext;
			l2 = l2->m_pNext;
		}
	}
	return head->m_pNext;
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
	ListNode* t2 = NULL;	
	int a[] = {  2,  4, 6, 8, 10 };
	int a2[] = { 0, 1, 3, 5, 7 };
	for (int i = 0; i < 5; i++){
		AddToTail(&t, a[i]);
		AddToTail(&t2, a2[i]);
	}	
	cout << "List1:\n";
	printList(t);
	cout << "List2:\n";
	printList(t2);
	//ListNode* pMerge = Merge_recursively(t, t2);
	//printList(pMerge);
	ListNode* pMerge2 = Merge(t, t2);
	printList(pMerge2);

	// 一个结点的链表
	ListNode* t3 = NULL;
	AddToTail(&t3, 2);
	ListNode* pMerge3 = Merge(t3, NULL);//Merge_recursively(t3, NULL);
	printList(pMerge3);
	

	// 特殊输入测试
	ListNode *pMerge4 = Merge_recursively(NULL,NULL);//Merge(NULL,NULL);
	printList(pMerge4);

	system("pause");
	return 0;
}