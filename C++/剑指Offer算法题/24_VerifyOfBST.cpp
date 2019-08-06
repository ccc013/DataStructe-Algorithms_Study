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

/* 输入一个整数数组，判断其是否是二叉搜索树的后序遍历结果 */
bool VerifySequenceOfBST(int sequence[], int length){
	if (sequence == NULL || length < 0)
		return false;
	// 后序遍历序列最后一个元素是根结点
	int root = sequence[length - 1];
	// 在二叉搜索树中左子树的结点数值小于根结点
	int left_index = 0;
	for (; left_index < length - 1; left_index++){
		if (sequence[left_index] > root)
			// 得到根结点左子树部分的结点总数
			break;
	}
	// 在二叉搜索树中右子树的结点数值大于根结点
	int right_index = left_index;
	for (; right_index < length - 1; right_index++){
		if (sequence[right_index] < root)
			return false;
	}
	// 判断左子树是不是二叉搜索树
	bool left = true;
	if (left_index>0)
		left = VerifySequenceOfBST(sequence, left_index);
	// 判断右子树是不是二叉搜索树
	bool right = true;
	if (left_index < length - 1)
		right = VerifySequenceOfBST(sequence, right_index);

	return (left && right);
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


// 测试
int main(void){
	int a[] = { 8, 6, 10, 5, 7, 9, 11 };
	BinaryTreeNode* pRoot = NULL;
	pRoot = constructTree(pRoot, a, 7);
	int seq1[] = { 5, 7, 6, 9, 11, 10, 8 };
	int seq2[] = { 7, 4, 6, 5 };
	if (VerifySequenceOfBST(seq1, 7))
		cout << "seq1 是二叉搜索树的后序遍历序列.\n";
	else
		cout << "seq1 不是二叉搜索树的后序遍历序列.\n";
	if (VerifySequenceOfBST(seq2, 4))
		cout << "seq2 是二叉搜索树的后序遍历序列.\n";
	else
		cout << "seq2 不是二叉搜索树的后序遍历序列.\n";

	system("pause");
	return 0;
}