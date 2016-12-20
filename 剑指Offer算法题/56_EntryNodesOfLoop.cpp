#include<iostream>

using std::cout;
using std::endl;
using std::cin;

/*一个链表中包含环，请找出环的入口结点 */
struct ListNode{
	int m_nValue;
	ListNode* m_pNext;
};

// 在链表中存在环的前提下找到快慢指针相遇的结点
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
// 解法
ListNode* EntryNodeOfLoop(ListNode* pHead){
	ListNode* meetingNode = MeetingNodes(pHead);
	if (meetingNode == NULL)
		return NULL;
	// 获取环中结点的数量
	int nodesInLoop = 1;
	ListNode* pNode1 = meetingNode;
	while (pNode1->m_pNext != meetingNode){
		pNode1 = pNode1->m_pNext;
		++nodesInLoop;
	}
	// 先将一个指针移动n步，n是环中结点的数量
	pNode1 = pHead;
	for (int i = 0; i < nodesInLoop; ++i)
		pNode1 = pNode1->m_pNext;
	// 再同时移动两个指针，当两个指针相等的时候就找到入口结点
	ListNode* pNode2 = pHead;
	while (pNode1 != pNode2){
		pNode1 = pNode1->m_pNext;
		pNode2 = pNode2->m_pNext;
	}
	return pNode1;
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
	
	ListNode* pNode = EntryNodeOfLoop(pHead);
	if (pNode != NULL){
		cout << "Entry node of loop : " << pNode->m_nValue << endl;
	}
	else{
		cout << "no loop in link list.\n";
	}

}

// 测试
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