#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
using namespace std;

class Solution {
public:
	//�ڴ滻ʱ��
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

//���ز�����ֻ���ӿո���Ŀ*2�Ŀռ䣬�Ӻ���ǰ��ֵ