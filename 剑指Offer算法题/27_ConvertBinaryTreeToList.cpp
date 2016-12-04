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

/*输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。要求不能创建新的结点，只能调整树中结点指针的指向。 */
void ConvertNode(BinaryTreeNode* pNode, BinaryTreeNode** pLastNodeInList);
BinaryTreeNode* Convert(BinaryTreeNode* pRootOfTree){
	BinaryTreeNode* pLastNodeInList = NULL;
	ConvertNode(pRootOfTree, &pLastNodeInList);
	// pLastNodeInList 指向双向链表的尾结点，需要返回头结点
	BinaryTreeNode* pHeadOfList = pLastNodeInList;
	while (pHeadOfList != NULL && pHeadOfList->m_pLeft != NULL)
		pHeadOfList = pHeadOfList->m_pLeft;

	return pHeadOfList;
}

void ConvertNode(BinaryTreeNode* pNode, BinaryTreeNode** pLastNodeInList){
	if (pNode == NULL)
		return;
	BinaryTreeNode* pCurrent = pNode;
	// 转换左子树
	if (pCurrent->m_pLeft != NULL)
		ConvertNode(pCurrent->m_pLeft, pLastNodeInList);
	// m_pLeft 作为转换后链表的前向指针，m_pRight 作为指向后继的指针
	pCurrent->m_pLeft = *pLastNodeInList;
	if (*pLastNodeInList != NULL)
		(*pLastNodeInList)->m_pRight = pCurrent;
	// 转换右子树
	*pLastNodeInList = pCurrent;
	if (pCurrent->m_pRight != NULL)
		ConvertNode(pCurrent->m_pRight, pLastNodeInList);
}
// 层次遍历构建二叉树
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
// 输出转换后的链表
void printConvertedTree(BinaryTreeNode* pHead){
	if (pHead == NULL){
		cout << "List is empty.\n";
		return;
	}
	BinaryTreeNode* pNode = pHead;
	while (pNode != NULL){
		cout << pNode->m_nValue;
		if (pNode->m_pLeft)
			cout << "(前向结点的值为:" << pNode->m_pLeft->m_nValue << ")";
		if (pNode->m_pRight == NULL)
			cout << endl;
		else
			cout << "--> ";
		pNode = pNode->m_pRight;
	}
}

// 测试
int main(void){
	int a[] = { 8, 6, 10, 5, 7, 9, 11 };
	BinaryTreeNode* pRoot = NULL;
	pRoot = constructTree(pRoot, a, 7);
	BinaryTreeNode* pConvert = Convert(pRoot);
	printConvertedTree(pConvert);
	// 只有一个结点的二叉树
	BinaryTreeNode* pRoot2 = pRoot;
	pRoot2->m_pLeft = NULL;
	pRoot2->m_pRight = NULL;
	BinaryTreeNode* pConvert2 = Convert(pRoot2);
	printConvertedTree(pConvert2);
	// 根结点是NULL
	BinaryTreeNode* pNull = Convert(NULL);
	printConvertedTree(pNull);

	system("pause");
	return 0;
}