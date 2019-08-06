#include<iostream>
#include<queue>
using std::deque;
using std::cout;
using std::endl;
using std::cin;
struct BinaryTreeNode{
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};

/*����һ�ö��������������ö���������ת����һ�������˫������Ҫ���ܴ����µĽ�㣬ֻ�ܵ������н��ָ���ָ�� */
void ConvertNode(BinaryTreeNode* pNode, BinaryTreeNode** pLastNodeInList);
BinaryTreeNode* Convert(BinaryTreeNode* pRootOfTree){
	BinaryTreeNode* pLastNodeInList = NULL;
	ConvertNode(pRootOfTree, &pLastNodeInList);
	// pLastNodeInList ָ��˫�������β��㣬��Ҫ����ͷ���
	BinaryTreeNode* pHeadOfList = pLastNodeInList;
	while (pHeadOfList != NULL && pHeadOfList->m_pLeft != NULL)
		pHeadOfList = pHeadOfList->m_pLeft;

	return pHeadOfList;
}

void ConvertNode(BinaryTreeNode* pNode, BinaryTreeNode** pLastNodeInList){
	if (pNode == NULL)
		return;
	BinaryTreeNode* pCurrent = pNode;
	// ת��������
	if (pCurrent->m_pLeft != NULL)
		ConvertNode(pCurrent->m_pLeft, pLastNodeInList);
	// m_pLeft ��Ϊת���������ǰ��ָ�룬m_pRight ��Ϊָ���̵�ָ��
	pCurrent->m_pLeft = *pLastNodeInList;
	if (*pLastNodeInList != NULL)
		(*pLastNodeInList)->m_pRight = pCurrent;
	// ת��������
	*pLastNodeInList = pCurrent;
	if (pCurrent->m_pRight != NULL)
		ConvertNode(pCurrent->m_pRight, pLastNodeInList);
}
// ��α�������������
BinaryTreeNode* constructTree(BinaryTreeNode* pTreeRoot, int a[], int length){
	if (length <= 0){
		cout << "Invalid Array input!\n";
		return pTreeRoot;
	}
	deque<BinaryTreeNode*> dequeTreeNode;
	if (pTreeRoot == NULL)
		pTreeRoot = new BinaryTreeNode();
	//pTreeRoot->m_nValue = a[0];
	BinaryTreeNode* pNode = new BinaryTreeNode();
	pNode = pTreeRoot;
	pTreeRoot->m_nValue = a[0];
	dequeTreeNode.push_back(pNode);
	int i = 1;
	while (dequeTreeNode.size() >0){
		pNode = dequeTreeNode.front();
		dequeTreeNode.pop_front();
		if (pNode->m_pLeft == NULL){
			BinaryTreeNode* pLeft = new BinaryTreeNode();
			pLeft->m_nValue = a[i];
			pNode->m_pLeft = pLeft;
			dequeTreeNode.push_back(pLeft);
			i++;
			if (i == length)
				break;
		}
		if (pNode->m_pRight == NULL){
			BinaryTreeNode* pRight = new BinaryTreeNode();
			pRight->m_nValue = a[i];
			pNode->m_pRight = pRight;
			dequeTreeNode.push_back(pRight);
			i++;
			if (i == length)
				break;
		}
	}
	return pTreeRoot;
}
// ���ת���������
void printConvertedTree(BinaryTreeNode* pHead){
	if (pHead == NULL){
		cout << "List is empty.\n";
		return;
	}
	BinaryTreeNode* pNode = pHead;
	while (pNode != NULL){
		cout << pNode->m_nValue;
		if (pNode->m_pLeft)
			cout << "(ǰ�����ֵΪ:" << pNode->m_pLeft->m_nValue << ")";
		if (pNode->m_pRight == NULL)
			cout << endl;
		else
			cout << "--> ";
		pNode = pNode->m_pRight;
	}
}

// ����
int main(void){
	int a[] = { 8, 6, 10, 5, 7, 9, 11 };
	BinaryTreeNode* pRoot = NULL;
	pRoot = constructTree(pRoot, a, 7);
	BinaryTreeNode* pConvert = Convert(pRoot);
	printConvertedTree(pConvert);
	// ֻ��һ�����Ķ�����
	BinaryTreeNode* pRoot2 = pRoot;
	pRoot2->m_pLeft = NULL;
	pRoot2->m_pRight = NULL;
	BinaryTreeNode* pConvert2 = Convert(pRoot2);
	printConvertedTree(pConvert2);
	// �������NULL
	BinaryTreeNode* pNull = Convert(NULL);
	printConvertedTree(pNull);

	system("pause");
	return 0;
}