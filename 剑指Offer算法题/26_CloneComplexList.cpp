#include<iostream>

using std::cout;
using std::endl;
using std::cin;
struct ComplexListNode{
	int m_nValue;
	ComplexListNode* m_pNext;
	ComplexListNode* m_pSibling;
};

/*复杂链表的复制 */
void CloneNode(ComplexListNode* pHead){
	// 复制原始链表的任意结点N并创建新结点N'，再把N'链接到N的后面
	ComplexListNode* pNode = pHead;
	while (pNode != NULL){
		ComplexListNode* pCloned = new ComplexListNode();
		pCloned->m_nValue = pNode->m_nValue;
		pCloned->m_pNext = pNode->m_pNext;
		pCloned->m_pSibling = NULL;

		pNode->m_pNext = pCloned;
		pNode = pCloned->m_pNext;
	}
}
// 设置复制出来的结点的m_pSibling.
void ConnectSiblingNodes(ComplexListNode* pHead){
	ComplexListNode* pNode = pHead;
	while (pNode != NULL){
		ComplexListNode* pCloned = pNode->m_pNext;
		if (pNode->m_pSibling != NULL){
			pCloned->m_pSibling = pNode->m_pSibling->m_pNext;
		}
		pNode = pCloned->m_pNext;
	}
}
// 拆分长链表，奇数位置的就是原链表，而偶数位置的是复制得到的链表
ComplexListNode* ReconnectNodes(ComplexListNode* pHead){
	ComplexListNode* pNode = pHead;
	ComplexListNode* pClonedNode = NULL;
	ComplexListNode* pClonedHead = NULL;

	if (pNode != NULL){
		pClonedHead = pClonedNode = pNode->m_pNext;
		pNode->m_pNext = pClonedNode->m_pNext;
		pNode = pNode->m_pNext;
	}
	while(pNode != NULL){
		pClonedNode->m_pNext = pNode->m_pNext;
		pClonedNode = pClonedNode->m_pNext;
		pNode->m_pNext = pClonedNode->m_pNext;
		pNode = pNode->m_pNext;
	}
	return pClonedHead;
}
// 复制链表的完整过程
ComplexListNode* Clone(ComplexListNode* pHead){
	CloneNode(pHead);
	ConnectSiblingNodes(pHead);
	return ReconnectNodes(pHead);
}
// 在链表结尾插入一个结点
void AddToTail(ComplexListNode** pHead, int value){
	ComplexListNode* pNew = new ComplexListNode();
	pNew->m_nValue = value;
	pNew->m_pNext = NULL;

	if (*pHead == NULL){
		*pHead = pNew;
	}
	else
	{
		ComplexListNode* pNode = *pHead;

		while (pNode->m_pNext != NULL)
			pNode = pNode->m_pNext;

		pNode->m_pNext = pNew;
	}
}
// 输出链表
void printComplexList(ComplexListNode* pHead){
	ComplexListNode* p = pHead;
	if (!p)
		cout << "List is empty!\n";
	while (p != NULL){
		cout << p->m_nValue;
		if (p->m_pSibling != NULL)
			cout << "(m_pSlibing value=" << p->m_pSibling->m_nValue << ")";
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
	ComplexListNode* pHead = NULL;
	for (int i = 0; i < 5; i++)
		AddToTail(&pHead, i);
	ComplexListNode* pNode = pHead;
	while (pNode != NULL){		
		pNode->m_pSibling = pNode;
		pNode = pNode->m_pNext;
	}
	cout << "List1:";
	printComplexList(pHead);
	// 链表结点的m_pSibling 指向自身
	ComplexListNode* pClone = Clone(pHead);
	cout << "Clone List: ";
	printComplexList(pClone);
	// 普通的复杂链表
	ComplexListNode* pHead2 = NULL;
	for (int i = 0; i < 5; i++)
		AddToTail(&pHead2, i*i);

	ComplexListNode* pNode2 = pHead2;
	while (pNode2 != NULL){
		if (pNode2->m_pNext && pNode2->m_pNext->m_pNext)
			pNode2->m_pSibling = pNode2->m_pNext->m_pNext;
		else
			pNode2->m_pSibling = pHead2->m_pNext;
		pNode2 = pNode2->m_pNext;
	}
	cout << "\nList2:";
	printComplexList(pHead2);
	ComplexListNode* pClone2 = Clone(pHead2);
	cout << "Clone List2: ";
	printComplexList(pClone2);
	// 链表头结点的指针为NULL
	ComplexListNode* pClone3 = Clone(NULL);
	cout << "Clone null list: ";
	printComplexList(pClone3);
	// 链表中只有一个结点
	ComplexListNode* pHead3 = pHead2;
	pHead3->m_pNext = NULL;
	cout << "\nList3:";
	printComplexList(pHead3);
	ComplexListNode* pClone4 = Clone(pHead3);
	cout << "Clone List3: ";
	printComplexList(pClone4);

	system("pause");
	return 0;
}