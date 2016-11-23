#include<iostream>
using std::cout;
using std::endl;
using std::cin;

struct BinaryTreeNode{
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};

BinaryTreeNode* ConstructCore(int* startPreorder, int* endPreorder, int* startInorder, int* endInorder){
	// 前序遍历的第一个数字就是根结点的值
	int rootValue = startPreorder[0];
	BinaryTreeNode* root = new BinaryTreeNode();
	root->m_nValue = rootValue;
	root->m_pLeft = root->m_pRight = NULL;

	if (startPreorder == endPreorder){
		if (startInorder == endInorder && *startPreorder == *startInorder)
			return root;
		else
			throw std::exception("Invalid input.");
	}
	// 在中序遍历中找到根结点的值
	int *rootInorder = startInorder;
	while (rootInorder <= endInorder && *rootInorder != rootValue)
		++rootInorder;
	if (rootInorder == endInorder && *rootInorder != rootValue)
		throw std::exception("Invalid input.");
	int leftLength = rootInorder - startInorder;
	int* leftPreorderEnd = startPreorder + leftLength;
	if (leftLength > 0){
		// 构建左子树
		root->m_pLeft = ConstructCore(startPreorder + 1, leftPreorderEnd, startInorder, rootInorder - 1);
	}
	if (leftLength < endPreorder - startPreorder){
		// 构建右子树
		root->m_pRight = ConstructCore(leftPreorderEnd + 1, endPreorder, rootInorder + 1, endInorder);
	}
	return root;
}
// 重建二叉树，根据输入的前序序列和中序序列
BinaryTreeNode* Construct(int* preorder, int* inorder, int length){
	if (preorder == NULL || inorder == NULL || length <= 0)
		return NULL;

	return ConstructCore(preorder, preorder + length - 1, inorder, inorder + length - 1);
}
// 前序遍历输出
void PreOutput(BinaryTreeNode* root){
	if (root == NULL)
		return;
	cout << root->m_nValue << " ";
	PreOutput(root->m_pLeft);
	PreOutput(root->m_pRight);
}
// 中序遍历输出
void InOutput(BinaryTreeNode* root){
	if (root == NULL)
		return;
	InOutput(root->m_pLeft);
	cout << root->m_nValue << " ";
	InOutput(root->m_pRight);
}

// 测试
int main(void){
	// 不完全二叉树
	int pre1[] = {1,2,4,7,3,5,6,8};
	int in1[] = {4,7,2,1,5,3,8,6};
	BinaryTreeNode* root = Construct(pre1, in1, 8);
	cout << "不完全二叉树前序遍历输出：";
	PreOutput(root);
	cout << endl;
	cout << "中序遍历输出：";
	InOutput(root);
	cout << endl;
	// 完全二叉树
	int pre2[] = { 1, 2, 4, 8, 9, 5, 3, 6, 7 };
	int in2[] = { 8, 4, 9, 2, 5, 1, 6, 3, 7 };
	root = Construct(pre2, in2, 9);
	cout << "\n完全二叉树前序遍历输出：";
	PreOutput(root);
	cout << endl;
	cout << "中序遍历输出：";
	InOutput(root);
	cout << endl;
	// 所有结点都没有右子结点的二叉树，即左斜树
	int pre3[] = { 1, 2, 3, 4, 5 };
	int in3[] = { 5, 4, 3, 2, 1 };
	root = Construct(pre3, in3, 5);
	cout << "\n左斜树前序遍历输出：";
	PreOutput(root);
	cout << endl;
	cout << "中序遍历输出：";
	InOutput(root);
	cout << endl;
	// 右斜树
	int pre4[] = { 1, 2, 3, 4, 5 };
	int in4[] = { 1, 2, 3, 4, 5 };
	root = Construct(pre4, in4, 5);
	cout << "\n右斜树前序遍历输出：";
	PreOutput(root);
	cout << endl;
	cout << "中序遍历输出：";
	InOutput(root);
	cout << endl;
	// 只有一个结点的二叉树
	int pre5[] = {  5 };
	int in5[] = { 5 };
	root = Construct(pre5, in5, 1);
	cout << "\n一个结点的二叉树前序遍历输出：";
	PreOutput(root);
	cout << endl;
	cout << "中序遍历输出：";
	InOutput(root);
	cout << endl;

	// 二叉树的根结点指针是NULL
	int pre7[] = { 5 };
	int in7[] = { 5 };
	root = Construct(pre5, in5, 0);


	system("pause");
	return 0;
}