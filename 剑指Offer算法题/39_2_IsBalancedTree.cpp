#include<iostream>
#include<queue>
using std::deque;
using std::cout;
using std::endl;
using std::cin;

/*输入一棵二叉树的根结点，判断该树是否是平衡二叉树 */
struct BinaryTreeNode{
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};

// 求取二叉树的深度
int TreeDepth(BinaryTreeNode* pRoot){
	if (pRoot == NULL)
		return 0;
	int nLeft = TreeDepth(pRoot->m_pLeft);
	int nRight = TreeDepth(pRoot->m_pRight);

	return (nLeft > nRight) ? (nLeft + 1) : (nRight + 1);
}
// 解法1
bool isBalanced(BinaryTreeNode* pRoot){
	if (pRoot == NULL)
		return true;
	int nLeft = TreeDepth(pRoot->m_pLeft);
	int nRight = TreeDepth(pRoot->m_pRight);
	int diff = nLeft - nRight;
	if (diff > 1 || diff < -1)
		return false;
	return isBalanced(pRoot->m_pLeft) && isBalanced(pRoot->m_pRight);
}

// 解法2
bool IsBalanced(BinaryTreeNode* pRoot, int* pDepth){
	if (pRoot == NULL){
		*pDepth = 0;
		return true;
	}
	int left, right;
	if (IsBalanced(pRoot->m_pLeft, &left)
		&& IsBalanced(pRoot->m_pRight, &right)){
		int diff = left - right;
		if (diff <= 1 && diff >= -1){
			*pDepth = 1 + (left > right) ? left : right;
			return true;
		}
	}
	return false;
}

bool isBalanced_2(BinaryTreeNode *pRoot){
	int depth = 0;
	return IsBalanced(pRoot, &depth);
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
		cout << pNode->m_nValue << " ";
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

void Test(BinaryTreeNode* pRoot){
	cout << "solution1 result: ";
	if (isBalanced(pRoot))
		cout << "true\n";
	else
		cout << "false\n";

	cout << "solution2 result: ";
	if (isBalanced_2(pRoot))
		cout << "true\n";
	else
		cout << "false\n";
	
}

// 测试
int main(void){
	int a[] = { 8, 6, 10, 5, 7, 9, 11 };
	BinaryTreeNode* pRoot = NULL;
	pRoot = constructTree(pRoot, a, 7);
	PrintFromTopToBottom(pRoot);
	Test(pRoot);

	

	system("pause");
	return 0;
}