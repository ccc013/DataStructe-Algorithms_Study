#include<iostream>
#include<string>
#include<unordered_map>

using namespace std;

void helper(vector<vector<string>> &res, vector<string> &v, string &str, int begin, int end, unordered_map<string, int> &mymap)
{
	if (begin == end) {
		res.push_back(v);
		return;
	}
	for (int i = 1; i <= end - begin; ++i)
	{
		string tmp = str.substr(begin, i);
		if (mymap.find(tmp) != mymap.end()) {
			v.push_back(tmp);
			helper(res, v, str, begin + i, end, mymap);
			v.pop_back();
		}
	}
}

vector<vector<string>> stringSplit(string &str, vector<string> &legal)
{
	unordered_map<string, int> mymap;
	for (int i = 0; i < legal.size(); i++)
		mymap[legal[i]] = 1;
	vector<vector<string>> res;
	vector<string> v;
	helper(res, v, str, 0, str.length(), mymap);
	return res;
}

int main()
{
	string str = "yourandit";
	vector<vector<string>> res;
	vector<string> legal{ "you", "your", "and", "rand", "it" };
	res = stringSplit(str, legal);
	for (auto x : res) {
		for (auto y : x) {
			cout << y << " ";
		}
		cout << endl;
	}

}