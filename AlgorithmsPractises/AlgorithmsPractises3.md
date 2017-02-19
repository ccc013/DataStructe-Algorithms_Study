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

#### 题16 [字符移位](https://www.nowcoder.com/question/next?pid=1725829&qid=44802&tid=6474910)

题目描述如下：

> 小Q最近遇到了一个难题：把一个字符串的大写字母放到字符串的后面，各个字符的相对位置不变，且不能申请额外的空间。
> 你能帮帮小Q吗？
>
> **输入描述:**`
> 输入数据有多组，每组包含一个字符串s，且保证:1<=s.length<=1000.
>   `
>
> **输出描述:**`
> 对于每组数据，输出移位后的字符串。
> `
> **输入例子:**`AkleBiCeilD
> `
> **输出例子:**`kleieilABCD`
>

实现方法如下：

```c++
#include<iostream>
#include<string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

void move(string &str){
	int length = str.size();
	char ch;
	int tmp = 0;
	for (int i = 0; i < length - tmp; i++){
		if (isupper(str[i])){
			ch = str[i];
			// 大写字母的字符串都往前移动
			for (int j = i; j < length - 1; j++)
				str[j] = str[j + 1];
			str[length - 1] = ch;
			// 记录移动过的大写字母个数
			tmp++;
			// 继续验证当前移动的字母是否是大写字母
			i--;
		}
	}
}

int main(){
	string input;
	while (cin >> input){
		if (input.size() <= 0)
			break;
		move(input);
		cout << input << endl;
	}

	return 0;
}
```

上述解法是每次遇到大写字母的时候，用一个变量`ch`保存，然后让后面的字符都往前移动一位，并且用一个变量`tmp`保存大写字母的个数，然后将遇到的大写字母保存到字符串的最后一位，并且由于每次循环结束都会让索引`i++`，所以遇到大写字母后需要让`i--`，继续判断移动到当前索引的字母是否为大写字母。

#### 题17 [有趣的数字](https://www.nowcoder.com/questionTerminal/af709ab9ca57430886632022e543d4c6)

题目描述如下：

> 小Q今天在上厕所时想到了这个问题：有n个数，两两组成二元组，差最小的有多少对呢？差最大呢？

解法如下：

```c++
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void result(vector<int>&a, int n);
int main()
{
	int num;
	while (cin >> num)
	{
		int temp;
		vector<int>data;
		for (int i = 0; i < num; ++i)
		{
			cin >> temp;
			data.push_back(temp);
		}
		result(data, num);
	}

	system("pause");
	return 0;
}

void result(vector<int>&a, int n)
{
	if (n > 1)
	{
		sort(a.begin(), a.end());
		// 统计最小值m1和最大值m2分别个数
		int m1 = 1;
		int m2 = 1;
		for (int i = 0; i < n - 1; ++i)
		{
			if (a[i + 1] != a[i])
				break;
			++m1;
		}
		for (int i = n - 1; i > 0; --i)
		{
			if (a[i - 1] != a[i])
				break;
			++m2;
		}
		// 最大差值对 = 最小值个数 * 最大值个数
		int max = m1*m2;

		int min_temp = a[1] - a[0];
		int min = 0;
		// 计算最小差值min_temp
		for (int i = 2; i < n; ++i)
			if (a[i] - a[i - 1] < min_temp)
				min_temp = a[i] - a[i - 1];

		if (min_temp == 0)
		{
			// 最小差值为0的情况说明有重复数字
			for (int i = 1; i < n; ++i)
			{
				int j = i - 1;
				while (j >= 0 && a[j] == a[i])
				{
					++min;
					--j;
				}
			}
		}
		else
		{
			// 最小差值不为0的情况遍历数组，统计等于最小差值的对数
			for (int i = 1; i < n; ++i)
				if (a[i] - a[i - 1] == min_temp)
					++min;
		}
		cout << min << ' ' << max << endl;
	}
}
```

参考别人给出的解答思路：

> 1.先排序
>
> ​	特殊情况：如果排完序之后发现数组中所有数都相同，直接输出结果
>
> ​	结果为：差最大个数 = 差最小个数 = (n*(n-1))/2;(两两组合)
>
> 2.统计数组中每种数字的个数（这里用的map)
>
> 3.计算差最小个数`
>
> * 3.1.如果数组中没有重复数字，说明最小差不为``0``，最小差肯定是数组中相邻两个数的差。因此，遍历一边数组，计算并统计最小差。
>
> 3.2.如果数组中有重复数字，说明最小差是``0``，此时，遍历一边map，数字个数不为``0``的。数字会产生最小差``0``，利用公式计算即可
>
> 4.计算差最大个数
>
> 只有一种情况，最大值与最小值的两两组合，即最大值个数 * 最小值个数

#### 题18 构造回文

题目描述如下：

> 给定一个字符串s，你可以从中删除一些字符，使得剩下的串是一个回文串。如何删除才能使得回文串最长呢？
> 输出需要删除的字符个数。

解法如下：

```c++
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
const int MAX = 1001;
int MaxLen[MAX][MAX]; //最长公共子序列，动态规划求法
int maxLen(string s1, string s2){
    int length1 = s1.size();
    int length2 = s2.size();
    for (int i = 0; i < length1; ++i)
        MaxLen[i][0] = 0;
    for (int i = 0; i < length2; ++i)
        MaxLen[0][i] = 0;
     
    for (int i = 1; i <= length1; ++i)
    {
        for (int j = 1; j <= length2; ++j)
        {
            if (s1[i-1] == s2[j-1]){
                MaxLen[i][j] = MaxLen[i-1][j - 1] + 1;
            }
            else
            {
                MaxLen[i][j] = max(MaxLen[i - 1][j], MaxLen[i][j - 1]);
            }
        }
    }
 
    return MaxLen[length1][length2];
}
 
int main(){
    string s;
    while (cin >> s){
        int length = s.size();
        if (length == 1){
            cout << 1 << endl;
            continue;
        }
        //利用回文串的特点
        string s2 = s;
        reverse(s2.begin(),s2.end());
        int max_length = maxLen(s, s2);
        cout << length - max_length << endl;
    }
    return 0;
}
```

提到回文串，自然要利用回文串的特点，想到将源字符串逆转后，“回文串”（不一定连续）相当于顺序没变
求原字符串和其反串的**最大公共子序列（不是子串，因为可以不连续）的长度（使用动态规划很容易求得）**，然后用原字符串的长度减去这个最大公共子串的长度就得到了最小编辑长度。

