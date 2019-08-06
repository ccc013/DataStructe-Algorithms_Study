#include<iostream>

using std::cout;
using std::endl;
using std::cin;

/*��n���������ڵ��ϣ��������ӳ���һ��ĵ���֮��Ϊs������n����ӡ��s�����п��ܵ�ֵ���ֵĸ��ʡ�*/
int g_maxValue = 6;
// ���ڵݹ��ʵ�ַ���
void Probability(int original, int current, int sum, int* pProbabilities){
	if (current == 1){
		pProbabilities[sum - original]++;
	}
	else{
		for (int i = 1; i <= g_maxValue; ++i){
			Probability(original, current - 1, i + sum, pProbabilities);
		}
	}
}

void Probability(int number, int* pProbabilites){
	for (int i = 1; i <= g_maxValue; ++i)
		Probability(number, number, i, pProbabilites);
}
void PrintProbability(int number){
	if (number < 1){
		cout << "number less 1.\n";
		return;
	}
	int maxSum = number * g_maxValue;
	int* pProbabilities = new int[maxSum - number + 1];
	for (int i = number; i <= maxSum; ++i)
		pProbabilities[i - number] = 0;
	Probability(number, pProbabilities);
	// n�����ӵ����е�����������--6^n
	int total = pow((double)g_maxValue, number);
	for (int i = number; i <= maxSum; ++i){
		double ratio = (double)pProbabilities[i - number] / total;
		cout << i << ": " << ratio << "\n";
	}
	delete[] pProbabilities;
}

// ����ѭ����ʵ�֣�ʱ�����ܸ���
void PrintProbability_2(int number){
	if (number < 1){
		cout << "number less 1.\n";
		return;
	}
	int* pProbabilities[2];
	pProbabilities[0] = new int[g_maxValue * number + 1];
	pProbabilities[1] = new int[g_maxValue * number + 1];
	for (int i = 0; i < g_maxValue * number + 1; ++i){
		pProbabilities[0][i] = 0;
		pProbabilities[1][i] = 0;
	}
	int flag = 0;
	for (int i = 1; i <= g_maxValue; ++i)
		pProbabilities[flag][i] = 1;
	for (int k = 2; k <= number; ++k){
		for (int i = 0; i < k; ++i)
			pProbabilities[1 - flag][i] = 0;
		for (int i = k; i <= g_maxValue * k; ++i){
			pProbabilities[1 - flag][i] = 0;
			for (int j = 1; j <= i && j <= g_maxValue; ++j)
				pProbabilities[1 - flag][i] += pProbabilities[flag][i - j];
		}
		flag = 1 - flag;
	}
	int total = pow((double)g_maxValue, number);
	for (int i = number; i <= g_maxValue * number; ++i){
		double ratio = (double)pProbabilities[flag][i] / total;
		cout << i << ": " << ratio << "\n";
	}
	delete[] pProbabilities[0];
	delete[] pProbabilities[1];
}

void Test(int n){
	cout << "Test numbers = " << n << endl;
	cout << "Solution 1 result: \n";
	PrintProbability(n);
	cout << "Solution 2 result : \n";
	PrintProbability_2(n);
}

// ����
int main(void){
	int test[] = { 0, 1, 3, 6, 10 };
	for (int i = 0; i < 5; i++)
		Test(test[i]);
	

	system("pause");
	return 0;
}