#include<unordered_set>
#include<stack>
#include<string>
#include<queue>
#include<list>
using namespace std;

class Solution {
public:
	/*
	Ͷ i �����ӣ�sum �ķ�Χ�� [i, 6*i]
	n �����ӵĸ��ʽ�������� n-1 �����ӵĸ��ʽ���Ƶ��ó�
	*/
	vector<double> twoSum(int n) {
		vector<double>rec(6 * n + 1, 0.0);
		const double p = 1.0 / 6.0;
		for (int i = 1; i <= 6; ++i)
			rec[i] = p ;
		for (int i = 2; i <= n; ++i) {
			for (int j = 6 * i; j >= i; --j) {
				rec[j] = 0;
				for (int k = j - 1; k >= i - 1 && k >= j - 6; --k) {
					rec[j] += (rec[k] * p);
				}
			}
		}
		return vector<double>(rec.begin() + n, rec.end());
	}
};