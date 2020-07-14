#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
#include<stack>
#include<string>
using namespace std;

class Solution {
public:
	bool isMatch(string s, string p) {
		if (s.empty() && p.empty()) return true;
		if (p.empty()) return false;
		if (s.empty()) {
			if (p.size() % 2 != 0) return false;
			int i = 1;
			while (i < p.size()) {
				if (p[i] != '*') return false;
				i += 2;
			}
			return true;
		}
		char c1 = s[0], c2 = p[0];
		char c3 = 'a';
		if (p.size() > 1) c3 = p[1];
		if (c3 != '*') {
			if (c1 == c2 || c2 == '.') {
				return isMatch(s.substr(1), p.substr(1));
			}
			else {
				return false;
			}
		}
		else {
			if (c1 == c2 || c2 == '.') {
				return isMatch(s.substr(1), p) || isMatch(s, p.substr(2));
			}
			else {
				return isMatch(s, p.substr(2));
			}
		}
	}
};