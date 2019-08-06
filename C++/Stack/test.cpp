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

// �����ַ�������
const int MaxLength = 100;
// ����ƥ��
void PrintMatchedPairs(char* expr){
	Stack<int> s(MaxLength);
	int j, length = strlen(expr);
	for (int i = 1; i <= length; i++){
		// ������ɨ���ַ���
		if (expr[i - 1] == '(')
			// ջ����������ŵ�λ������ֵ
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
	// ��ջ��ʣ�µ�( ����δƥ���
	while (!s.IsEmpty()){
		s.Delete(j);
		cout << "No match for left parenthesis at " << j << endl;
	}
}

void testMathedParis(){
	// ��������ƥ��
	char expr[MaxLength];
	cout << "Type an expression of length at most " << MaxLength << endl;
	cin.getline(expr, MaxLength);
	cout << "The pairs of matching parentheses in " << endl;
	puts(expr);
	cout << "are" << endl;
	PrintMatchedPairs(expr);
}

// ��ŵ������,��n�����Ӵ���x�ƶ�����y���ɽ�������z
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
	// �ѳ���ӻ��������������촦��ͬʱ�޸�minS��minH
	// ��������
	int c;
	// �Ӷ�ջminS��ɾ�������С�ĳ���minH
	H[minS].Delete(c);
	cout << "More car " << minH << " from holding track " << minS << " to output\n";
	// ͨ��������е�ջ���������µ�minH��minS
	minH = n + 2;
	for (int i = 1; i <= k; i++){
		if (!H[i].IsEmpty() && (c = H[i].Top()) < minH){
			minH = c;
			minS = i;
		}
	}
}

bool Hold(int c, int& minH, int& minS, LinkedStack<int> H[], int k, int n){
	// ��һ�����������з��복��c,���û�п��õĻ������죬����false������ռ䲻�㣬�������쳣NoMem
	// Ŀǰ���ŵ�����
	int BestTrack = 0;
	// ���������ϵ�ͷ�������
	int BestTop = n + 1;
	// ��������
	int x;
	// ɨ�軺������
	for (int i = 1; i <= k; i++){
		if (!H[i].IsEmpty()){
			x = H[i].Top();
			if (c < x && x < BestTop){
				BestTop = c;
				BestTrack = i;
			}
		}
		else{
			// �����ǿ�
			if (!BestTrack)
				BestTrack = i;
		}
	}
	if (!BestTrack)
		return false;
	// �ѳ���c���뻺������
	H[BestTrack].Add(c);
	cout << "More car " << c << " from input to holding track " << BestTrack << endl;
	// ��Ҫʱ�޸�minH��minS
	if (c < minH){
		minH = c;
		minS = BestTrack;
	}
	return true;
}

// �𳵳�������
bool Railroad(int p[], int n, int k){
	// k���������죬�����ʼ����Ϊp[1:n], ������ųɹ�������true�����򷵻�false������ڴ治�㣬�������쳣NoMem
	// �����ڻ��������Ӧ�Ķ�ջ
	LinkedStack<int> *H = new LinkedStack<int>[k+1];
	// ��һ��Ҫ����ĳ���
	int NowOut = 1;
	// ���������б����С�ĳ���
	int minH = n + 1;
	// minH�ų����Ӧ�Ļ�������
	int minS;
	// ���г�������
	for (int i = 1; i <= n; i++){
		if (p[i] == NowOut){
			// ֱ�����
			cout << "More car " << p[i] << " from input to output" << endl;
			NowOut++;
			while (minH == NowOut){
				Output(minH, minS, H, k, n);
				NowOut++;
			}
		}
		else{
			// ��p[i]����ĳ����������
			if (!Hold(p[i], minH, minS, H, k, n))
				return false;
		}
	}
	return true;
}

bool CheckBox(int net[], int n){
	// ȷ�����غ��Ƿ�ɲ���
	Stack<int> * s = new Stack<int>(n);
	// ˳ʱ��ɨ�������
	for (int i = 0; i < n; i++){
		if (!s->IsEmpty()){
			if (net[i] == net[s->Top()]){
				// net[i]���Բ��ߣ��Ӷ�ջ��ɾ��
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
	// �Ƿ��в��ɲ��ߵ�����
	if (s->IsEmpty()){
		delete s;
		cout << "Switch box is routable\n";
		return true;
	}
	delete s;
	cout << "Switch box is not routable\n";
	return false;
}

int main(){

	/*int p[] = {0,3,6,9,2,4,7,1,8,5};
	Railroad(p, 9, 9);*/

	int net1[] = { 1, 2, 2, 1, 3, 3, 4, 4 };
	CheckBox(net1, 8);
	int net2[] = { 1, 2, 2, 3, 1, 4, 3, 4 };
	CheckBox(net2, 8);

	system("pause");
	return 0;
}

