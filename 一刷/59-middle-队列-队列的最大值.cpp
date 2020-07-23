#include<unordered_set>
#include<stack>
#include<string>
#include<queue>
#include<list>
#include<deque>
using namespace std;
class MaxQueue {
	queue<int> q;
	deque<int> d;
public:
	MaxQueue() {
	}
	//不用一个单独的数字来存储最大值，而是使用一个双端队列，维持队列的单调性来保证他的
	//front始终是最大值
	int max_value() {
		if (d.empty())
			return -1;
		return d.front();
	}

	void push_back(int value) {
		while (!d.empty() && d.back() < value) {
			d.pop_back();
		}
		d.push_back(value);
		q.push(value);
	}

	int pop_front() {
		if (q.empty())
			return -1;
		int ans = q.front();
		if (ans == d.front()) {
			d.pop_front();
		}
		q.pop();
		return ans;
	}
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();*/