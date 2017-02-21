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

#### 9 [Palindrome Linked List](https://leetcode.com/problems/palindrome-linked-list/)

题目描述如下：

> Given a singly linked list, determine if it is a palindrome.

给定一个单链表，判断其是否是回文。解法如下：

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
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return true;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        slow->next = reverseList(slow->next);
        slow = slow->next;
        while(slow != NULL){
            if(slow->val != head->val)
                return false;
            slow = slow->next;
            head = head->next;
        }
        return true;
    }
    ListNode* reverseList(ListNode* head){
        ListNode* next = NULL;
        ListNode* pre = NULL;
        while(head != NULL){
            next = head->next;
            head->next = pre;
            pre = head;
            head = next;
        }
        return pre;
    }
};
```

这个解法首先是使用快慢指针，当快指针到达链表末尾，慢指针会刚好到达链表中部，此时反转链表后半部分，也就是`slow->next = reverse(slow->next);`所做的工作，然后此时将得到一个从原链表尾部元素为开头，慢慢指向原链表中部元素的指针，也就是用`slow`表示，此时后面一个`while`循环就是进行比较，原链表从头开始和其尾部开始的元素进行比较。

#### 10 [Sort List](https://leetcode.com/problems/sort-list/)

题目描述如下：

> Sort a linked list in *O*(*n* log *n*) time using constant space complexity.

对链表进行排序，要求时间复杂度是$O(nlogn)$。解法如下：

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
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        // divide the list to two parts
        fast = slow->next;
        slow->next = NULL;
        
        return merge(sortList(head), sortList(fast));
    }
    
    ListNode* merge(ListNode* l1, ListNode* l2){
        ListNode* head = new ListNode(0);
        ListNode* tmp = head;
        while(l1 != NULL && l2 != NULL){
            if(l1->val <= l2->val){
                tmp->next = l1;
                l1 = l1->next;
            }else{
                tmp->next = l2;
                l2 = l2->next;
            }
            tmp = tmp->next;
        }
        if(l1 != NULL)
            tmp->next = l1;
        else
            tmp->next = l2;
        return head->next;
    }
};
```

上述解法是使用了归并排序算法，首先使用快慢指针来将链表分成两部分，然后在融合部分就相当于融合两个有序的链表一样。

使用快速排序的解法如下：

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
    void sortListHelper(ListNode* head, ListNode* tail) {
    	if (head -> next == tail) return;
    	/* Partition the list. */
    	ListNode* pre = head;
    	ListNode* cur = head -> next; 
    	ListNode* pivot = cur;
    	while (cur -> next && cur -> next != tail) {		
    		if (pivot -> val > cur -> next -> val) {
    			ListNode* temp = pre -> next;
    			pre -> next = cur -> next;
    			cur -> next = cur -> next -> next;
    			pre -> next -> next = temp;
    		}
    		else cur = cur -> next;
    	}
    	sortListHelper(head, pivot);
    	/* Here is the trick. */
    	while (pivot -> next != tail && pivot -> next -> val == pivot -> val)
    	    pivot = pivot -> next;
    	if (pivot -> next != tail) sortListHelper(pivot, tail);
    } 
    
    ListNode* sortList(ListNode* head) {
    	ListNode* new_head = new ListNode(0);
    	new_head -> next = head;
    	sortListHelper(new_head, NULL);
    	return new_head -> next;
    }
};
```

上述解法首先是新定义一个首节点`new_head`，然后在排序过程中，每次都选第一个结点作为基准点，同时`pre`是保存比基准值小的结点，而`cur`则是正常遍历顺序的指针。然后其中使用的加快速度的地方是跳过重复值的代码，即`while (pivot -> next != tail && pivot -> next -> val == pivot -> val)`。

#### 11 [Intersection of Two Linked Lists](https://leetcode.com/problems/intersection-of-two-linked-lists/)

题目描述如下：

> Write a program to find the node at which the intersection of two singly linked lists begins.
>
> For example, the following two linked lists:
>
> ```
> A:          a1 → a2
>                    ↘
>                      c1 → c2 → c3
>                    ↗            
> B:     b1 → b2 → b3
>
> ```
>
> begin to intersect at node c1.
>
> **Notes:**
>
> - If the two linked lists have no intersection at all, return `null`.
> - The linked lists must retain their original structure after the function returns.
> - You may assume there are no cycles anywhere in the entire linked structure.
> - Your code should preferably run in O(n) time and use only O(1) memory.

这是寻找两个链表的公共结点。解法如下：

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL)
            return NULL;
        int lensA = 1, lensB = 1;
        ListNode* pA = headA,*pB = headB;
        while(pA != NULL){
            lensA++;
            pA = pA->next;
        }
        while(pB != NULL){
            lensB++;
            pB = pB->next;
        }
        pA = headA;
        pB = headB;
        int n = abs(lensA - lensB);
        if(lensA > lensB){
            while(n>0){
                pA = pA->next;
                n--;
            }
        }else{
            while(n>0){
                pB = pB->next;
                n--;
            }
        }
        while(pA != NULL || pB != NULL){
            if(pA == pB)
                return pA;
            pA = pA->next;
            pB = pB->next;
        }
        return NULL;
    }
};
```

