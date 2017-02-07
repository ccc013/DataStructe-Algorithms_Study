### AlgorithmsPractises--Tree

------

记录算法练习中的练习题以及实现的代码，练习题主要是来自[Hihocoder][1]以及[LeetCode](https://leetcode.com/problemset/algorithms/)，主要还是按照级别，由简单到难的顺序练习，并且主要是有关树的算法题。

##### 1. [Maximum Depth of Binary Tree](https://leetcode.com/problems/maximum-depth-of-binary-tree/)

问题的描述如下：

> Given a binary tree, find its maximum depth.
>
> The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

这道题是要计算二叉树的最大深度，实现代码如下：

```c++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root)
            return 0;
        int lval = maxDepth(root->left) + 1;
        int rval = maxDepth(root->right) + 1;
        return (lval > rval)? lval : rval;
    }
};
```

这里使用递归的方法，比较左右子树的深度，返回最大值。

##### 2. [Invert Binary Tree](https://leetcode.com/problems/invert-binary-tree/)

问题描述如下：

> Invert a binary tree.
>
> ```
>      4
>    /   \
>   2     7
>  / \   / \
> 1   3 6   9
> ```
>
> to
>
> ```
>      4
>    /   \
>   7     2
>  / \   / \
> 9   6 3   1
> ```

这道题目是将一颗二叉树的左右子树进行对调，我的实现方法如下：

```c++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root)
            return root;
        if(root->left || root->right){
            TreeNode *tmp = root->left;
            root->left = root->right;
            root->right = tmp;
        }
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};
```

这里是使用了前序遍历的方法。一个更快的代码实现如下：

```c++
class Solution {
  public:
  TreeNode* invertTree(TreeNode* root) {
    if(root ==NULL)
    	return root;
    TreeNode* temp=root->left;
    root->left=invertTree(root->right);
    root->right=invertTree(temp);
    return root;
}	
```

##### 3. [Sum of Left Leaves](https://leetcode.com/problems/sum-of-left-leaves/)

题目描述：

>Find the sum of all left leaves in a given binary tree.
>
>**Example:**
>
>```
>    3
>   / \
>  9  20
>    /  \
>   15   7
>
>There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24.
>```

这题是要计算所有作为左叶子结点的数值的和。实现代码如下：

```c++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        return helper(root, 0);
    }
    
    int helper(TreeNode* root, int flag){
        if(!root)
            return 0;
        if(flag == 0){
            // middle
            return helper(root->left, 1) + helper(root->right, 2);
        }
        if(flag == 1){
            // left tree
            if(!root->left && !root->right)
                return root->val;
        }
        // right tree
        return helper(root->left, 1) + helper(root->right, 2);
    }
};
```

这题一开始还是难住了，主要是需要判断当前叶子结点是在左边还是右边，参考了别人的代码，发现都是增加一个辅助函数，用来增加一个变量，可以提示这是属于左叶子结点还是右边的。当然也看到下面这种不需要辅助函数的实现代码：

```c++
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
      if (!root || (root->left == NULL && root->right == NULL) ) return 0;
      if (root->left != NULL && root->left->left == NULL && root->left->right == NULL) {
        return root->left->val + sumOfLeftLeaves(root->right);
      }
      return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
    }
};
```

这个方法主要是需要先判断后当前结点的子树的子树的情况，也就是其子孙结点了，如果子孙结点只有左边，没有右边，那这就是符合情况的结点，然后下一步就遍历其右子树的情况。

##### 4. [Same Tree](https://leetcode.com/problems/same-tree/)

题目描述如下：

> Given two binary trees, write a function to check if they are equal or not.
>
> Two binary trees are considered equal if they are structurally identical and the nodes have the same value.

给定两棵二叉树，判断它们是否相等，相等的条件是二叉树的结构相同而且每个节点有同样的值。

实现代码如下：

```c++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q)
            return true;
        if(!p || !q || p->val != q->val)
            return false;
        return (isSameTree(p->left, q->left) && isSameTree(p->right, q->right))? true : false;
    }
};
```

采用前序遍历的方法，首先两个结点都是空结点，那么应该是相同的情况，而当有一个结点为空，或者结点的数值不相同，这都是不相等的条件。

##### 5. [Balanced Binary Tree](https://leetcode.com/problems/balanced-binary-tree/)

题目描述如下：

> Given a binary tree, determine if it is height-balanced.
>
> For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of *every* node never differ by more than 1.

这道题的意思是给定一棵二叉树，判断它是否是高度平衡的，高度平衡是指二叉树中任意一个结点的两个子树的深度之差不大于1。

实现代码如下：

```c++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(!root)
            return true;
        int lH = 0, rH = 0;
        lH = maxDepth(root->left);
        rH = maxDepth(root->right);
        if(abs(lH-rH) > 1)
            return false;
        else
            return isBalanced(root->left) && isBalanced(root->right);
    }
    
    int maxDepth(TreeNode* root) {
        if(!root)
            return 0;
        int lval = maxDepth(root->left) + 1;
        int rval = maxDepth(root->right) + 1;
        return (lval > rval)? lval : rval;
    }
};
```

这里需要先获取每个结点的深度，所以定义了一个`maxDepth()`函数，然后每次判断一个结点后，如果其左右子树深度差不大于1，则需要继续判断，如果是大于1，则不满足高度平衡的条件，直接返回`false`。

##### 6.[Binary Tree Level Order Traversal](https://leetcode.com/problems/binary-tree-level-order-traversal/)

题目描述如下：

> Given a binary tree, return the *level order* traversal of its nodes' values. (ie, from left to right, level by level).
>
> For example:
> Given binary tree `[3,9,20,null,null,15,7]`,
>
> ```
>     3
>    / \
>   9  20
>     /  \
>    15   7
>
> ```
>
> return its level order traversal as:
>
> ```c++
> [
>   [3],
>   [9,20],
>   [15,7]
> ]
> ```

这是要对树进行层次遍历，然后输出每一层的结点的数值，这里需要使用到队列来辅助。实现代码如下：

```c++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> nodes;
        vector<vector<int>> result;
        if(!root){
            return result;
        }
        
        int i=0;
        nodes.push(root);
        while(!nodes.empty()){
            result.push_back(vector<int> ());
            // 保存下一层次的结点
            queue<TreeNode*> tmp;          
            while(!nodes.empty()){
                // 开始遍历当前第i层的结点
                TreeNode *n = nodes.front();
                nodes.pop();
                result[i].push_back(n->val);
                if(n->left)
                    tmp.push(n->left);
                if(n->right)
                    tmp.push(n->right);
            }
            i++;
            nodes = tmp;
        }
        return result;
    }
};
```

这里用到两个`queue`，一个是保存当前层次的结点，另一个`tmp`则是保存下一层次的结点，用于下次循环的时候进行遍历。

##### 7. [Binary Tree Level Order Traversal II](https://leetcode.com/problems/binary-tree-level-order-traversal-ii/)

题目描述如下：

> Given a binary tree, return the *bottom-up level order* traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).
>
> For example:
> Given binary tree `[3,9,20,null,null,15,7]`,
>
> ```
>     3
>    / \
>   9  20
>     /  \
>    15   7
>
> ```
>
> return its bottom-up level order traversal as:
>
> ```
> [
>   [15,7],
>   [9,20],
>   [3]
> ]
> ```

