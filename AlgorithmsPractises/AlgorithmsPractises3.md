### AlgorithmsPractises3

------

#### 题13 字符串反转

[字符串反转](http://www.nowcoder.com/practice/e45e078701ab4e4cb49393ae30f1bb04?tpId=37&tqId=21235&rp=&ru=/ta/huawei&qru=/ta/huawei/question-ranking)来自牛客网上的一道在线编程题目，是华为机试的一道题目，题目描述如下：

> 写出一个程序，接受一个字符串，然后输出该字符串反转后的字符串。例如：
>
> **输入描述：**
>
> > 输入N个字符
>
> **输出描述：**
>
> > 输出该字符串反转后的字符串
>
> **输入例子：**
>
> > abcd
>
> **输出例子**
>
> > dcba

实现代码如下：

```c++
#include<iostream>
#include<string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main(){
	using std::getline;
	string input;
	getline(cin, input);

	int lens = input.size();
	int middle = lens / 2;
	char tmp;
	for (int i = 0; i < middle; i++){	
		tmp = input[i];
		input[i] = input[lens - i - 1];
		input[lens - i - 1] = tmp;
	}
	cout << input << endl;

	return 0;
}
```



#### 题14 [Best Time to Buy and Sell Stock](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/)

题目描述如下：

![](http://7xrluf.com1.z0.glb.clouddn.com/algorithm14.png)

这道题目是给定一个数组，数组的第$i$个元素表示的就是第$i$天股票的价格，现在只可以买进一次和卖出一次，求最大可用获得的利润。

这里需要注意买入的价格是必须小于卖出的，也就是需要注意比较的数组元素的索引顺序。

在参考了讨论区的答案后，给出的代码如下：

```c++
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max = 0;
        int lens = prices.size();
        int sum = 0;
        for(int i=1;i<lens;i++){
            sum += prices[i] - prices[i-1];
            if(sum > max)
                max = sum;
            if(sum < 0)
                sum = 0;
        }
        return max;
    }
};
```

这里是每次记录两个相邻元素的差值，并且是进行累加，如果比保存的最大差值还要大，就修改，否则就继续下一次的比较。这里感觉比较巧妙的就是这个累加，同时如果累加结果为负值就必须重置为0。

还有一种实现方法如下：

```c++
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        if(n < 2) return 0;
        int minval = prices[0];
        int rst=0;
        for(int i = 1; i < n; i++){
            if(prices[i] < minval) minval = prices[i];
            if(prices[i] - minval > rst) rst = prices[i] - minval;
        }
        return rst;
    }
};
```

这里使用`minVal`变量记录前面`i-1`个数组元素中的最小值，然后再跟当前数组元素进行相减求差值。这个思路也是非常赞。

#### 题15  [最大差值](http://www.nowcoder.com/practice/1f7675ae7a9e40e4bd04eb754b62fd00?tpId=49&tqId=29281&rp=1&ru=/ta/2016test&qru=/ta/2016test/question-ranking)

题目描述如下：

> 有一个长为n的数组A，求满足0≤a≤b<n的A[b]-A[a]的最大值。
>
> 给定数组**A**及它的大小**n**，请返回最大差值。
>
> 测试样例：
>
>
> > [10,5],2
> > 返回：0
>

实现代码如下：

```c++
int getDis(vector<int> A, int n) {
        // write code here
        int minVal = A[0];
        int diff = 0;
        for(int i=1;i<n;i++){
            diff = max(diff, A[i]-minVal);
            minVal = min(minVal, A[i]);
        }
        return diff;
    }
```

这道题目跟14题的思路一样，也是需要记录前面已经遍历过的元素中的最小值。这是一个贪心算法的思路。