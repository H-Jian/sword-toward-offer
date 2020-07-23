#include<unordered_set>
#include<stack>
#include<string>
#include<queue>
#include<list>
#include<deque>
using namespace std;

class Solution {
public:
	//时间复杂度高
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		if (k == 1)return nums;
		int j = k - 1;
		int i = 0;
		int maxNum = INT_MIN;
		vector<int>rec;
		while (j < nums.size()) {
			for (; i <= j; ++i) {
				maxNum = max(maxNum, nums[i]);
			}
			rec.push_back(maxNum);
			j++;
			i = j - k + 1;
			maxNum = INT_MIN;

		}
		return rec;
	}
};

class Solution {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		vector<int> ans;
		deque<int> deq;
		int n = nums.size();
		for (int i = 0; i < n; i++) {
			//新元素入队时如果比队尾元素大的话就替代队尾元素
			while (!deq.empty() && nums[i] > nums[deq.back()]) {
				deq.pop_back();
			}
			//检查队首的index是否在窗口内，不在的话需要出队
			if (!deq.empty() && deq.front() < i - k + 1) deq.pop_front();
			deq.push_back(i);
			if (i >= k - 1) ans.push_back(nums[deq.front()]);
		}
		return ans;
	}
};