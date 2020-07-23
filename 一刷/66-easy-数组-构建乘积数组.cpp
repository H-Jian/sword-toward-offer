#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
#include<stack>
#include<string>
#include<queue>
using namespace std;

class Solution {
public:
	vector<int> constructArr(vector<int>& a) {
		int size_a = a.size();
		vector<int>res;
		if (size_a < 1)return res;
		if (size_a == 1)return a;
		vector<int> rec1(size_a, 1);
		vector<int> rec2(size_a, 1);
		for (int i = 0; i < size_a - 1; ++i)
		{
			rec1[i + 1] = rec1[i] * a[i];
			//rec2[i]
		}
		for (int i = size_a - 1; i > 0; --i) {
			rec2[i - 1] = rec2[i] * a[i];
		}
		for (int i = 0; i < size_a; ++i)
			res.push_back(rec1[i] * rec2[i]);
		return res;
	}
};


vector<int> constructArr(vector<int>& a) {
	int size_a = a.size();
	vector<int>res;
	if (size_a < 1)return res;
	if (size_a == 1)return a;
	vector<int> rec1(size_a, 1);
	vector<int> rec2(size_a, 1);
	for (int i = size_a - 1; i > 0; --i) {
		rec2[i - 1] = rec2[i] * a[i];
	}
	for (int i = 0; i < size_a; ++i)
	{
		if (i < size_a - 1)rec1[i + 1] = rec1[i] * a[i];
		res.push_back(rec1[i] * rec2[i]);
	}
	return res;
}
