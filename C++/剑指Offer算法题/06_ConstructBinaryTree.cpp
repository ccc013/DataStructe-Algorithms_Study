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
	// ����ȫ������
	int pre1[] = {1,2,4,7,3,5,6,8};
	int in1[] = {4,7,2,1,5,3,8,6};
	BinaryTreeNode* root = Construct(pre1, in1, 8);
	cout << "����ȫ������ǰ����������";
	PreOutput(root);
	cout << endl;
	cout << "������������";
	InOutput(root);
	cout << endl;
	// ��ȫ������
	int pre2[] = { 1, 2, 4, 8, 9, 5, 3, 6, 7 };
	int in2[] = { 8, 4, 9, 2, 5, 1, 6, 3, 7 };
	root = Construct(pre2, in2, 9);
	cout << "\n��ȫ������ǰ����������";
	PreOutput(root);
	cout << endl;
	cout << "������������";
	InOutput(root);
	cout << endl;
	// ���н�㶼û�����ӽ��Ķ�����������б��
	int pre3[] = { 1, 2, 3, 4, 5 };
	int in3[] = { 5, 4, 3, 2, 1 };
	root = Construct(pre3, in3, 5);
	cout << "\n��б��ǰ����������";
	PreOutput(root);
	cout << endl;
	cout << "������������";
	InOutput(root);
	cout << endl;
	// ��б��
	int pre4[] = { 1, 2, 3, 4, 5 };
	int in4[] = { 1, 2, 3, 4, 5 };
	root = Construct(pre4, in4, 5);
	cout << "\n��б��ǰ����������";
	PreOutput(root);
	cout << endl;
	cout << "������������";
	InOutput(root);
	cout << endl;
	// ֻ��һ�����Ķ�����
	int pre5[] = {  5 };
	int in5[] = { 5 };
	root = Construct(pre5, in5, 1);
	cout << "\nһ�����Ķ�����ǰ����������";
	PreOutput(root);
	cout << endl;
	cout << "������������";
	InOutput(root);
	cout << endl;

	// �������ĸ����ָ����NULL
	int pre7[] = { 5 };
	int in7[] = { 5 };
	root = Construct(pre5, in5, 0);


	system("pause");
	return 0;
}