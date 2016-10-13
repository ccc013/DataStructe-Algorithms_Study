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



[1]: http://hihocoder.com/problemset
[2]: https://github.com/ccc013/DataStructe-Algorithms_Study/blob/master/AlgorithmsPractises/AlgorithmsPractises1.md
[3]: http://hihocoder.com/problemset/problem/1135
[4]: http://7xrluf.com1.z0.glb.clouddn.com/algorithm71.png
[5]: http://7xrluf.com1.z0.glb.clouddn.com/algorithm72.png