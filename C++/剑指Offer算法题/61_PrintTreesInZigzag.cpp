#include<iostream>
#include<queue>
#include<stack>
using std::stack;
using std::deque;
using std::cout;
using std::endl;
using std::cin;

/* 从上到下按之字形顺序打印二叉树，即奇数层从左到右打印，偶数层从右到左打印，每一层打印一行。 */
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
	stack<BinaryTreeNode*> levels[2];
	int current = 0;
	int next = 1;

	levels[current].push(pRoot);
	while (!levels[0].empty() || !levels[1].empty()){
		BinaryTreeNode* pNode = levels[current].top();
		levels[current].pop();
		cout << pNode->m_nValue << " ";

		if (current == 0){
			// 当前是奇数层，先压入左子结点，再压入右子节点，则下一层的打印就是从右到左打印
			if (pNode->m_pLeft != NULL)
				levels[next].push(pNode->m_pLeft);
			if (pNode->m_pRight != NULL)
				levels[next].push(pNode->m_pRight);
		}
		else{
			// 当前是偶数层，先压入右子结点，再压入左子节点，所有下一层就是从左到右打印
			if (pNode->m_pRight != NULL)
				levels[next].push(pNode->m_pRight);
			if (pNode->m_pLeft != NULL)
				levels[next].push(pNode->m_pLeft);
		}
		// 当前层打印完毕
		if (levels[current].empty()){
			cout << endl;
			current = 1 - current;
			next = 1 - next;
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