这道题目跟上一题差不多，只是要求输出的时候是自底向上的输出。所以只需对上一题的代码简单修改即可：

```c++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        queue<TreeNode*> nodes;
        vector<vector<int>> result;
        if(!root){
            return result;
        }
        
        int i=0;
        nodes.push(root);
        while(!nodes.empty()){
            result.push_back(vector<int> ());
            // 保存下一层次的结点
            queue<TreeNode*> tmp;          
            while(!nodes.empty()){
                // 开始遍历当前第i层的结点
                TreeNode *n = nodes.front();
                nodes.pop();
                result[i].push_back(n->val);
                if(n->left)
                    tmp.push(n->left);
                if(n->right)
                    tmp.push(n->right);
            }
            i++;
            nodes = tmp;
        }
      /*
        int nums = result.size();
        for(int j=0;j<nums/2;j++){
            vector<int> temps = result[j];
            result[j] = result[nums-j-1];
            result[nums-j-1] = temps;
        }
        */
        reverse(result.begin(), result.end());
        return result;
    }
};
```

主要是增加了在最后返回`result`前的代码，对`result`进行一个反转排序来满足题目的输出要求。

去讨论区看到别人的实现方法，第一种如下：

```c++
 // this is the helper function to do level traversal from top to bottom
void levelOrderTop(TreeNode* r, int level, vector<vector<int>>& res) {
     if (!r) return;
     if (level == res.size()) res.push_back({r->val}); // enter a deeper level for the first time
     else res[level].push_back(r->val); // enter a previously visited level and append node

      // do left subtree first since it requires to print from left node at the same level
     levelOrderTop(r->left, level+1,res);
     levelOrderTop(r->right, level+1,res);
}
    
vector<vector<int>> levelOrderBottom(TreeNode* r) {
     vector<vector<int>> res;
     levelOrderTop(r, 0, res); // root is at level 0
     reverse(res.begin(), res.end()); // reverse to get order from bottom to root level
     return res;
 }
```

