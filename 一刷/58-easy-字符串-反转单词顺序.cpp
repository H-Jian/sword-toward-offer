#include<unordered_set>
#include<stack>
#include<string>
#include<queue>
#include<list>
#include<deque>
using namespace std;

class Solution {
public:
	string reverseWords(string s) {
		vector<string>rec;
		string res = "";
		string temp = "";
		for (int i = 0; i < s.length(); ++i) {
			if (temp.empty() && s[i] == ' ')continue;
			else if (!temp.empty() && s[i] == ' ') {
				rec.push_back(temp);
				temp.clear();
			}
			else if (s[i] != ' ')
				temp += s[i];
		}
		if (!temp.empty()) {
			rec.push_back(temp);
			temp.clear();
		}
		if (rec.size() > 1) {
			for (int i = rec.size() - 1; i > 0; --i) {
				res = res + rec[i] + " ";
			}
			res = res + rec[0];
		}
		else if (rec.size() == 0)return "";
		else return rec[0];
		return res;
	}
};


//Õ»¼ÇÂ¼

string reverseWords(string s) {
	stack<string>rec;
	string res = "";
	string temp = "";
	for (int i = 0; i < s.length(); ++i) {
		if (temp.empty() && s[i] == ' ')continue;
		else if (!temp.empty() && s[i] == ' ') {
			rec.push(temp);
			temp.clear();
		}
		else if (s[i] != ' ')
			temp += s[i];
	}
	if (!temp.empty()) {
		rec.push(temp);
		temp.clear();
	}
	if (rec.empty())return "";
	while (!rec.empty()) {
		res += rec.top() + " ";
		rec.pop();
	}
	res.pop_back();
	return res;	
}