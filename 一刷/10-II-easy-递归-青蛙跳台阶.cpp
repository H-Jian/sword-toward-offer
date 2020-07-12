#include<iostream>
#include<vector>
#include<stack>
#include<unordered_map>
using namespace std;

class Solution {
public:
	int numWays(int n) {
		if (n == 1 || n == 2 || n == 0) return n;
		return numWays(n - 1) + numWays(n - 2);
	}
};
int numWays(int n) {
	if (n == 1 || n == 2 || n == 0) return n;
	int res = 0;
	int num1 = 1;
	int num2 = 2;
	for (int i = 3; i <= n; ++i) {
		res = (num1 + num2) % 1000000007;
		num1 = num2;
		num2 = res;
	}
	return res;
}

