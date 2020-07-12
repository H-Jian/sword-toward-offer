#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
#include<stack>
using namespace std;


// Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
	vector<int> reversePrint(ListNode* head) {
		stack<int>rec;
		vector<int>res;
		if (!head) return res;
		while (head) {
			rec.push(head->val);
			head = head->next;
		}
		while (!rec.empty()) {
			res.push_back(rec.top());
			rec.pop();
		}
		return res;
	}
};

//递归的本质就是后进先出，和栈相似

vector<int>res;
void helper(ListNode* head) {
	if (!head) return;
	helper(head->next);
	res.push_back(head->val);
}

vector<int> reversePrint(ListNode* head) {
	helper(head);
	vector<int>res2;
	for (int i = 0; i < res.size(); ++i)
		res2.push_back(res[i]);
	return res2;
}