上述解法是分别计算两个链表的长度，然后先让长的链表先走出两个链表长度相差的距离，接着再一起进行遍历链表，当两个指针指向公共结点，就返回该结点，否则返回空。

#### 12 [Add Two Numbers II](https://leetcode.com/problems/add-two-numbers-ii/)

题目描述如下：

> You are given two **non-empty** linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
>
> You may assume the two numbers do not contain any leading zero, except the number 0 itself.
>
> **Follow up:**
> What if you cannot modify the input lists? In other words, reversing the lists is not allowed.
>
> **Example:**
>
> ```
> Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
> Output: 7 -> 8 -> 0 -> 7
> ```

题目是给定两个链表，求两个链表相加的结果，并且链表的顺序是高位到低位的顺序。解法如下：

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int n1 = 0, n2 = 0, carry = 0;
        ListNode *cur1 = l1, *cur2 = l2, *res = NULL;
        while(cur1){
            n1++;
            cur1 = cur1->next;
        }
        while(cur2){
            n2++;
            cur2 = cur2->next;
        }
        cur1 = l1;
        cur2 = l2;
        while(n1 > 0 && n2 > 0){
            int sum = 0;
            if(n1 >= n2){
                sum += cur1->val;
                cur1 = cur1->next;
                n1--;
            }
            if(n2 > n1){
                sum += cur2->val;
                cur2 = cur2->next;
                n2--;
            }
            res = addToFront(sum, res);
        }
        cur1 = res;
        res = NULL;
        while(cur1){
            cur1->val += carry;
            carry = cur1->val / 10;
            res = addToFront(cur1->val % 10, res);
            cur2 = cur1;
            cur1 = cur1->next;
            delete cur2;
        }
        if(carry)
            res = addToFront(1, res);
        return res;
    }
    ListNode* addToFront(int val, ListNode* head){
        ListNode* temp = new ListNode(val);
        temp->next = head;
        return temp;
    }
};
```

上述解法首先是分别统计两个链表的长度`n1`和`n2`，然后就开始进行链表相加的操作，这里每次相加后都会将链表长度相减，而且实际上是将新得到的链表`res`是原来链表的一个反转，因为函数`addToFront`就是将新结点插入到当前结点前面，所以相加后得到的链表刚好是一个低位到高位的顺序，接着后面的循环就是解决存在的进位问题，并且再次调整顺序，使得最后的链表就是高位到低位的顺序。

另一个解法：

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int> nums1, nums2;
        while(l1) {
            nums1.push_back(l1->val);
            l1 = l1->next;
        }
        while(l2) {
            nums2.push_back(l2->val);
            l2 = l2->next;
        }
    
        int m = nums1.size(), n = nums2.size();
        int sum = 0, carry = 0;
        ListNode *head = nullptr, *p = nullptr;
        for(int i = m - 1, j = n - 1; i >= 0 || j >= 0 || carry > 0; i--, j--) {
            sum = carry;
            if(i >= 0) 
                sum += nums1[i];
    
            if(j >= 0)
                sum += nums2[j];
    
            carry = sum / 10;
    
            p = new ListNode(sum%10);
            p->next = head;
            head = p;
        }
    
        return head;
    }
};
```

上述解法则是使用两个数组来保存链表的内容，然后相加的时候从数组末尾开始相加，并且重新生成一个新的链表。

#### 13 [Odd Even Linked List](https://leetcode.com/problems/odd-even-linked-list/)

题目描述如下：

