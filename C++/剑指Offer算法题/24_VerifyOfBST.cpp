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

/* ����һ���������飬�ж����Ƿ��Ƕ����������ĺ��������� */
bool VerifySequenceOfBST(int sequence[], int length){
	if (sequence == NULL || length < 0)
		return false;
	// ��������������һ��Ԫ���Ǹ����
	int root = sequence[length - 1];
	// �ڶ������������������Ľ����ֵС�ڸ����
	int left_index = 0;
	for (; left_index < length - 1; left_index++){
		if (sequence[left_index] > root)
			// �õ���������������ֵĽ������
			break;
	}
	// �ڶ������������������Ľ����ֵ���ڸ����
	int right_index = left_index;
	for (; right_index < length - 1; right_index++){
		if (sequence[right_index] < root)
			return false;
	}
	// �ж��������ǲ��Ƕ���������
	bool left = true;
	if (left_index>0)
		left = VerifySequenceOfBST(sequence, left_index);
	// �ж��������ǲ��Ƕ���������
	bool right = true;
	if (left_index < length - 1)
		right = VerifySequenceOfBST(sequence, right_index);

	return (left && right);
}

// ��α�������������
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


// ����
int main(void){
	int a[] = { 8, 6, 10, 5, 7, 9, 11 };
	BinaryTreeNode* pRoot = NULL;
	pRoot = constructTree(pRoot, a, 7);
	int seq1[] = { 5, 7, 6, 9, 11, 10, 8 };
	int seq2[] = { 7, 4, 6, 5 };
	if (VerifySequenceOfBST(seq1, 7))
		cout << "seq1 �Ƕ����������ĺ����������.\n";
	else
		cout << "seq1 ���Ƕ����������ĺ����������.\n";
	if (VerifySequenceOfBST(seq2, 4))
		cout << "seq2 �Ƕ����������ĺ����������.\n";
	else
		cout << "seq2 ���Ƕ����������ĺ����������.\n";

	system("pause");
	return 0;
}