这个方法首先是其层次遍历方法是用一个递归的方法来实现的，而没有使用到队列。

##### 8.[Path Sum](https://leetcode.com/problems/path-sum/)

题目描述如下：

> Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.
>
> For example:
>
> Given the below binary tree and 
>
> ```
> sum = 22
> ```
>
> ,
>
> ```
>               5
>              / \
>             4   8
>            /   / \
>           11  13  4
>          /  \      \
>         7    2      1
>
> ```
>
> return true, as there exist a root-to-leaf path `5->4->11->2` which sum is 22.

这道题目是给定一个二叉树和一个数值，在二叉树里找到一个从根结点到叶子结点的路径，这个路径上所有数值之和等于给定的数值，这里需要注意最后的结点一定是叶子结点。实现代码如下：

```c++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root)
            return false;
        sum -= root->val;
        if (sum == 0 && root->left == NULL && root->right == NULL)
        // must be leaf node
            return true;
        return hasPathSum(root->left, sum) || hasPathSum(root->right, sum);
    }
};
```

这道题目提交了三次才通过，第一次失败的原因就是忘记了最后一个结点必须是叶子结点才可以，所以在判断`sum==0`后，还需要判断`root->left == NULL && root->right == NULL`才可以，第二层错误的原因是忽略了负数，一开始是只当做正数，所以有一段代码

```c++
if(sum<0) 
	return false;
```

但是因为是有负数的可能，所以就删除上面这段代码，最终第三次成功提交。果然还是需要好好看题，思考要更加周全点。

##### 9.[Lowest Common Ancestor of a Binary Search Tree](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/)

题目描述如下：

> Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.
>
> According to the [definition of LCA on Wikipedia](https://en.wikipedia.org/wiki/Lowest_common_ancestor): “The lowest common ancestor is defined between two nodes v and w as the lowest node in T that has both v and w as descendants (where we allow **a node to be a descendant of itself**).”
>
> ```
>         _______6______
>        /              \
>     ___2__          ___8__
>    /      \        /      \
>    0      _4       7       9
>          /  \
>          3   5
>
> ```
>
> For example, the lowest common ancestor (LCA) of nodes `2` and `8` is `6`. Another example is LCA of nodes `2` and `4` is `2`, since a node can be a descendant of itself according to the LCA definition.

题目的意思是寻找两个给定结点的最近祖先，其中这个最近祖先可以是给定的两个结点之一。

在参考了别人的实现方法后，得到的实现代码如下：

```c++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL || root->val == p->val || root->val == q->val ||
        (p->val < root->val && q->val > root->val) ||
        (q->val < root->val && p->val > root->val))
            return root;
        else if (root->val > p->val)
            return lowestCommonAncestor(root->left, p, q);
        else
            return lowestCommonAncestor(root->right, p, q);
    }
};
```

这里首先判断如果是空树，或者当前结点`root`等于给定的两个结点之一，或者是当前结点刚好是处于给定结点的中间值，都可以认为当前结点是所求值，而如果不满足这几个条件，那么再根据当前结点和任意一个给定结点的大小来判断是往左子树结点还是右子树结点进行查找。这个也是因为所求的是二叉查找树，每个结点和其左右孩子结点的大小是排序好的。

##### 10.[Minimum Depth of Binary Tree](https://leetcode.com/problems/minimum-depth-of-binary-tree/)

题目描述如下：

> Given a binary tree, find its minimum depth.
>
> The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

题目是要查找二叉树中最小的深度。

实现代码如下：

```c++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == NULL)
            return 0;
        int lval = minDepth(root->left) + 1;
        int rval = minDepth(root->right) + 1;
        if (lval <= 1 )
            return rval;
        else if (rval <= 1)
            return lval;
        else
            return (lval < rval)? lval : rval;
    }
};
```

这里前面四行代码跟求最大深度的代码是一样的，都是先得到结点的左右子树的深度，然后增加了判断左右子树 的深度是否为小于等于1，因为一开始返回的条件是当前结点是空结点，如果得到的深度是1，那就只有一种情况，这个结点是根结点，否则是不会得到只有深度为1的结果的。

##### 11 [Symmetric Tree](https://leetcode.com/problems/symmetric-tree/)

题目如下：

> Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
>
> For example, this binary tree `[1,2,2,3,4,4,3]` is symmetric:
>
> ```
>     1
>    / \
>   2   2
>  / \ / \
> 3  4 4  3
> ```
>
> But the following `[1,2,2,null,3,null,3]` is not:
>
> ```
>     1
>    / \
>   2   2
>    \   \
>    3    3
> ```

这是一道判断二叉树是否是对称的题目，解法如下：

```c++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return isSymmetric(root, root);
    }
    
    bool isSymmetric(TreeNode* pNode1, TreeNode* pNode2){
        if(pNode1 == NULL && pNode2 == NULL)
            return true;
        
        if(pNode1 == NULL || pNode2 == NULL)
            return false;
        
        if(pNode1->val != pNode2->val)
            return false;
        
        return isSymmetric(pNode1->left, pNode2->right) && 
                isSymmetric(pNode1->right, pNode2->left);
    }
};
```

这是采用前序遍历的方法，而且是比较正常的前序遍历和对称前序遍历的序列是否相同来进行判断，定义的函数`isSymmetric(TreeNode*, TreeNode*)`，就是进行这个判断，左边输入的是正常前序遍历时候的树结点，即先根结点，然后先左结点，再右结点的遍历二叉树，而右边就是对称前序遍历，同样是从根结点开始，接着就是先右结点，再左结点。

##### 12 [Lowest Common Ancestor of a Binary Tree](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/)

题目描述如下：

> Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.
>
> According to the [definition of LCA on Wikipedia](https://en.wikipedia.org/wiki/Lowest_common_ancestor): “The lowest common ancestor is defined between two nodes v and w as the lowest node in T that has both v and w as descendants (where we allow **a node to be a descendant of itself**).”
>
> ```
>         _______3______
>        /              \
>     ___5__          ___1__
>    /      \        /      \
>    6      _2       0       8
>          /  \
>          7   4
> ```
>
> For example, the lowest common ancestor (LCA) of nodes `5` and `1` is `3`. Another example is LCA of nodes `5` and `4` is `5`, since a node can be a descendant of itself according to the LCA definition.

这是求取二叉树中两个结点的最近的公共祖先。解法如下：

```c++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL || p == NULL || q == NULL)
		    return NULL;
    	list<TreeNode*> path1;
    	GetNodePath(root, p, path1);
    
    	list<TreeNode*> path2;
    	GetNodePath(root, q, path2);
    
    	return GetLastCommonNode(path1, path2);
    }
    // 寻找从根结点pRoot开始到达结点pNode的路径
    bool GetNodePath(TreeNode* pRoot, TreeNode* pNode, list<TreeNode*>& path){
        path.push_back(pRoot);
    	if (pRoot == pNode)
    		return true;
    	bool found = false;
    	
    	if (!found && pRoot->left)
    		found = GetNodePath(pRoot->left, pNode, path);
    	if (!found && pRoot->right)
    		found = GetNodePath(pRoot->right, pNode, path);
    	
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
};
```

上述解法是分别对二叉树进行遍历，找到每个结点，并且保存路径，然后再定义一个函数用于比较两个路径，寻找相同的结点，并返回。

更短和更快的解法如下：

```c++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return dfsTraverse(root, p, q);
    }
    TreeNode * dfsTraverse(TreeNode * root, TreeNode * p , TreeNode * q)
    {
        if( root == p || root == q || root == NULL)
            return root;
        TreeNode * parent1 = dfsTraverse(root->left, p, q);
        TreeNode * parent2 = dfsTraverse(root->right, p, q);
        if( parent1 && parent2)
            return root;
        else
            return parent1 ? parent1:parent2;
    }
};
```

这是一个前序遍历的思路，先判断当前结点是否跟任意一个给定结点相同，如果不同，则考虑其左右子结点，如果发现左右子结点都可以返回一个非空结点，那么当前结点就是要求的最近的公共祖先结点，如果有一个非空，那就是非空的结点为最近公共祖先结点。

##### 13 [Binary Tree Paths](https://leetcode.com/problems/binary-tree-paths/)

题目描述如下：

> Given a binary tree, return all root-to-leaf paths.
>
> For example, given the following binary tree:
>
> ```
>    1
>  /   \
> 2     3
>  \
>   5
>
> ```
>
> All root-to-leaf paths are:
>
> ```
> ["1->2->5", "1->3"]
> ```

这是求取二叉树中根结点到叶节点的所有路径。实现代码如下：

```c++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if(root == NULL){
            return res;
        }
        stack<TreeNode*> s;
        stack<string> pathStack;
        s.push(root);
        pathStack.push(to_string(root->val));
        while (!s.empty()) {
            TreeNode * curNode = s.top(); 
            s.pop();
            string tmpPath = pathStack.top(); 
            pathStack.pop();
            if (curNode->left == NULL && curNode->right == NULL) {
                res.push_back(tmpPath); 
                continue;
            }
            
            if (curNode->left != NULL) {
                s.push(curNode->left);
                pathStack.push(tmpPath + "->" + to_string(curNode->left->val));
            }
            
            if (curNode->right != NULL) {
                s.push(curNode->right);
                pathStack.push(tmpPath + "->" + to_string(curNode->right->val));
            }
        } 
        return res;
    }
};
```

上述代码是非递归版本，使用了两个辅助栈，一个栈用来存放结点，一个栈则是保存当前路径值。

递归版本如下：

```c++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if (root == NULL) return res;
        dfs(root, to_string(root->val), res);
        return res;
    }
    
    void dfs(TreeNode* root, string path, vector<string>& res) {
        if (root->left == NULL && root->right == NULL) {
            res.push_back(path);
        }
        
        if (root->left != NULL)
            dfs(root->left, path + "->" + to_string(root->left->val), res);
        
        if (root->right != NULL)
            dfs(root->right, path + "->" + to_string(root->right->val), res);
    }
};
```

使用一个辅助函数实现。

##### 14 [Binary Tree Zigzag Level Order Traversal](https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/)

题目描述如下：

> Given a binary tree, return the *zigzag level order* traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).
>
> For example:
> Given binary tree `[3,9,20,null,null,15,7]`,
>
> ```
>     3
>    / \
>   9  20
>     /  \
>    15   7
>
> ```
>
> return its zigzag level order traversal as:
>
> ```
> [
>   [3],
>   [20,9],
>   [15,7]
> ]
>
> ```

这是打印二叉树，并且是以Z字形打印，即奇数层从左到右打印，偶数层从右到左打印，解法如下：

```c++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root == NULL){
            return res;
        }
        stack<TreeNode*> levels[2];
        int current = 0, next =1;
        
        levels[current].push(root);
        int index = 0;
        vector<int> temp;
        res.push_back(temp);
        while(!levels[0].empty() || !levels[1].empty()){
            TreeNode* pNode = levels[current].top();
            levels[current].pop();
            res[index].push_back(pNode->val);
            if (current == 0){
    			// 当前是奇数层，先压入左子结点，再压入右子节点，则下一层的打印就是从右到左打印
    			if (pNode->left != NULL)
    				levels[next].push(pNode->left);
    			if (pNode->right != NULL)
    				levels[next].push(pNode->right);
    		}
    		else{
    			// 当前是偶数层，先压入右子结点，再压入左子节点，所有下一层就是从左到右打印
    			if (pNode->right != NULL)
    				levels[next].push(pNode->right);
    			if (pNode->left != NULL)
    				levels[next].push(pNode->left);
    		}
    		// 当前层打印完毕
    		if (levels[current].empty()){
    			current = 1 - current;
    			next = 1 - next;
    			index++;
    			vector<int> t;
    			res.push_back(t);
    		}
        }
        if(res[index].empty())
            res.pop_back();
        return res;
    }
};
```

使用栈进行辅助，并且定义两个栈，一个用来保存当前层未打印的结点，剩下的是保存下一层打印顺序的结点，并且保存下一层打印结点的时候要根据当前层是奇数还是偶数层来决定先将左子结点还是右子结点压入栈中。

另一个解法，使用一个队列来解决，如下所示：

```c++
vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
    if (root == NULL) {
        return vector<vector<int> > ();
    }
    vector<vector<int> > result;

    queue<TreeNode*> nodesQueue;
    nodesQueue.push(root);
    bool leftToRight = true;

    while ( !nodesQueue.empty()) {
        int size = nodesQueue.size();
        vector<int> row(size);
        for (int i = 0; i < size; i++) {
            TreeNode* node = nodesQueue.front();
            nodesQueue.pop();

            // find position to fill node's value
            int index = (leftToRight) ? i : (size - 1 - i);

            row[index] = node->val;
            if (node->left) {
                nodesQueue.push(node->left);
            }
            if (node->right) {
                nodesQueue.push(node->right);
            }
        }
        // after this level
        leftToRight = !leftToRight;
        result.push_back(row);
    }
    return result;
}
```

上述解法只需要利用一个队列，然后就是增加一个bool变量来判断当前层是从左到右打印还是从右到左打印，从而决定将从队列取出结点是从队头开始，还是队尾。

##### 15 [Kth Smallest Element in a BST](https://leetcode.com/problems/kth-smallest-element-in-a-bst/)

题目描述如下：

> Given a binary search tree, write a function `kthSmallest` to find the **k**th smallest element in it.
>
> **Note: **
> You may assume k is always valid, 1 ≤ k ≤ BST's total elements.

这是求二叉搜索树第k小的元素，可以利用中序遍历，实现如下：

```c++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        if(root == NULL || k == 0)
            return NULL;
        TreeNode* pNode = getKthSmallest(root, k);
        return pNode->val;
    }
    TreeNode* getKthSmallest(TreeNode* root, int& k){
        TreeNode* target = NULL;
        if(root->left != NULL)
            target = getKthSmallest(root->left, k);
        if(target == NULL){
            if(k==1)
                target = root;
            k--;
        }
        if(target == NULL && root->right != NULL)
            target = getKthSmallest(root->right, k);
        return target;
    }
};
```

中序遍历得到的序列就是一个递增的序列。

##### 16 [Binary Tree Inorder Traversal](https://leetcode.com/problems/binary-tree-inorder-traversal/)

题目描述如下：

> Given a binary tree, return the *inorder* traversal of its nodes' values.
>
> For example:
> Given binary tree `[1,null,2,3]`,
>
> ```
>    1
>     \
>      2
>     /
>    3
>
> ```
>
> return `[1,3,2]`.

这是对二叉树进行中序遍历，下面是迭代版本的实现：

```c++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> nodes;
        std::stack<TreeNode*> toVisit;
        while(1) {
            while(root) { 
                toVisit.push(root); 
                root=root->left; 
            }
            if(toVisit.empty())
                break;
            root=toVisit.top(); 
            toVisit.pop();
            nodes.push_back(root->val);
            root=root->right;
        }
        return nodes;
    }
};
```

迭代版本需要借助栈，首先往栈压入根结点，然后就是压入其所有的左子结点，之后如果根结点的左子结点都遍历完了，就会轮到右子结点。

下面是递归版本的实现：

```c++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> nodes;
        inorder(root, nodes);
        return nodes;
    }
    void inorder(TreeNode* root, vector<int>& nodes) {
        if (!root) return;
        inorder(root -> left, nodes);
        nodes.push_back(root -> val);
        inorder(root -> right, nodes);
    }
};
```

迭代版本实现会简单直观很多。

第三种实现是不需要辅助空间，但是时间复杂度都是$O(n)$，方法称为`Morris traversal`。

```c++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode* curNode = root;
        vector<int> nodes;
        while (curNode) {
            if (curNode -> left) {
                TreeNode* predecessor = curNode -> left;
                while (predecessor -> right && predecessor -> right != curNode)
                    predecessor = predecessor -> right;
                if (!(predecessor -> right)) {
                    predecessor -> right = curNode;
                    curNode = curNode -> left;
                }
                else {
                    predecessor -> right = NULL;
                    nodes.push_back(curNode -> val);
                    curNode = curNode -> right;
                }
            }
            else {
                nodes.push_back(curNode -> val);
                curNode = curNode -> right;
            }
        }
        return nodes;
    }
};
```

这个方法借助了两个辅助指针。具体可以参考[Morris Traversal方法遍历二叉树（非递归，不用栈，O(1)空间）](http://www.cnblogs.com/AnnieKim/archive/2013/06/15/morristraversal.html)。

##### 17 [Binary Tree Postorder Traversal](https://leetcode.com/problems/binary-tree-postorder-traversal/)

题目如下：

> Given a binary tree, return the *postorder* traversal of its nodes' values.
>
> For example:
> Given binary tree `{1,#,2,3}`,
>
> ```
>    1
>     \
>      2
>     /
>    3
>
> ```
>
> return `[3,2,1]`.

这是对二叉树进行后序遍历。递归版本如下：

```c++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if(root == NULL)
            return vector<int>();
        vector<int> r;
        postorder(root, r);
        return r;
    }
    
    void postorder(TreeNode* root, vector<int>& r){
        if(!root)
            return;
        postorder(root->left, r);
        postorder(root->right,r);
        r.push_back(root->val);
    }
};
```

迭代版本如下：

```c++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> nodes;
        stack<TreeNode*> toVisit;
        TreeNode* curNode = root;
        TreeNode* lastNode = NULL;
        while (curNode || !toVisit.empty()) {
            if (curNode) {
                toVisit.push(curNode);
                curNode = curNode -> left;
            }
            else {
                TreeNode* topNode = toVisit.top();
                if (topNode -> right && lastNode != topNode -> right)
                    curNode = topNode -> right;
                else {
                    nodes.push_back(topNode -> val);
                    lastNode = topNode;
                    toVisit.pop();
                }
            }
        }
        return nodes;
    }  
};
```

同样需要使用辅助栈`toVisit`,首先是从根结点开始一直遍历每棵树的左子树，当遇到空结点后，就弹出栈的栈顶结点，然后判断，如果没有右子树，那么就说明是一个最左结点了，可以放到输出的`vector`中，同时记录当前结点；如果上一个结点是当前结点的右子树，那就是该结点是一个子树的根结点，并且轮到要输出该结点的数值了。而如果这两个条件都满足，即有右子树和上一个遍历结点不是当前结点的右子树，则将遍历结点变成当前结点的右子树，进行下一次的遍历了。

##### 18 [Binary Tree Right Side View](https://leetcode.com/problems/binary-tree-right-side-view/)

题目描述如下：

> Given a binary tree, imagine yourself standing on the *right* side of it, return the values of the nodes you can see ordered from top to bottom.
>
> For example:
> Given the following binary tree,
>
> ```
>    1            <---
>  /   \
> 2     3         <---
>  \     \
>   5     4       <---
>
> ```
>
> You should return `[1, 3, 4]`.

这是给定一个二叉树，求每层最右结点。解法如下：

```c++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(root == NULL)
            return vector<int>();
        vector<int> rs;
        queue<TreeNode*> qt;
        qt.push(root);
        while(!qt.empty()){
            rs.push_back(qt.back()->val);
            for(int i=qt.size(); i > 0; i--){
                TreeNode* t = qt.front();
                qt.pop();
                if(t->left)
                    qt.push(t->left);
                if(t->right)
                    qt.push(t->right);
            }
        }
        return rs;
    }
};
```

上述解法是一个迭代版本，利用了`queue`结构来保存每一层的结点，然后遍历完一层结点后，每次都取队列最后一个元素，也就是每层的最右结点。

下面是另一个解法：

```c++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void recursion(TreeNode *root, int level, vector<int> &res)
    {
        if(root==NULL) return ;
        if(res.size()<level) res.push_back(root->val);
        recursion(root->right, level+1, res);
        recursion(root->left, level+1, res);
    }
    
    vector<int> rightSideView(TreeNode *root) {
        vector<int> res;
        recursion(root, 1, res);
        return res;
    }
};
```

这是递归版本，使用一个改进的先序遍历方法，即从根结点开始，然后是右子树，再是左子树，判断是否是要求的最右结点的代码是`res.size() < level`，这里`level`代表所处的层数，因为是先遍历右子树，如果右子树非空，并且`res`中保存的元素数量少于当前层数，说明当前遍历的元素就是要求的数值。

