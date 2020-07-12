#include<iostream>
#include<vector>
#include<stack>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Solution {
public:
	int hammingWeight(uint32_t n) {
		int res = 0;
		while (n) {
			//if (n & 1)res++;
			res += n & 1;
			n >>= 1;
		}
		return res;
	}
};