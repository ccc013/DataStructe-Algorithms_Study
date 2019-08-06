#include<iostream>
#include<queue>
using std::deque;
using std::cout;
using std::endl;
using std::cin;

/* 从上到下打印二叉树，每一层打印一行，从左到右的顺序打印每层结点。 */
struct BinaryTreeNode{
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};

void Print(BinaryTreeNode* pRoot){
	if (pRoot == NULL){
		cout << "Tree is null." << endl;
		return;
	}
	deque<BinaryTreeNode*> nodes;
	nodes.push_back(pRoot);
	// 下一层结点的数目
	int nextLevel = 0;
	// 当前层还没打印的结点数
	int toBePrinted = 1;
	while (!nodes.empty()){
		BinaryTreeNode* pNode = nodes.front();
		cout << pNode->m_nValue << " ";
		if (pNode->m_pLeft != NULL){
			nodes.push_back(pNode->m_pLeft);
			++nextLevel;
		}
		if (pNode->m_pRight != NULL){
			nodes.push_back(pNode->m_pRight);
			++nextLevel;
		}
		nodes.pop_front();
		--toBePrinted;
		if (toBePrinted == 0){
			// 当前层的所有结点都打印完
			cout << endl;
			toBePrinted = nextLevel;
			nextLevel = 0;
		}
	}
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
		cout << pNode->m_nValue<< " ";
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


void Test(BinaryTreeNode* pHead){
	if (pHead){
		cout << "Binary tree: ";
		PrintFromTopToBottom(pHead);
	}
	else{
		cout << "Null tree: ";
		return;
	}
	Print(pHead);
}

// 测试
int main(void){
	int a[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	BinaryTreeNode* pRoot = NULL;
	pRoot = constructTree(pRoot, a, 8);
	Test(pRoot);

	int a2[] = { 8, 6, 6, 5, 6, 6, 5 };
	pRoot = NULL;
	pRoot = constructTree(pRoot, a2, 7);
	Test(pRoot);

	system("pause");
	return 0;
}