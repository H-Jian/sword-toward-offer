#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
using namespace std;

class Solution {
public:
	//内存换时间
	string replaceSpace(string s) {
		string res = "";
		string t;
		t.push_back('%');
		t += "20";
		for (char &c : s) {
			if (c == ' ')
				res += '%';
			else
				res += c;
		}
		return res;
	}
};

//本地操作，只增加空格数目*2的空间，从后向前赋值