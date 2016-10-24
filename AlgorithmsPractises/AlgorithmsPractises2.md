# AlgorithmsPractises2

标签（空格分隔）： 算法

---

记录算法练习中的练习题以及实现的代码，练习题主要是来自[Hihocoder][1]以及[LeetCode](https://leetcode.com/problemset/algorithms/)，主要还是按照级别，由简单到难的顺序练习。

这是接着[AlgorithmsPractises1][2]的练习题。

------

##### 题6  Magic Box
  第6题来自[Magic Box][3]，题目描述如下：

  ![此处输入图片的描述][4]
  ![此处输入图片的描述][5]

  这是求一个盒子中曾经拥有的最大的球的个数的问题。首先是有红、蓝、黄三种颜色的球，输入的第一行是3个整数--x、y和z，分别代表3种颜色球的数量差值，第二行是依次放球到盒子中的顺序，用字符'R','Y','B'分别表示三种颜色的球，当三种球的数量之差分别等于x,y,z时，盒子中的球就会消失，然后如果还需要继续放球，就会继续放，否则就结束，并输出盒子中曾经拥有的最大的球的个数。

  

实现的代码如下：

```
#include<iostream>
#include<string>
#include<unordered_map>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int getMaxBallNums(string & str, int x, int y, int z){
	int max = 0;
	char colors[] = { 'R', 'B', 'Y' };
	// 三个颜色的球分别的数量
	int Cr, Cb,Cy ;
	// 不同颜色球之间数量差值
	int d_rb, d_ry, d_by;
	Cr = Cb = Cy = 0;
	d_rb = d_ry = d_by = 0;
	// 当前盒子中球的总数
	int currentNums = 0;
	// 判断是否达到球消失的标志
	bool isVanished = false;

	std::unordered_map<int, int> map;
	// 使用hash_map 保存
	map[x] = 0;
	map[y] = 1;
	map[z] = 2;
	// 确认有效键值个数
	int keys = map.size();

	for (int i = 0; i < str.size(); i++){
		std::unordered_map<int, int> tmp = map;
		if (str[i] == colors[0])
			Cr++;
		else if (str[i] == colors[1])
			Cb++;
		else if (str[i] == colors[2])
			Cy++;

		currentNums++;
		if (Cr>0 || Cb > 0 || Cy > 0){
			// 计算不同颜色球的差值
			d_rb = (Cr > Cb) ? (Cr - Cb) : (Cb - Cr);
			d_ry = (Cr > Cy) ? (Cr - Cy) : (Cy - Cr);
			d_by = (Cb > Cy) ? (Cb - Cy) : (Cy - Cb);

			// 进行匹配，是否达到消失球的条件
			if (tmp.find(d_rb) != tmp.end() && tmp.find(d_ry) != tmp.end()
				&& tmp.find(d_by) != tmp.end()){
				if (keys == 3 && d_rb != d_ry && d_rb != d_by && d_ry != d_by){
					// 3个差值都不相同
					isVanished = true;
				}
				else if(keys == 1 || keys == 2){
					isVanished = true;
				}
			}
			if (isVanished){
				// 成功匹配
				max = (max > currentNums) ? max : currentNums;
				// 清空球的总数以及各色球的数量
				currentNums = 0;
				Cb = Cy = Cr = 0;
				isVanished = false;
			}	
		}
	}
	if (currentNums>0)
		max = (max > currentNums) ? max : currentNums;
	return max;
}

int main(){
	using std::getline;
	int x, y, z;
	cin >> x >> y >> z;
	cin.get();

	string balls;
	getline(cin, balls);
	cout << getMaxBallNums(balls, x, y, z) << endl;
	
	system("pause");
	return 0;
}
```

------

##### 题7 [Rotate Function](https://leetcode.com/problems/rotate-function/) 

这道题目是来自`LeetCode`上的题目。题目描述如下：

![](http://7xrluf.com1.z0.glb.clouddn.com/QQ%E6%88%AA%E5%9B%BE20161011192004.png)



这道题目需要注意的是时间问题，如果直接进行计算，即如下所示：

```
int maxRotateFunction(vector<int>& A) {
        int maxVal;
        int n = A.size();
        for(int i=0;i<n;i++){
            int val=0;
            for(int j=1;j<n;j++){
                val += j * A[(j+i)%n];
            }
            if(i==0)
                maxVal = val;
            else
                maxVal = (maxVal > val)? maxVal : val;
        }
        return maxVal;
    }
```

那么时间复杂度是$O(n^2)$,会出现**Time Limit Exceeded**，即运行时间太长，毕竟题目中的`n`值最多可以等于10000，所以这里需要重新看看题目，找出规律，这里参考了讨论区中的[代码](https://discuss.leetcode.com/topic/62581/c-codes-with-clear-formula-explanation-75-61)，其思路如下图所示：

![](http://7xrluf.com1.z0.glb.clouddn.com/algorithm8.png)

因此最终实现的代码如下所示：

```
class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        int maxVal;
        int n = A.size();
        int tmp = 0,sum=0;
        for(int i=0;i<n;i++){
            sum += A[i];
            tmp += i * A[i];
        }
        maxVal = tmp;
        for(int i=1;i<n;i++){
            tmp = sum + tmp - n * A[n-i];
            maxVal = max(maxVal,tmp);
        }
        return maxVal;
    }
};
```

对于算法题，首先当然要能解决问题，即能输出期望的结果，然后就要考虑时间复杂度的问题，尽可能使用更短的时间和更少的内存解决问题。

##### 题8 [Add Two Numbers](https://leetcode.com/problems/add-two-numbers/)

第八题来自`LeetCode`，描述如下：

![](http://7xrluf.com1.z0.glb.clouddn.com/algorithm9.png)

这道题目是用单链表来存储非负整数，并且相加的时候，如果结果大于10，需要进位。

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int add = 0;
        ListNode* res = new ListNode(0);
        ListNode *p,*r;
        r = res;
        while(l1 || l2 || add){
            p = new ListNode(add);
            if(l1){
                p->val += l1->val;
                l1 = l1->next;
            }
            if(l2){
                p->val += l2->val;
                l2 = l2->next;
            }
            add = p->val / 10;
            p->val %= 10;
           
            r->next = p;
            r = p; 
        }
        
        return res->next;
    }
```
这里首先要了解单链表的使用，需要先创建一个头结点，然后创建一个链表指针，并且这里还要注意输入的两个链表长度可以是不一样的。

同时在讨论区看到一个实现方法更加简洁，并且更加快的[代码](https://discuss.leetcode.com/topic/53268/efficient-and-clean-iterative-and-recursive-solutions-in-c)：

```c++
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        int c = 0;
        ListNode newHead(0);
        ListNode *t = &newHead;
        while(c || l1 || l2)
        {
            c += (l1? l1->val : 0) + (l2? l2->val : 0);
            t->next = new ListNode(c%10);
            t = t->next;
            c /= 10;
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }
        return newHead.next;
    }
};
```

##### 题9 [ZigZag Conversion](https://leetcode.com/problems/zigzag-conversion/) 

第九题继续来自`LeetCode`,题目描述如下：

![](http://7xrluf.com1.z0.glb.clouddn.com/algorithm10.png)

这道题目是将输入的字符串按照`Z`字形排列，然后逐行打印出来，需要找规律。在第一行和最后一行，每个字符相差`2*nRows-2`，而在中间的每行中，都会还有一个字符要相加，相差的就是`2*(nRows-i)-2`，即如题目给出的例子中，中间一行，`A`和`P`的差距是`2*(3-1)-2 = 2`,`A`的索引值是1，而`P`的索引值是3，然后`L`和`S`的差距也是2。因此实现的代码如下：

```c++
class Solution {
public:
    string convert(string s, int numRows) {
        int len = s.size();
        if (len <=1 || numRows < 2)
            return s;
        
        // 行的循环周期
        int cyc = 2*numRows - 2;
        string res;
        for(int i=0;i<numRows;i++){
            for(int j=i;j<len;j += cyc){
                res += s[j];
                
                // 非首行和末行要多加一个
                if(i>0 && i< numRows - 1){
                    int t = j + cyc - 2*i;
                    if(t<len){
                        res+= s[t];
                    }
                }
            }
        }
        return res;
    }
};
```
这道题目关键点还是找到每行的字符索引的差值的规律，特别是注意非首行和末行的字符。



##### 题10 [Reverse Integer](https://leetcode.com/problems/reverse-integer/)

题目描述如下：

![](http://7xrluf.com1.z0.glb.clouddn.com/algorithm11.png)

这道题目是将输入的整数要反转输出，需要注意这里输入的整数是`int`类型，它是一个32位数，会有溢出的情况，其最大值`INT_MAX = 2147483647`，最小值`INT_MIN=-2147483647`。

```c++
class Solution {
public:
    int reverse(int x) {
        long result = 0;
        while(x != 0){
            result = result * 10 + x % 10;
            if(result > INT_MAX || result < INT_MIN)
                return 0;
            x = x / 10;
        }
        return result;
    }
};
```
一开始做的时候没有将代码中的`result`设置为`long`类型，而是设置为`int`类型，所以遇到输入值是`1147483647`这种正常是不会溢出，但是倒过来后就溢出的测试值，总是出错，而且输出值也很奇怪，然后才发现是因为`result`已经溢出了。

不过上述代码的运行时间依然还是需要约9ms，而如果对整数进行正负的判断，则可以提高运行时间到约6ms.

```c++
class Solution {
public:
    int reverse(int x) {
        long result = 0;
        bool flag = false;
        if(x < 0){
            x = -x;
            flag = true;
        }
        while(x != 0){
            result = result * 10 + x % 10;
            if(result > INT_MAX || result < INT_MIN)
                return 0;
            x = x / 10;
        }
        if(flag)
            result = -result;
        return result;
    }
};
```

##### 题11 [Remove Element](https://leetcode.com/problems/remove-element/)

第六题的题目描述如下：

![](http://7xrluf.com1.z0.glb.clouddn.com/algorithm12.png)

给定一个数组和一个数值，要求是数组在去除给定的数值后，返回新的数组的长度。这里要求不能使用另一个数组，即对存储空间有要求，然后元素的顺序可以改变。实现代码如下：

```c++
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int len = nums.size();
        // 非目标数值的数量
        int j = 0;
        for(int i=0;i<len;i++){
            if(nums[i] != val)
                nums[j++] = nums[i];
        }
        return j;
    }
};
```

这题使用一个额外的`j`作为表示保留的数组元素的个数。

##### 题12 [Rotate Array](https://leetcode.com/problems/rotate-array/)

题目描述如下：

![](http://7xrluf.com1.z0.glb.clouddn.com/algorithm13.png)

这道题目就是根据输入的`k`值移动数组的元素，其实比较简单，难点是能否只在空间复杂度是$O(1)$的情况下完成，即不需要使用额外的数组。

我的第一种实现，采用一个额外的数组进行辅助：

```c++
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int lens = nums.size();
        vector<int> tmp = nums;
        for(int i=0;i<lens;i++){
            nums[(i+k)%lens] = tmp[i];
        }
    }
};
```

这种实现方法优点是时间更快，根据提交后的结果显示，耗时16ms，在所有提交的C++版本中排在前5%左右，缺点就是需要$O(n)$的存储空间。

下面则是给出不需要额外的辅助空间，但是耗时相对较长的实现方案：

```c++
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int lens = nums.size();
        int rotated = 0;
        for(int i=0;i<k;i++){
            int start = i;
            int startVal = nums[start];
            int to = 0;
            do{
                to = (start + k) % lens;
                int tmp = nums[to];
                nums[to] = startVal;
                // 保存被替换位置的元素和索引
                start = to;
                startVal = tmp;
                rotated++;
            }while(start != i);
            if(rotated == lens)
                break;
        }
    }
};
```
这种实现方法耗时19ms,排名前40%左右。实现的思路是根据输入的`k`可以知道实际上有前k个数组元素需要向右进行移动，所以最外层的循环是循环`k`次，然后每次循环中，根据`(start + k) % lens`找到每个元素移动到的新位置，然后保存该位置的索引值和元素值，作为`while`循环的下一次循环使用；然后用一个变量`rotated`记录进行移动的元素个数，当它等于数组长度时，表示所有的数组元素都经过一次移动，可以终止整个函数了。

[1]: http://hihocoder.com/problemset
[2]: https://github.com/ccc013/DataStructe-Algorithms_Study/blob/master/AlgorithmsPractises/AlgorithmsPractises1.md
[3]: http://hihocoder.com/problemset/problem/1135
[4]: http://7xrluf.com1.z0.glb.clouddn.com/algorithm71.png
[5]: http://7xrluf.com1.z0.glb.clouddn.com/algorithm72.png