> Given a singly linked list, group all odd nodes together followed by the even nodes. Please note here we are talking about the node number and not the value in the nodes.
>
> You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.
>
> **Example:**
> Given `1->2->3->4->5->NULL`,
> return `1->3->5->2->4->NULL`.
>
> **Note:**
> The relative order inside both the even and odd groups should remain as it was in the input. 
> The first node is considered odd, the second node even and so on ...

给定一个链表，要求将偶数位置放到奇数位置后面。解法如下：

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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL)
            return head;
        int lens=0;
        ListNode* cur = head, *pre = head, *last = NULL;
        while(cur != NULL){
            lens++;
            cur = cur->next;
            if(cur != NULL && cur->next == NULL)
                last = cur;
        }
        if(lens == 1 || lens == 2)
            return head;
        cur = head->next;
        int nums = lens/2;
        while(nums>0){
            // put cur insert to last node
            ListNode* tmp = cur->next;
            pre->next = tmp;
            pre = tmp;
            last->next = cur;
            cur->next = NULL;
            last = cur;
            if(pre != NULL)
                cur = pre->next;
            nums--;
        }
        return head;
    }
};
```

上述解法主要是每次将偶数位置的结点插入到链表末端，而循环次数就是偶数位置的个数，需要创建三个指针，`pre`是前驱指针，是指向当前指针`cur`的前一个指针，然后`last`指针指向链表末尾的结点，这里需要注意链表只有1个或者两个结点的时候，直接返回链表即可。然后在循环中注意`pre`可能是一个空指针，再将`cur`指针重新指向下一个偶数位置时，需要判断`pre`是否为空。

另一个更简洁的解法如下：

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
    ListNode* oddEvenList(ListNode* head) {
        if(!head) 
            return head;
        ListNode *odd=head, *evenhead=head->next, *even = evenhead;
        while(even && even->next)
        {
            odd->next = odd->next->next;
            even->next = even->next->next;
            odd = odd->next;
            even = even->next;
        }
        odd->next = evenhead;
        return head;
    }
};
```

这个解法分别创建两个指针`odd`和`even`作为奇数结点和偶数结点的指针，然后在循环的时候，分别将奇数结点和偶数结点放到这两个指针后面，最后再将偶数结点放到奇数结点后面即可。

#### 14 [Remove Nth Node From End of List](https://leetcode.com/problems/remove-nth-node-from-end-of-list/)

题目描述如下：

> Given a linked list, remove the *n*th node from the end of list and return its head.
>
> For example,
>
> ```
>    Given linked list: 1->2->3->4->5, and n = 2.
>
>    After removing the second node from the end, the linked list becomes 1->2->3->5.
>
> ```
>
> **Note:**
> Given *n* will always be valid.
> Try to do this in one pass.

这是要删除倒数第N个结点。解法如下：

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL || head->next == NULL)
            return NULL;
        int lens = 0;
        ListNode *cur = head;
        ListNode *new_head = new ListNode(0);
        new_head->next = head;
        while(cur != NULL){
            lens++;
            cur = cur->next;
        }
        int k = lens - n;
        if(k==0){
            new_head->next = head->next;
            head->next = NULL;
            delete head;
            return new_head->next;
        }
        cur = head;
        int i=1;
        while(i != k && cur){
            cur = cur->next;
            i++;
            
        }
        if(i == k){
            ListNode* tmp = cur->next;
            cur->next = tmp->next;
            if(tmp->next != NULL)
                tmp->next = NULL;
        }
        return head;
    }
};
```

上述解法先得到链表长度`lens`，然后得到被删除前的结点所在的位置`k = lens-n`，如果`k == lens`，也就是删除链表第一个结点，所以需要先创建一个新结点指向头结点，即`new_head`，而如果不等于，则先遍历链表，找到被删除结点的前一个结点，然后就可以删除其后面的结点。

另一个解法：

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head)
        	return nullptr;

        ListNode new_head(-1);
        new_head.next = head;
        ListNode *slow = &new_head, *fast = &new_head;
        for (int i = 0; i < n; i++)
            fast = fast->next;
    
        while (fast->next) 
        {
            fast = fast->next;
            slow = slow->next;
        }
        ListNode *to_be_deleted = slow->next;
        slow->next = slow->next->next;
        
        delete to_be_deleted;
        return new_head.next;
    }
};
```

上述解法创建了两个指针`fast`和`slow`，并先让`fast`走了`n`步，接着让两个指针同时走，则当`fast`走到末尾的时候，`slow`走到被删除结点的前一个结点。

#### 15 