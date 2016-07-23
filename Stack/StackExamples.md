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

### 火车车厢重排
> 一列货运列车共有n节车厢，每节车厢将停放在不同的车站。假定 n个车站的编号分别为1~n，货运列车按照第 n站至第1站的次序经过这些车站。车厢的编号与它们的目的地相同。为了便于从列车上卸掉相应的车厢，必须重新排列车厢，使各车厢从前至后按编号 1到n的次序排列。当所有的车厢都按照这种次序排列时，在每个车站只需卸掉最后一节车厢即可。


这里使用k个链表形式的堆栈来描述k个缓冲铁轨。下列函数**Railroad**用于确定重排n个车厢，它最多可使用k个缓冲铁轨并假定车厢的次序为p[1:n]。如果不能成功重排，函数将返回false，否则返回true。具体实现如下所示：
```
// 火车车厢重排
bool Railroad(int p[], int n, int k){
    // k个缓冲铁轨，车厢初始排序为p[1:n], 如果重排成功，返回true，否则返回false，如果内存不足，则引发异常NoMem
    // 创建于缓冲铁轨对应的堆栈
    LinkedStack<int> *H = new LinkedStack<int>[k+1];
    // 下一次要输出的车厢
    int NowOut = 1;
    // 缓冲铁轨中编号最小的车厢
    int minH = n + 1;
    // minH号车厢对应的缓冲铁轨
    int minS;
    // 进行车厢重排
    for (int i = 1; i <= n; i++){
        if (p[i] == NowOut){
            // 直接输出
            cout << "More car " << p[i] << " from input to output" << endl;
            NowOut++;
            while (minH == NowOut){
                Output(minH, minS, H, k, n);
                NowOut++;
            }
        }
        else{
            // 将p[i]送入某个缓冲铁轨
            if (!Hold(p[i], minH, minS, H, k, n))
                return false;
        }
    }
    return true;
}
```

下面则给出函数**Railroad**中使用的函数**Output和Hold**的代码实现，前者主要是用于将一节车厢从缓冲铁轨中输出到出轨处，同时修改minH和minS，而后者则是根据分配规则将车厢c送入某个缓冲铁轨，并在必要的时候修改minH和minS。
```
void Output(int& minH, int& minS, LinkedStack<int> H[], int k, int n){
    // 把车厢从缓冲铁轨送至出轨处，同时修改minS和minH
    // 车厢索引
    int c;
    // 从堆栈minS中删除编号最小的车厢minH
    H[minS].Delete(c);
    cout << "More car " << minH << " from holding track " << minS << " to output\n";
    // 通过检查所有的栈顶，搜索新的minH和minS
    minH = n + 2;
    for (int i = 1; i <= k; i++){
        if (!H[i].IsEmpty() && (c = H[i].Top()) < minH){
            minH = c;
            minS = i;
        }
    }
}

bool Hold(int c, int& minH, int& minS, LinkedStack<int> H[], int k, int n){
    // 在一个缓冲铁轨中放入车厢c,如果没有可用的缓冲铁轨，返回false，如果空间不足，则引发异常NoMem
    // 目前最优的铁轨
    int BestTrack = 0;
    // 最优铁轨上的头辆车厢号
    int BestTop = n + 1;
    // 车厢索引
    int x;
    // 扫描缓冲铁轨
    for (int i = 1; i <= k; i++){
        if (!H[i].IsEmpty()){
            x = H[i].Top();
            if (c < x && x < BestTop){
                BestTop = c;
                BestTrack = i;
            }
        }
        else{
            // 铁轨是空
            if (!BestTrack)
                BestTrack = i;
        }
    }
    if (!BestTrack)
        return false;
    // 把车厢c送入缓冲铁轨
    H[BestTrack].Add(c);
    cout << "More car " << c << " from input to holding track " << BestTrack << endl;
    // 必要时修改minH和minS
    if (c < minH){
        minH = c;
        minS = BestTrack;
    }
    return true;
}
```
上述两个函数Output和Hold的时间复杂性都是$\theta(k)$。而在函数Railroad中的while循环最多可以输出n-1节车厢，else语句也是最多有n-1节车厢被送入缓冲铁轨，因此，这两个函数所消耗的总时间是$O(kn)$。而Railroad函数中for循环部分的其余部分耗时$\theta(n)$,因此该函数的时间复杂性是$O(kn)$。

### 开光盒布线
> 开关盒布线问题是这样的：给定一个矩阵布线区域，其外围有若干针脚。两个针脚之间通过布设一条金属线路而实现互连，这条线路被称为电线，被限制在矩形区域内，此外如果两条电线发现交叉，会发生电流短路，因此不允许电线间的交叉，每对互连的针脚被称为网组。**我们的目标是要确定给定的网组，能否合理地布设电线以使其不发生交叉。**

下面给出代码实现。它要求对每个网组进行编号，并且每个针脚也得有一个对应的网组编号，对于上图c的例子，给定网组是`net=[1,2,2,1,3,3,4,4]`。程序的复杂性是$\theta(n)$,n是针脚的数目。
```
bool CheckBox(int net[], int n){
    // 确定开关盒是否可布线
    Stack<int> * s = new Stack<int>(n);
    // 顺时针扫描各网组
    for (int i = 0; i < n; i++){
        if (!s->IsEmpty()){
            if (net[i] == net[s->Top()]){
                // net[i]可以布线，从堆栈中删除
                int x;
                s->Delete(x);
            }
            else{
                s->Add(i);
            }
        }
        else{
            s->Add(i);
        }
    }
    // 是否有不可布线的网组
    if (s->IsEmpty()){
        delete s;
        cout << "Switch box is routable\n";
        return true;
    }
    delete s;
    cout << "Switch box is not routable\n";
    return false;
}
```

测试例子如下，其中`net1`就是上述图c的例子，而`net2`则是刚说的反例。
```
int main(){
    int net1[] = { 1, 2, 2, 1, 3, 3, 4, 4 };
    CheckBox(net1, 8);
    int net2[] = { 1, 2, 2, 3, 1, 4, 3, 4 };
    CheckBox(net2, 8);

    system("pause");
    return 0;
}
```

