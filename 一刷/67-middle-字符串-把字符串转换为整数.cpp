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

		//���жϴ���Խ��ķ�ʽ�ܺã�ÿһ���жϵ�ǰ��res�Ƿ�����������ǰ��λ�����жϵ�ǰ��cur�Ƿ���ڵ��ڸ�λ������������
		//���Ż��ռ䣬һ�˱�������
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