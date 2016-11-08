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

> 
>
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

主要是增加了在最后返回`result`前的6行代码，对`result`进行一个反转排序来满足题目的输出要求。

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