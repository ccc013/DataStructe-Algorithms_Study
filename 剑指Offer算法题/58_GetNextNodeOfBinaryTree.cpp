#include<iostream>
#include<queue>
using std::deque;
using std::cout;
using std::endl;
using std::cin;

/* 给定一棵二叉树和其中的一个结点，找出其中序遍历顺序的下一个结点。树中结点还有一个指向父结点的指针。 */
struct BinaryTreeNode{
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
	BinaryTreeNode* m_pParent;
};
BinaryTreeNode* GetNext(BinaryTreeNode* pNode){
	if (pNode == NULL)
		return NULL;

	BinaryTreeNode* pNext = NULL;
	if (pNode->m_pRight != NULL){
		// 如果当前结点有右子树，则目标结点是其右子树中的最左子结点
		BinaryTreeNode* pRight = pNode->m_pRight;
		while (pRight->m_pLeft != NULL)
			pRight = pRight->m_pLeft;
		pNext = pRight;
	}
	else if (pNode->m_pParent != NULL){
		BinaryTreeNode* pCurrent = pNode;
		BinaryTreeNode* pParent = pNode->m_pParent;
		while (pParent != NULL && pCurrent == pParent->m_pRight){
			// 寻找到一个是其父结点的左子结点的结点，该结点的父结点就是目标结点
			pCurrent = pParent;
			pParent = pParent->m_pParent;
		}

		pNext = pParent;
	}
	return pNext;
}
/* 从上往下打印二叉树 */
void PrintFromTopToBottom(BinaryTreeNode* pTreeRoot){
	if (!pTreeRoot){
		cout << "Tree is empty!\n";
		return;
	}
	deque<BinaryTreeNode*> dequeTreeNode;
	dequeTreeNode.push_back(pTreeRoot);

	while (dequeTreeNode.size()){
		BinaryTreeNode* pNode = dequeTreeNode.front();
		dequeTreeNode.pop_front();
		cout << pNode->m_nValue;
		if (pNode->m_pParent)
			cout << "(parent: " << pNode->m_pParent->m_nValue << ") ";
		else
			cout << " ";
		if (pNode->m_pLeft)
			dequeTreeNode.push_back(pNode->m_pLeft);
		if (pNode->m_pRight)
			dequeTreeNode.push_back(pNode->m_pRight);
	}
	cout << endl;
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
			pLeft->m_pParent = pNode;
			pNode->m_pLeft = pLeft;
			dequeTreeNode.push_back(pLeft);
			i++;
			if (i == length)
				break;
		}
		if (pNode->m_pRight == NULL){
			BinaryTreeNode* pRight = new BinaryTreeNode();
			pRight->m_nValue = a[i];
			pRight->m_pParent = pNode;
			pNode->m_pRight = pRight;
			dequeTreeNode.push_back(pRight);
			i++;
			if (i == length)
				break;
		}
	}
	return pTreeRoot;
}


void Test(BinaryTreeNode* pHead){
	if (pHead){
		cout << "Binary tree: ";
		PrintFromTopToBottom(pHead);
	}
	else{
		cout << "Null tree: ";
		return;
	}
	BinaryTreeNode* pNode = pHead->m_pLeft;
	cout << "Test node value =	" << pNode->m_nValue << endl;
	pNode = GetNext(pNode);
	if (pNode)
		cout << "It's next node value = " << pNode->m_nValue << endl;
	else
		cout << "no next node";
	// 测试根结点
	cout << "Test node value =" << pHead->m_nValue << endl;
	pNode = GetNext(pHead);
	if (pNode)
		cout << "It's next node value = " << pNode->m_nValue << endl;
	else
		cout << "no next node";
	// 测试中序遍历最后一个结点
	pNode = pHead->m_pRight->m_pRight;
	cout << "Test node value =" << pNode->m_nValue << endl;
	pNode = GetNext(pNode);
	if (pNode)
		cout << "It's next node value = " << pNode->m_nValue << endl;
	else
		cout << "no next node\n";
	// 测试一个结点，没有右子树，是其父结点的右子结点
	pNode = pHead->m_pLeft->m_pRight;
	cout << "Test node value =" << pNode->m_nValue << endl;
	pNode = GetNext(pNode);
	if (pNode)
		cout << "It's next node value = " << pNode->m_nValue << endl;
	else
		cout << "no next node\n";
}

// 测试
int main(void){
	int a[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	BinaryTreeNode* pRoot = NULL;
	pRoot = constructTree(pRoot, a, 8);
	Test(pRoot);

	system("pause");
	return 0;
}