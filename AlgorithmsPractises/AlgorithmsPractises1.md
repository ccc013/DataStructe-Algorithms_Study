# AlgorithmsPractises1

标签（空格分隔）： 算法

---

记录算法练习中的练习题以及实现的代码，练习题主要是来自[Hihocoder][1]。主要还是按照级别，由简单到难的顺序练习。

##### 题1 A+B
  第一题来自[A + B][2]，输入两个整数，输出其相加的结果。题目描述如下：
  
  ![此处输入图片的描述][3]
  
  实现的代码如下：
```
#include<iostream>
using std::cin;
using std::cout;

int main(){
	int a, b;
	while (cin >> a >> b){
		cout << a + b << "\n";
	}

	return 0;
}
```

这题是非常简单的一道题目了。

##### 题2 字符消除
  第二题是[字符消除][4]，描述如下：
  
  ![此处输入图片的描述][5]
  
  ![此处输入图片的描述][6]
  
  这道题目一开始打算使用`char`数组，但是感觉还是不如使用`string`类方面，最终实现代码如下：
  
```
#include<iostream>
#include<string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

// 返回消除的字符数
int getDelStrNums(const string& str){
	int resultNums = 0;
	string tmp(str);
	// 初始字符长度
	int beforeLength = tmp.size();
	// 开始执行消除字符操作
	while (!tmp.empty()){
		string finalStr;
		for (int i = 0; i < tmp.size()-1; i++){
			if (tmp[i] == tmp[i + 1]){
				// 如果连续两个字符相等，则继续判断有连续几个字符相等
				while (i < tmp.size() - 1 && tmp[i] == tmp[i + 1]){
					i++;
				}
			}
			else{
				finalStr.append(1, tmp[i]);
			}
		}
		if (tmp.size() == 1 || tmp[tmp.size() - 2] != tmp[tmp.size() - 1]){
			// 最后一个字符和倒数第二个字符不相等的话
			finalStr.append(1, tmp[tmp.size() - 1]);
		}
		if (tmp.size() == finalStr.size()){
			// 消除前字符长度与执行消除操作后的字符长度相等，说明已经没有字符可以消除
			tmp.clear();
			tmp.assign(finalStr.begin(), finalStr.end());
			break;
		}
		// 分配好剩余字符
		tmp.clear();
		tmp.assign(finalStr.begin(), finalStr.end());
	}

	// 得到最终的消除字符数
	resultNums = beforeLength - tmp.size();

	return resultNums;
}

// 先对输入的字符插入A~C中的一个字符以获得最大的消除字符数
int insertStr(const string& str){
	int maxNums = 0;

	char insertStr[] = { 'A', 'B', 'C' };
	for (int i = 0; i <= str.size(); i++){
		for (int k = 0; k < 3; k++){
			// 轮流插入3个字符中的一个
			string input(str);
			if (i == str.size()){
				// 在输入字符末尾插入一个字符
				input += insertStr[k];
			}
			else{
				input.insert(i, 1, insertStr[k]);
			}
			// 获取消除的总字符数
			int delNums = getDelStrNums(input);
			maxNums = (delNums >= maxNums) ? delNums : maxNums;
		}
	}
	return maxNums;
}

int main(){
	int nums = 0;
	cin >> nums;

	for (int i = 0; i < nums; i++){
		string input;
		cin >> input;
		cout << insertStr(input) << endl;
	}

	system("pause");
	return 0;
}
```

##### 题3 补提交卡
  第三题是[补提交卡][7]，描述如下：
  
  ![此处输入图片的描述][8]
  
  实现代码如下：
```
#include<iostream>
using std::cin;
using std::cout;
using std::endl;

// 计算补交天数后最长连续提交的天数
int getLongestDays(int a[], int n, int m){
	int maxDays = 0;
	if (m >= n)
		// 补交天数大于等于缺交天数时
		maxDays = 100;
	else{
		for (int k = 0; k <= n - 1; k++){
			int days = 0;
			if (k <= m){
				// 少于补交天数的时候
			    days = a[k]-1;
			}
			else if (k == n - m-1){
				days = 100 - a[k]-1;
			}
			else{
				days = a[k] - a[k - m-1]-1;
			}
			maxDays = (days > maxDays) ? days : maxDays;
		}
	}
	return maxDays;
}

int main(){
	int nums = 0;
	cin >> nums;

	for (int i = 0; i < nums; i++){
		// N 是错失提交的天数，M是可以补交的天数
		int N=0, M=0;
		cin >> N >> M;
		int *a = new int[N];
		for (int j = 0; j < N; j++)
			cin >> a[j];
		
		cout << getLongestDays(a, N, M) << endl;
		delete[] a;
	}

	system("pause");
	return 0;
}
```

##### 题4 然而沼跃鱼早就看穿了一切
  第四题来自[然而沼跃鱼早就看穿了一切][9]，其描述如下：
  
  ![此处输入图片的描述][10]
  
  ![此处输入图片的描述][11]
  
  实现的代码如下所示：
