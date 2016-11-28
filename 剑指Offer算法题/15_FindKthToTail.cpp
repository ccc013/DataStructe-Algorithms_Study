#include<iostream>

using std::cout;
using std::endl;
using std::cin;

struct ListNode{
	int m_nValue;
	ListNode* m_pNext;
};

// 寻找链表的倒数第k个结点
ListNode* FindKthToTail(ListNode* pListHead, unsigned int k){
	if (pListHead == NULL || k == 0)
		return NULL;
	ListNode *pAhead = pListHead;
	ListNode *pBehind = NULL;
	// 第一个指针先走 k-1步
	for (unsigned int i = 0; i < k - 1; ++i){
		if (pAhead->m_pNext != NULL)
			pAhead = pAhead->m_pNext;
		else
			// 链表的结点数少于k个
			return NULL;
	}
	pBehind = pListHead;
	while (pAhead->m_pNext != NULL){
		pAhead = pAhead->m_pNext;
		pBehind = pBehind->m_pNext;
	}
	return pBehind;
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
// 返回链表中间数
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
// 判断链表是否有环
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

// 测试
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
	
	// 特殊输入测试
	ListNode *tNull = NULL;
	ListNode *r = FindKthToTail(tNull, 2);
	printList(r);
	// k=0
	r = FindKthToTail(t, 0);
	printList(r);
	// 链表总数少于k
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