#include<iostream>
#include<queue>

using std::deque;
using std::cout;
using std::endl;
using std::cin;


/* 给定一棵二叉搜索树，请找出其中的第k大的结点 */
struct BinaryTreeNode{
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};
// 解法，通过中序遍历来求第k个结点
BinaryTreeNode* KthNodeCore(BinaryTreeNode* pRoot, unsigned int &k){
	BinaryTreeNode* target = NULL;

	if (pRoot->m_pLeft != NULL)
		target = KthNodeCore(pRoot->m_pLeft, k);
	if (target == NULL){
		if (k == 1)
			target = pRoot;
		k--;
	}
	if (target == NULL && pRoot->m_pRight != NULL)
		target = KthNodeCore(pRoot->m_pRight, k);
	return target;
}
BinaryTreeNode* KthNode(BinaryTreeNode* pRoot, unsigned int k){
	if (pRoot == NULL || k == 0)
		return NULL;
	return KthNodeCore(pRoot, k);
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


void Test(BinaryTreeNode* pRoot,unsigned int k){
	if (pRoot){
		cout << "Binary tree: ";
		PrintFromTopToBottom(pRoot);
	}
	else{
		cout << "Null tree: ";
		return;
	}
	BinaryTreeNode* pNode = NULL;
	cout << "Find the " << k << ": ";
	pNode = KthNode(pRoot, k);
	if (pNode)
		cout << pNode->m_nValue << endl;
	else
		cout << "error!\n";
}

// 测试
int main(void){
	int a[] = { 5,3,7,2,4,6,8 };
	BinaryTreeNode* pRoot = NULL;
	pRoot = constructTree(pRoot, a, 7);
	Test(pRoot,3);
	Test(pRoot, 0);
	Test(pRoot, 8);
	Test(NULL, 2);

	system("pause");
	return 0;
}