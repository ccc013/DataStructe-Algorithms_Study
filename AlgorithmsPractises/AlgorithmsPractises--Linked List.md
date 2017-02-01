### AlgorithmsPractises--Linked List

------

记录算法练习中的练习题以及实现的代码，练习题主要是来自[Hihocoder][1]以及[LeetCode](https://leetcode.com/problemset/algorithms/)，主要还是按照级别，由简单到难的顺序练习，并且主要是有关链表的算法题。

#### 1. [Linked List Cycle](https://leetcode.com/problems/linked-list-cycle/)

题目描述如下：

> Given a linked list, determine if it has a cycle in it.
>
> Follow up:
> Can you solve it without using extra space?

这道题目主要是判断链表中是否存在环。实现代码如下：

```c++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *fast = head;
        ListNode *slow = head;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(fast == slow)
                // there is a cycle in the linked list
                return true;
        }
        return false;
    }
};
```

实现的思路主要是使用快慢指针。**快慢指针是判断单链表是否有环的一种方法**：两个指针，每次移动的步长为2叫做快指针，每次移动步长为1的指针叫做慢指针。快慢指针同时从头结点出发，当快指针率先到达NULL的时候，则说明此单链表中不存在环，当快指针追上慢指针的时候，说明此单链表中存在环。

#### 2. [Remove Duplicates from Sorted List](https://leetcode.com/problems/remove-duplicates-from-sorted-list/)

题目描述如下：

> Given a sorted linked list, delete all duplicates such that each element appear only *once*.
>
> For example,
> Given `1->1->2`, return `1->2`.
> Given `1->1->2->3->3`, return `1->2->3`.

实现的代码如下：

```c++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode *p = head->next;
        ListNode *r = head;
        while(p != NULL){
            if(p->val == r->val){
                r->next = p->next;
            }else{
                r->next = p;
                r = p;
            }
            p = p->next;
        }
        return head;
    }
};
```

#### 3. [Remove Duplicates from Sorted List II](https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/)

这是上一题的升级版，难度是中级了，题目描述如下:

> Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only *distinct* numbers from the original list.
>
> For example,
> Given `1->2->3->3->4->4->5`, return `1->2->5`.
> Given `1->1->1->2->3`, return `2->3`.

相比于上一题，这一题是将有重复的元素的节点都要删除。实现代码如下：

```c++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head)
		    return head;
	    ListNode *pre = head;
	    ListNode *p = head;
	    bool isDulplicates = false;
	    int count = 0;
	    while (p && p->next){
		    if (p->next->val == p->val){
			    p = p->next;
			    isDulplicates = true;
    		}
    		else if(p->val != p->next->val && isDulplicates == false){
    			// p所指当前值是一个单独的值，没有重复值
    			ListNode *tmp = new ListNode(p->val);
    			p = p->next;
    			pre->next = tmp;
    			pre = tmp;
    			count++;
    			if (count == 1){
    				head = pre;
    			}
    		}
    		else if (p->val != p->next->val){
    			// p所指的值与后一个值不同，但是它与前一个值相同
    			p = p->next;
    			isDulplicates = false;
    		}
    	}
    	if (!isDulplicates){
    		ListNode *tmp = new ListNode(p->val);
    		pre->next = tmp;
    		pre = tmp;
    	}else if(isDulplicates && count == 0){
    	    return 0;
    	}
    	return (count>0)? head:pre;
    }
};
```

这一题也是花了不少时间完成，第一次完成中级难度的算法题，的确是很有难度，当然可能还是思路上一开始没有找对。这里给出在讨论区看到的另一种实现方法，相对更加简洁，清晰。

```c++
class Solution {
public:
  ListNode* deleteDuplicates(ListNode* head){
    ListNode* pre=NULL;
    ListNode* nxt=NULL,* p=head;
    ListNode* start=new ListNode(0),*h=start;
    if(!head||!head->next)
          return head;
    while(p){
      nxt=p->next;
      // if the node is duplicate, just skip
      if((nxt&&p->val==nxt->val)||(pre&&pre->val==p->val)){
        pre=p;
        p=p->next;
      }else{
        pre=p;
        start->next=p;
        p=p->next;
        start=start->next;
        start->next=NULL;
      }
    }
   	return h->next;
  }
};
```

#### 4. [Reverse Linked List](https://leetcode.com/problems/reverse-linked-list/)

题目描述如下：

> Reverse a singly linked list.

题目意思是需要反转一个链表，实现代码如下：

```c++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head)
            return head;
        ListNode *p = new ListNode(head->val);
        while(head->next){
            ListNode *tmp = new ListNode(head->next->val);
            tmp->next = p;
            p = tmp;
            head=head->next;
        }
        return p;
    }
};
```

上述是自己实现的迭代的方法，下面是找到一个使用递归实现的方法：

```c++
class Solution {
public:   
    ListNode* reverseList(ListNode* head) {
        if (!head || !(head -> next)) return head;
        ListNode* node = reverseList(head -> next);
        head -> next -> next = head;
        head -> next = NULL;
        return node; 
    }
}; 
```

这里通过递归找到链表的最后一个节点，然后再开始反转。

#### 5. [Delete Node in a Linked List](https://leetcode.com/problems/delete-node-in-a-linked-list/)

题目描述如下：

> Write a function to delete a node (except the tail) in a singly linked list, given only access to that node.
>
> Supposed the linked list is `1 -> 2 -> 3 -> 4` and you are given the third node with value `3`, the linked list should become `1 -> 2 -> 4`after calling your function.

题目的意思是删除一个给定的链表中的节点。实现的代码如下：

```c++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        if(!node)
            return;
        while(node->next){
            node->val = node->next->val;
            if (node->next->next)
			    node = node->next;
		    else
			    break;
        }
        node->next = NULL;
    }
};
```

实现的思路主要是将要删除的节点后面的节点往前移动，当移动到倒数第二个节点的时候，就可以退出循环，并将其`next`指针设置为`NULL`，因为最终是要删除一个节点的。

一个代码更少的实现如下：

```c++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        *node = *node->next;
    }
};
```

上述代码等价于：

```c++
node->val = node->next->val;
node->next = node->next->next;
```

#### 6. [Remove Linked List Elements](https://leetcode.com/problems/remove-linked-list-elements/)

题目描述如下：

>Remove all elements from a linked list of integers that have value **val**.
>
>**Example**
>**Given:** 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, **val** = 6
>**Return:** 1 --> 2 --> 3 --> 4 --> 5

实现代码如下：

```c++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(!head)
            return head;
        ListNode *p = head;
        ListNode *pre = head;
        while(p->next){
           if(p->val == val){
               p->val = p->next->val;
               p->next= p->next->next;
           }else{
               pre = p;
               p = p->next;
           }
        }
        if(!p->next && p==head && p->val == val)
            head = NULL;
        else if(p!=head && p->val == val)
            pre->next = NULL;
        
        return head;
    }
};
```

实现思路有点像上一题删除节点，但是这里因为只有节点的数值等于给定数值，才需要删除，所以需要进行判断，同时多声明一个链表指针来指向前一个节点，这是用于如果链表指针到达最后一个节点，并且最后一个节点还是满足删除条件的，那么此时前一个节点的`next`指针应该设置为`NULL`。

#### 7. [Merge Two Sorted Lists](https://leetcode.com/problems/merge-two-sorted-lists/)

题目描述如下：

>  Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

题目的意思是合并两个有序链表。

实现的代码如下：

```c++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1)
            return l2;
        if(!l2)
            return l1;
        ListNode *head = new ListNode(0);
        ListNode *tmp = head;
        while(l1 || l2){
            if(l1 == NULL){
                // l1 is NULL
                tmp->next = l2;
                break;
            }else if(l2 == NULL){
                // l2 is NULL
                tmp->next = l1;
                break;
            }else if(l1->val < l2->val){
                tmp->next = new ListNode(l1->val);
                tmp = tmp->next;
                l1 = l1->next;
            }else{
                tmp->next = new ListNode(l2->val);
                tmp = tmp->next;
                l2 = l2->next;
            }
        }
        return head->next;
    }
};
```

上述解法需要依次判断两个给点的链表是否为空，如果是有空的，则让`tmp`的`next`指针指向非空的链表，否则就依次判断当前两个链表的元素的大小，按照递增的顺序来进行合并。

#### 8  [Insertion Sort List](https://leetcode.com/problems/insertion-sort-list/)

题目描述如下：

> Sort a linked list using insertion sort.

这是使用插入排序来对一个链表进行排序。解法如下：

```c++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode* new_head = new ListNode(0);
        new_head -> next = head;
        ListNode* pre = new_head;
        ListNode* cur = head;
        while (cur) {
            if (cur -> next && cur -> next -> val < cur -> val) {
                while (pre -> next && pre -> next -> val < cur -> next -> val)
                    pre = pre -> next;
                /* Insert cur -> next after pre.*/
                ListNode* temp = pre -> next;
                pre -> next = cur -> next;
                cur -> next = cur -> next -> next;
                pre -> next -> next = temp;
                /* Move pre back to new_head. */
                pre = new_head;
            }
            else cur = cur -> next;
        }
        ListNode* res = new_head -> next;
        delete new_head;
        return res;
    }
};
```

上述解法首先定义一个`new_head`，它是预防有些元素可能会比`head`还要小的情况。插入排序是从链表的第二个元素开始，每次循环的时候，如果当前值都小于前一个结点的数值，就会从`head`开始往后查找比当前元素要大的元素，找到的时候，即代码中`pre->next->val < cur->next->val`条件不成立，此时就将`cur->next`插入到`pre`后面，并让`pre`重新定位到链表的头结点`new_head`。最后返回链表的时候再删除这个头结点即可。

