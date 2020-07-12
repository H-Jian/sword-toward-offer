#include<iostream>
#include<vector>
#include<stack>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Solution {
public:
	int cuttingRope(int n) {
		if (n <= 3) return n - 1;
		int a = n / 3, b = n % 3;
		int t = 1;
		for (int i = 0; i < a-1; ++i) {
			t *= 3 % 1000000007;
		}
		if (b == 0) return t * 3 % 1000000007;
		if (b == 1) return t * 4 % 1000000007;
		return (t * 3 % 1000000007) * 2 % 1000000007;
	}
};


class Solution {
public:
	int cuttingRope(int n) {
		vector<long> dp(1001, 0);
		dp[1] = 1;
		dp[2] = 1;
		dp[3] = 2;
		dp[4] = 4;
		dp[5] = 6;
		dp[6] = 9;
		for (int i = 7; i <= n; i++) {
			dp[i] = (dp[i - 3] * 3) % 1000000007;
		}
		return dp[n];
	}
};
