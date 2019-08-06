#include<iostream>

using std::cout;
using std::endl;
using std::cin;
struct ComplexListNode{
	int m_nValue;
	ComplexListNode* m_pNext;
	ComplexListNode* m_pSibling;
};

/*��������ĸ��� */
void CloneNode(ComplexListNode* pHead){
	// ����ԭʼ�����������N�������½��N'���ٰ�N'���ӵ�N�ĺ���
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
// ���ø��Ƴ����Ľ���m_pSibling.
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
// ��ֳ���������λ�õľ���ԭ������ż��λ�õ��Ǹ��Ƶõ�������
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
// �����������������
ComplexListNode* Clone(ComplexListNode* pHead){
	CloneNode(pHead);
	ConnectSiblingNodes(pHead);
	return ReconnectNodes(pHead);
}
// �������β����һ�����
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
// �������
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

// ����
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
	// �������m_pSibling ָ������
	ComplexListNode* pClone = Clone(pHead);
	cout << "Clone List: ";
	printComplexList(pClone);
	// ��ͨ�ĸ�������
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
	// ����ͷ����ָ��ΪNULL
	ComplexListNode* pClone3 = Clone(NULL);
	cout << "Clone null list: ";
	printComplexList(pClone3);
	// ������ֻ��һ�����
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