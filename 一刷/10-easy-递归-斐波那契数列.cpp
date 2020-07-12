#include<iostream>
#include<vector>
#include<stack>

using namespace std;

class Solution {
public:
	//冗余计算，超出时间限制
	int fib1(int n) {
		if (n == 0 || n == 1) return n;
		return fib1(n - 1) + fib1(n - 2);
	}

	int fib(int n) {
		if (n == 0 || n == 1) return n;
		int res=0;
		int num1 = 0;
		int num2 = 1;
		for (int i = 2; i <= n; ++i) {
			res = (num1 + num2) % 1000000007;
			num1 = num2;
			num2 = res;
		}
		return res;
	}
};