#include<unordered_set>
#include<stack>
#include<string>
#include<queue>
#include<list>
#include<deque>
using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int>res;
		int i = 0, j = nums.size() - 1;
		while (i < j) {
			int sum = nums[i] + nums[j];
			if (sum == target) return vector<int>{nums[i], nums[j]};
			else if (sum > target) j--;
			else if (sum < target) i++;
		}
		return res;
	}
};