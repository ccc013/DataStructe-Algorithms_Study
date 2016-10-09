# AlgorithmsPractises2

标签（空格分隔）： 算法

---

记录算法练习中的练习题以及实现的代码，练习题主要是来自[Hihocoder][1]。主要还是按照级别，由简单到难的顺序练习。

这是接着[算法练习1][2]的练习题。

##### 题5 Magic Box
  第五题来自[Magic Box][3]，题目描述如下：
  
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


  [1]: http://hihocoder.com/problemset
  [2]: https://github.com/ccc013/DataStructe-Algorithms_Study/blob/master/AlgorithmsPractises/%E7%AE%97%E6%B3%95%E7%BB%83%E4%B9%A01.md
  [3]: http://hihocoder.com/problemset/problem/1135
  [4]: http://7xrluf.com1.z0.glb.clouddn.com/algorithm71.png
  [5]: http://7xrluf.com1.z0.glb.clouddn.com/algorithm72.png