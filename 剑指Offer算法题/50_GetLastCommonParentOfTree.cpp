#include<iostream>
#include<list>
#include<vector>
using std::vector;
using std::list;
using std::cout;
using std::endl;
using std::cin;

/* 树中两个结点的最低公共祖先 */
struct TreeNode{
	int m_nValue;
	vector<TreeNode *> m_vChildren;
};
// 寻找从根结点pRoot开始到达结点pNode的路径
bool GetNodePath(TreeNode* pRoot, TreeNode* pNode, list<TreeNode *>& path){
	if (pRoot == pNode)
		return true;
	path.push_back(pRoot);
	bool found = false;
	vector<TreeNode *>::iterator i = pRoot->m_vChildren.begin();
	while (!found && i < pRoot->m_vChildren.end()){
		found = GetNodePath(*i, pNode, path);
		++i;
	}
	if (!found)
		path.pop_back();
	return found;
}
// 寻找两个路径中的最后一个公共结点，也就是目标所求的公共祖先
TreeNode* GetLastCommonNode(const list<TreeNode*>& path1, const list<TreeNode*>& path2){
	list<TreeNode*>::const_iterator iterator1 = path1.begin();
	list<TreeNode*>::const_iterator iterator2 = path2.begin();

	TreeNode* pLast = NULL;
	while (iterator1 != path1.end() && iterator2 != path2.end()){
		if (*iterator1 == *iterator2)
			pLast = *iterator1;
		iterator1++;
		iterator2++;
	}
	return pLast;
}
TreeNode* GetLastCommonParent(TreeNode* pRoot, TreeNode* pNode1, TreeNode* pNode2){
	if (pRoot == NULL || pNode1 == NULL || pNode2 == NULL)
		return NULL;
	list<TreeNode*> path1;
	GetNodePath(pRoot, pNode1, path1);

	list<TreeNode*> path2;
	GetNodePath(pRoot, pNode2, path2);

	return GetLastCommonNode(path1, path2);
}

void Test(const char* str){
	
}

// 测试
int main(void){
	
	

	system("pause");
	return 0;
}