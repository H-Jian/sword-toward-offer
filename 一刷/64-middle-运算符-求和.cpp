#include<unordered_set>
#include<stack>
#include<string>
#include<queue>
using namespace std;


class Solution {
public:
	int add(int a, int b) {
		return b ? add(a^b, (unsigned int)(a&b) << 1) : a;
	}

	int sumNums(int n) {
		n && (n += sumNums(n - 1));
		return n;
	}
};


class Solution {
public:
	int sumNums(int n) {
		int ans = 0, A = n, B = n + 1;

		(B & 1) && (ans += A);
		A <<= 1;
		B >>= 1;

		(B & 1) && (ans += A);
		A <<= 1;
		B >>= 1;

		(B & 1) && (ans += A);
		A <<= 1;
		B >>= 1;

		(B & 1) && (ans += A);
		A <<= 1;
		B >>= 1;

		(B & 1) && (ans += A);
		A <<= 1;
		B >>= 1;

		(B & 1) && (ans += A);
		A <<= 1;
		B >>= 1;

		(B & 1) && (ans += A);
		A <<= 1;
		B >>= 1;

		(B & 1) && (ans += A);
		A <<= 1;
		B >>= 1;

		(B & 1) && (ans += A);
		A <<= 1;
		B >>= 1;

		(B & 1) && (ans += A);
		A <<= 1;
		B >>= 1;

		(B & 1) && (ans += A);
		A <<= 1;
		B >>= 1;

		(B & 1) && (ans += A);
		A <<= 1;
		B >>= 1;

		(B & 1) && (ans += A);
		A <<= 1;
		B >>= 1;

		(B & 1) && (ans += A);
		A <<= 1;
		B >>= 1;

		return ans >> 1;
	}
};

