#include<iostream>
#include<ctime>
#include"xcept.h"
#include"Stack.h"
#include"llist.h"
#include"LinkedStack.h"
#include"Hanoi.h"

using std::cout;
using std::endl;
using std::cin;

void testStack(){
	Stack<int> stack1(10);
	cout << "show a empty stack\n";
	cout << stack1;
	for (int i = 0; i < 10; i++)
		stack1.Add(i + 2);
	cout << "stack is Full?\n";
	if (stack1.IsFull())
		cout << "Yes\n";
	else
		cout << "No\n";
	cout << "show Stack1\n";
	cout << stack1;
	
	int x;
	stack1.Delete(x);
	cout << "pop stack1, it is " << x << ".The remain elements are\n";
	cout << stack1;

}

void testLinkedStack(){
	LinkedStack<int> stack1;
	cout << "show a empty stack\n";
	cout << stack1;
	for (int i = 0; i < 10; i++)
		stack1.Add(i + 5);
	cout << "stack is Full?\n";
	if (stack1.IsFull())
		cout << "Yes\n";
	else
		cout << "No\n";
	cout << "show Stack1\n";
	cout << stack1;

	int x;
	stack1.Delete(x);
	cout << "pop stack1, it is " << x << ".The remain elements are\n";
	cout << stack1;

}

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

// 汉诺塔问题,把n个碟子从塔x移动到塔y，可借助于塔z
void TowersOfHanoi(int n, int x, int y, int z){
	if (n > 0){
		TowersOfHanoi(n - 1, x, z, y);
		cout << "Move top disk from tower " << x << " to top of tower " << y << endl;
		TowersOfHanoi(n - 1, z, y, x);
	}
}

void testTowersOfHanoi(){
	useTowersOfHanoi(2);
}
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


int main(){

	int p[] = {0,3,6,9,2,4,7,1,8,5};
	Railroad(p, 9, 9);

	system("pause");
	return 0;
}

