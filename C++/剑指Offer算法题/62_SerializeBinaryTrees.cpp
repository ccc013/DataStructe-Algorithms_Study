#include<iostream>
#include<queue>
#include<stack>
#include <fstream>
using std::stack;
using std::deque;
using std::cout;
using std::endl;
using std::cin;
using std::ostream;
using std::istream;

/* 请实现两个函数，分别用来序列化和反序列化。 */
struct BinaryTreeNode{
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};
// 序列化
void Serialize(BinaryTreeNode* pRoot, ostream& stream){
	if (pRoot == NULL){
		stream << "$, ";
		return;
	}
	stream << pRoot->m_nValue << ", ";
	Serialize(pRoot->m_pLeft, stream);
	Serialize(pRoot->m_pRight, stream);
}
// 每次读取字符，如果是数字或者'$'，返回true，否则返回false
bool ReadStream(istream& stream, int* number)
{
	if (stream.eof())
		return false;

	char buffer[32];
	buffer[0] = '\0';

	char ch;
	stream >> ch;
	int i = 0;
	while (!stream.eof() && ch != ',')
	{
		buffer[i++] = ch;
		stream >> ch;
	}

	bool isNumeric = false;
	if (i > 0 && buffer[0] != '$')
	{
		*number = atoi(buffer);
		isNumeric = true;
	}

	return isNumeric;
}

// 反序列化
void Deserialize(BinaryTreeNode** pRoot, istream& stream){
	int number;
	if (ReadStream(stream, &number))
	{
		*pRoot = new BinaryTreeNode();
		(*pRoot)->m_nValue = number;
		(*pRoot)->m_pLeft = NULL;
		(*pRoot)->m_pRight = NULL;

		Deserialize(&((*pRoot)->m_pLeft), stream);
		Deserialize(&((*pRoot)->m_pRight), stream);
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


void Test(BinaryTreeNode* pRoot){
	if (pRoot){
		cout << "Binary tree: ";
		PrintFromTopToBottom(pRoot);
	}
	else{
		cout << "Null tree: ";
		return;
	}
	// 保存序列化结果的文件名字
	char* fileName = "test.txt";
	std::ofstream fileOut;
	fileOut.open(fileName);

	Serialize(pRoot, fileOut);
	fileOut.close();
	
	// 打印序列化的结果
	std::ifstream fileIn1;
	char ch;
	fileIn1.open(fileName);
	cout << "Serialize list: ";
	while (!fileIn1.eof())
	{
		fileIn1 >> ch;
		cout << ch;
	}
	fileIn1.close();
	cout << endl;
	// 反序列化，从保存序列化结果的文件读取
	std::ifstream fileIn2;
	fileIn2.open(fileName);
	BinaryTreeNode* pNewRoot = NULL;
	Deserialize(&pNewRoot, fileIn2);
	fileIn2.close();
	cout << "Deserialize tree: ";
	PrintFromTopToBottom(pNewRoot);
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