#include<unordered_set>
#include<stack>
#include<string>
#include<queue>
#include<list>
#include<deque>
using namespace std;

class Solution {
public:
	string reverseLeftWords(string s, int n) {
		int len = s.length();
		n = n % len;
		if (n == 0) return s;
		string res(len, 'a');
		for (int i = 0; i < len - n; ++i)
			res[i] = s[i + n];
		for (int i = 0; i < n; ++i)
			res[i + len - n] = s[i];

		return res;
	}

};


//原地操作
//三次反转
class Solution {
public:
	string reverse(string &s, int head, int end) {
		while (head < end) {
			swap(s[head], s[end]);
			head++;
			end--;
		}
		return s;
	}
	string reverseLeftWords(string s, int n) {
		int len = s.length();
		n = n % len;
		if (n == 0) return s;
		reverse(s, 0, n - 1);
		reverse(s, n, len - 1);
		reverse(s, 0, len - 1);
		return s;
	}
};