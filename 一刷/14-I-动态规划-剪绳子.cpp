#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
#include<stack>

using namespace std;

class Solution {
public:
	int cuttingRope(int n) {
		if (n <= 3) return n - 1;
		int front = n / 3;
		int back = n % 3;
		if (back == 0) return pow(3, front);
		if (back == 1) return pow(3, front - 1) * 4;
		return pow(3, front) * 2;
	}
};