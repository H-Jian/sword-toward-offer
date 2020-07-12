#include<iostream>
#include<vector>
#include<stack>

using namespace std;

class CQueue {
public:
	//stack1支持队列插入，stack2支持队列pop
	stack<int>stack1, stack2;
	CQueue() {
		while (!stack1.empty()) stack1.pop();
		while (!stack2.empty()) stack2.pop();
	}

	void appendTail(int value) {
		stack1.push(value);
	}

	int deleteHead() {
		if (stack1.empty()) return -1;
		while (!stack1.empty()) {
			stack2.push(stack1.top());
			stack1.pop();
		}
		int del = stack2.top();
		stack2.pop();
		while (!stack2.empty()) {
			stack1.push(stack2.top());
			stack2.pop();
		}
		return del;
	}
};