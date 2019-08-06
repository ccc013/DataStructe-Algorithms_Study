#include<iostream>
#include<queue>
#include<vector>
using std::vector;
using std::deque;
using std::cout;
using std::endl;
using std::cin;
struct BinaryTreeNode{
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};

/*����һ�ö�������һ����������ӡ���������н��ֵ�ĺ�Ϊ��������������·�� */
void FindPath(BinaryTreeNode* pRoot, int expectedSum, vector<int>& path, int currentSum){
	currentSum += pRoot->m_nValue;
	path.push_back(pRoot->m_nValue);

	// �����Ҷ�ӽ�㣬��·���Ͻ��ĺ͵�������ֵ����ӡ����·��
	bool isLeaf = pRoot->m_pLeft == NULL && pRoot->m_pRight == NULL;
	if (currentSum == expectedSum && isLeaf){
		cout << "A path is found: ";
		vector<int>::iterator iter = path.begin();
		for (; iter != path.end(); ++iter){
			cout << *iter << " ";
		}
		cout << endl;
	}
	// �������Ҷ��㣬�ͱ������ӽ��
	if (pRoot->m_pLeft != NULL)
		FindPath(pRoot->m_pLeft, expectedSum, path, currentSum);
	if (pRoot->m_pRight != NULL)
		FindPath(pRoot->m_pRight, expectedSum, path, currentSum);
	// �ڷ��ص������֮ǰ����·����ɾ����ǰ���
	path.pop_back();
}

void FindPath(BinaryTreeNode* pRoot, int expectedSum){
	if (pRoot == NULL)
		return;
	vector<int> path;
	int currentSum = 0;
	FindPath(pRoot, expectedSum, path, currentSum);
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
	// ֻ��һ��·��
	int a[] = { 8, 6, 10, 5, 7, 9, 11 };
	BinaryTreeNode* pRoot = NULL;
	pRoot = constructTree(pRoot, a, 7);
	FindPath(pRoot, 19);
	// ����·��
	int a2[] = { 8, 5,10,5,2 };
	BinaryTreeNode* pRoot2 = NULL;
	pRoot2 = constructTree(pRoot2, a2, 5);
	FindPath(pRoot2, 18);
	FindPath(pRoot2, 11);

	system("pause");
	return 0;
}