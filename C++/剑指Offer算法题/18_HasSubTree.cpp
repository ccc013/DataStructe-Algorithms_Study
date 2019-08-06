#include<iostream>

using std::cout;
using std::endl;
using std::cin;

struct BinaryTreeNode{
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};
// 判断A中以R为根结点的子树是否和B具有相同的结构
bool DoseTree1HaveTree2(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2){
	if (pRoot2 == NULL)
		return true;
	if (pRoot1 == NULL)
		return false;
	if (pRoot1->m_nValue != pRoot2->m_nValue)
		return false;

	return DoseTree1HaveTree2(pRoot1->m_pLeft, pRoot2->m_pLeft) &&
		DoseTree1HaveTree2(pRoot1->m_pRight, pRoot2->m_pRight);
}

// 输入两棵二叉树A和B，判断B是不是A的子结构
bool HasSubtree(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2){
	bool result = false;

	if (pRoot1 != NULL && pRoot2 != NULL){
		// 寻找A中与B的根结点一样值的结点
		if (pRoot1->m_nValue == pRoot2->m_nValue)
			result = DoseTree1HaveTree2(pRoot1, pRoot2);
		if (!result)
			result = HasSubtree(pRoot1->m_pLeft, pRoot2);
		if (!result)
			result = HasSubtree(pRoot1->m_pRight, pRoot2);
	}
	return result;
}
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

// 测试
int main(void){
	int pre1[] = { 1, 2, 4, 7, 3, 5, 6, 8 };
	int in1[] = { 4, 7, 2, 1, 5, 3, 8, 6 };
	BinaryTreeNode* root1 = Construct(pre1, in1, 8);
	cout << "\n二叉树A前序遍历输出：";
	PreOutput(root1);

	int pre2[] = { 2, 4, 7 };
	int in2[] = { 4, 7, 2 };
	BinaryTreeNode* root2 = Construct(pre2, in2, 3);
	cout << "\n二叉树B前序遍历输出：";
	PreOutput(root2);

	if (HasSubtree(root1, root2))
		cout << "\nB是A的子结构\n";
	else
		cout << "\nB不是A的子结构\n";

	int pre3[] = { 2, 9, 2 };
	int in3[] = { 9, 2, 2 };
	BinaryTreeNode* root3 = Construct(pre3, in3, 3);
	cout << "\n二叉树C前序遍历输出：";
	PreOutput(root3);

	if (HasSubtree(root1, root3))
		cout << "\nC是A的子结构\n";
	else
		cout << "\nC不是A的子结构\n";

	BinaryTreeNode* root4 = NULL;
	if (HasSubtree(root1, root4))
		cout << "\nD是A的子结构\n";
	else
		cout << "\nD不是A的子结构\n";



	system("pause");
	return 0;
}