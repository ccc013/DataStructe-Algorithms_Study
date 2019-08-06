#include<iostream>

using std::cout;
using std::endl;
using std::cin;

struct BinaryTreeNode{
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};
// ���һ���������ľ���
void MirrorRecursively(BinaryTreeNode* pNode){
	if (pNode == NULL)
		return;
	if (pNode->m_pLeft == NULL && pNode->m_pRight == NULL)
		return;

	BinaryTreeNode* pTemp = pNode->m_pLeft;
	pNode->m_pLeft = pNode->m_pRight;
	pNode->m_pRight = pTemp;

	if (pNode->m_pLeft)
		MirrorRecursively(pNode->m_pLeft);
	if (pNode->m_pRight)
		MirrorRecursively(pNode->m_pRight);
}
BinaryTreeNode* ConstructCore(int* startPreorder, int* endPreorder, int* startInorder, int* endInorder){
	// ǰ������ĵ�һ�����־��Ǹ�����ֵ
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
	// ������������ҵ�������ֵ
	int *rootInorder = startInorder;
	while (rootInorder <= endInorder && *rootInorder != rootValue)
		++rootInorder;
	if (rootInorder == endInorder && *rootInorder != rootValue)
		throw std::exception("Invalid input.");
	int leftLength = rootInorder - startInorder;
	int* leftPreorderEnd = startPreorder + leftLength;
	if (leftLength > 0){
		// ����������
		root->m_pLeft = ConstructCore(startPreorder + 1, leftPreorderEnd, startInorder, rootInorder - 1);
	}
	if (leftLength < endPreorder - startPreorder){
		// ����������
		root->m_pRight = ConstructCore(leftPreorderEnd + 1, endPreorder, rootInorder + 1, endInorder);
	}
	return root;
}
// �ؽ������������������ǰ�����к���������
BinaryTreeNode* Construct(int* preorder, int* inorder, int length){
	if (preorder == NULL || inorder == NULL || length <= 0)
		return NULL;

	return ConstructCore(preorder, preorder + length - 1, inorder, inorder + length - 1);
}
// ǰ��������
void PreOutput(BinaryTreeNode* root){
	if (root == NULL)
		return;
	cout << root->m_nValue << " ";
	PreOutput(root->m_pLeft);
	PreOutput(root->m_pRight);
}
// ����������
void InOutput(BinaryTreeNode* root){
	if (root == NULL)
		return;
	InOutput(root->m_pLeft);
	cout << root->m_nValue << " ";
	InOutput(root->m_pRight);
}

// ����
int main(void){
	int pre1[] = { 1, 2, 4, 7, 3, 5, 6, 8 };
	int in1[] = { 4, 7, 2, 1, 5, 3, 8, 6 };
	BinaryTreeNode* root1 = Construct(pre1, in1, 8);
	cout << "\n������Aǰ����������";
	PreOutput(root1);
	MirrorRecursively(root1);
	cout << "\nA�ľ���";
	PreOutput(root1);
	// ֻ���������Ķ�����
	int pre2[] = { 1, 2, 4, 7 };
	int in2[] = { 7, 4, 2, 1 };
	BinaryTreeNode* root2 = Construct(pre2, in2, 4);
	cout << "\n������Bǰ����������";
	PreOutput(root2);
	MirrorRecursively(root2);
	cout << "\nB�ľ���,���������";
	InOutput(root2);
	// ֻ���������Ķ�����
	int pre3[] = { 1, 2, 4, 7 };
	int in3[] = { 1, 2, 4, 7 };
	BinaryTreeNode* root3 = Construct(pre3, in3, 4);
	cout << "\n������Cǰ����������";
	PreOutput(root3);
	MirrorRecursively(root3);
	cout << "\nC�ľ���,���������";
	InOutput(root3);
	// ֻ��һ�����Ķ�����
	int pre4[] = { 1 };
	int in4[] = { 1 };
	BinaryTreeNode* root4 = Construct(pre4, in4, 1);
	cout << "\n������Dǰ����������";
	PreOutput(root4);
	MirrorRecursively(root4);
	cout << "\nD�ľ���";
	PreOutput(root4);
	cout << endl;
	// �������NULL
	BinaryTreeNode* root5 = NULL;
	MirrorRecursively(root5);



	system("pause");
	return 0;
}