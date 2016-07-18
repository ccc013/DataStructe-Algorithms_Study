# 堆栈应用

### 括号的匹配
  括号的匹配就是要匹配一个字符串中的左、右括号。目标是编写一个C++程序，其输入为一个字符串，输出为相互匹配的括号以及未能匹配的括号。注意，括号匹配问题可用来解决C++程序中的{和}的匹配问题。
  
  可以观察到，**如果从左至右扫描一个字符串，那么最近每个右括号将于最近遇到的未匹配的左括号相匹配**。因此，我们可以在从左至右的扫描过程中，把所遇到的左括号放到堆栈内，每当遇到一个右括号时，就将它与栈顶的左括号(如果存在)相匹配，同时从栈顶删除该左括号。
  
  下面给出括号匹配问题实现的代码，其时间复杂性是$\theta(n),其中n$是输入串的长度。
```
// 最大的字符串长度
const int MaxLength = 100;
// 括号匹配
void PrintMatchedPairs(char* expr){
	Stack<int> s(MaxLength);
	int j, length = strlen(expr);
	for (int i = 1; i <= length; i++){
		// 从左到右扫描字符串
		if (expr[i - 1] == '(')
			// 栈中添加左括号的位置索引值
			s.Add(i);
		else if (expr[i - 1] == ')'){
			try{
				s.Delete(j);
				cout << j << " " << i << endl;
			}
			catch (OutOfBounds){
				cout << "No match for right parenthesis" << " at " << i << endl;
			}
		}	
	}
	// 堆栈中剩下的( 都是未匹配的
	while (!s.IsEmpty()){
		s.Delete(j);
		cout << "No match for left parenthesis at " << j << endl;
	}
}
```
测试例子如下：
```
#include<iostream>
#include"xcept.h"
#include"Stack.h"

using std::cout;
using std::endl;
using std::cin;

void testMathedParis(){
	// 测试括号匹配
	char expr[MaxLength];
	cout << "Type an expression of length at most " << MaxLength << endl;
	cin.getline(expr, MaxLength);
	cout << "The pairs of matching parentheses in " << endl;
	puts(expr);
	cout << "are" << endl;
	PrintMatchedPairs(expr);
}

int main(){

	testMathedParis();

	system("pause");
	return 0;
}
```

### 汉诺塔
> 在汉诺塔问题中，已知有n个碟子和3座塔。初始时所有的碟子按从大到小次序从塔1的底部堆放至顶部，我们需要把碟子都移动到塔2，每次移动一个碟子，而且任何时候都不能把大碟放在小碟子的上面。

一个非常优雅的解决办法是使用**递归**。为了把最大的碟子移动到塔2，可以先将其余的n-1个碟子移动到塔3，然后把最大的碟子移动到塔2。接下来是把塔3上的n-1个碟子移动到塔2，因此要借用塔1和塔2，此时可以完全忽视塔2上已经有一个碟子的事实，因为这个碟子是所有碟子中最大的一个。

下面是按照递归方式实现的代码。初始调用的语句是`TowersOfHanoi(n,1,2,3)`
```
// 汉诺塔问题,把n个碟子从塔x移动到塔y，可借助于塔z
void TowersOfHanoi(int n, int x, int y, int z){
    if (n > 0){
        TowersOfHanoi(n - 1, x, z, y);
        cout << "Move top disk from tower " << x << " to top of tower " << y << endl;
        TowersOfHanoi(n - 1, z, y, x);
    }
}
```

