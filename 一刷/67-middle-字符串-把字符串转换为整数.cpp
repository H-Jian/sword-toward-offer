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
	int strToInt(string str) {
		if (str.empty()) return 0;
		queue<int>rec;
		bool flag = true;
		for (char & c : str) {
			if (rec.empty() && (c == ' ' || c == '+')) {
				if (c == '+') rec.push(0);
			}
			else if (rec.empty() && c == '-') {
				flag = false;
				rec.push(0);
			}
			else if (rec.empty() && (c > '9' || c < '0')) return 0;
			else if (c <= '9' && c >= '0') rec.push( c - '0');
			else break;
		}
		if (rec.empty()) return 0;
		int res = 0;
		int bndry = INT_MAX / 10;

		//此判断大数越界的方式很好，每一次判断当前的res是否大于最大数的前几位，再判断当前的cur是否大于等于个位可允许的最大数
		//有优化空间，一趟遍历即可
		while (!rec.empty()) {
			if (res > bndry || (res == bndry && rec.front() >= 8)) {
				return flag ? INT_MAX : INT_MIN;
			}
			res = res * 10 + rec.front();
			rec.pop();
		}
		return flag ? res : -(res);

	}
};