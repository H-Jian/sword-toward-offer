#include<unordered_set>
#include<stack>
#include<string>
#include<queue>
using namespace std;

class Solution {
public:
	int add(int a, int b) {
		while (b){
			int carry = (unsigned int)(a & b) << 1;
			a ^= b;
			b = carry;
		}
		return a;
	}
};