```
#include<iostream>
#include<string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

// 转变成小写字母
string transferLower(const string& str){
	string tmp(str);
	for (int i = 0; i < str.size(); i++){
		if (tmp[i] >= 'A' && tmp[i] <= 'Z'){
			tmp[i] -= 'A' - 'a';
		}
	}
	return tmp;
}

// 替换字符串中的"marshtomp"成“fjxmlhx”
string getNewStr(const string& str){
	string newStr(str);
	string result;
	string delStr("marshtomp");
	char replaceStr[] = "fjxmlhx";
	int length = delStr.size();
	int i;
	for (i = 0; i <= str.size()-length; i++){
		string tmp;
		
		// 当前搜索的子串,从目标字符串中当前索引i开始，分配长度为length的子串进行匹配
		tmp.assign(newStr,i,length);
		int index = tmp.find(' ', i);
		if (index >= 0){
			for (int k = i; k <= index; k++)
				result += newStr[k];
			// 存在空格，则搜索索引跳到空格所在索引
			i = index;
		}
		else{
			// 转成小写字母
			tmp = transferLower(tmp);
			if (tmp == delStr){
				// 匹配成功，进行替换
				result.append(replaceStr);
				i += length - 1;
			}
			else{
				// 匹配不成功，添加当前索引的字符，剩余的继续作为下次搜索内容
				result +=newStr[i];
			}
		}
	}
	while (i >= str.size() - length && i < str.size()){
		// 剩余的字符继续输出
		result += newStr[i];
		i++;
	}

	return result;
}

int main(){
	string str;
	while (std::getline(cin, str)){
		cout << getNewStr(str) << endl;
	}
	system("pause");
	return 0;
}
```

这道题目首先是使用`string`类，参考了[标准C++中的string类的用法总结][12]，一开始使用的时候对于`string`类的`assign()`函数是有点使用不正确的，这个函数的作用是进行赋值，开始使用这个函数是一开始搜索出一个长度与目标字符串`marshtomp`长度相同的字符串，然后赋值给一个新声明的`string`对象，初始写的代码是`tmp.assign(newStr[i],newStr[i+length-1]);`,但是发现实际上这样进行赋值是不正确的，这样使用该函数调用的是有迭代器的才可以，所以解决方法是改成上述代码中第31行处的`tmp.assign(newStr,i,length);`,然后需要判断搜索的字符串中是否有空格，有的话就直接跳过，进行下一轮搜索，没有的话，就首先需要将字符串都转成小写字母，再进行比较。最后需要将剩余不足目标字符串长度的字符串输出。


##### 题5 Lost in the City
  第五题来自[Lost in the City][13]，描述如下：
  
  ![此处输入图片的描述][14]
  ![此处输入图片的描述][15]
  
  题目的大致意思是需要输入一个$N \times M$大小的数组，然后再输入3行字符串，每行3个字符，表示的是 Little Hi 所在位置周围的建筑物，这里用的是字母'A'-'Z'和'.'表示的建筑物，并且由于方向也是不知道的，所以比较的时候需要转换这3行字符串的位置。
  
  实现的代码如下：
```
#include<iostream>
#include<string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

// 字符串顺时针旋转90度
void rotate(string str[]){
	string tmp[3];
	for (int i = 0; i < 3; i++)
		tmp[i] = str[i];
	for (int j = 0; j < 3; j++){
		// 新的字符串数组的最后一列是原来字符串数组的第一行
		str[j][2] = tmp[0][j];
		str[j][1] = tmp[1][j];
		str[j][0] = tmp[2][j];
	}
}

int main(){
	using std::getline;
	// 输入地图的大小 n*m
	int n, m;
	cin >> n >> m;
	cin.get();
	// 输入地图的具体内容
	string* map = new string[n];
	for (int m = 0; m < n; m++){
		getline(cin, map[m]);
	}
	// 输入所在点周围的建筑物
	string a[3];
	for (int i = 0; i < 3; i++){
		getline(cin, a[i]);
	}

	// 进行比较，找出所在位置
	if (n>3 && m>3){
		for (int j = 0; j < n - 2; j++){
			for (int k = 0; k < m - 2; k++){
				// 中心位置如果不相等，则直接跳过，往下一行查找
				if (a[1][1] != map[j + 1][k + 1])
					continue;
				// 可能需要旋转4次提供的建筑物位置，才能找出所在点
				for (int i = 0; i < 4; i++){
					if (a[0][0] == map[j][k] && a[0][1] == map[j][k + 1] && a[0][2] == map[j][k + 2]
						&& a[1][0] == map[j + 1][k] && a[1][1] == map[j + 1][k + 1] && a[1][2] == map[j + 1][k + 2]
						&& a[2][0] == map[j + 2][k] && a[2][1] == map[j + 2][k + 1] && a[2][2] == map[j + 2][k + 2]){
						// 找到所在点
						cout << j + 2 << " " << k + 2 << endl;
						break;
					}
					rotate(a);
				}
			}
		}
	}
	
	delete[] map;
	system("pause");
	return 0;
}
```



  [1]: http://hihocoder.com/problemset
  [2]: http://hihocoder.com/problemset/problem/1000
  [3]: http://7xrluf.com1.z0.glb.clouddn.com/algorithm1.png
  [4]: http://hihocoder.com/problemset/problem/1039
  [5]: http://7xrluf.com1.z0.glb.clouddn.com/algorithm2.png
  [6]: http://7xrluf.com1.z0.glb.clouddn.com/algorithm3.png
  [7]: http://hihocoder.com/problemset/problem/1051
  [8]: http://7xrluf.com1.z0.glb.clouddn.com/algorithm4.png
  [9]: http://hihocoder.com/problemset/problem/1082
  [10]: http://7xrluf.com1.z0.glb.clouddn.com/algorithm51.png
  [11]: http://7xrluf.com1.z0.glb.clouddn.com/algorithm52.png
  [12]: http://www.cnblogs.com/xFreedom/archive/2011/05/16/2048037.html
  [13]: http://hihocoder.com/problemset/problem/1094
  [14]: http://7xrluf.com1.z0.glb.clouddn.com/algorithm61.png
  [15]: http://7xrluf.com1.z0.glb.clouddn.com/algorithm62.png