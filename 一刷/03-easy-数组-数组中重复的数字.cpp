#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
using namespace std;

class Solution {
public:
	//排序+双指针遍历
	int findRepeatNumber(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int i = 0, j = 1;
		while (j < nums.size()) {
			if (nums[i++] == nums[j++]) return nums[i];
		}
		return -1;
	}
};


//集合元素的唯一性
class Solution {
public:
	int findRepeatNumber(vector<int>& nums) {
		unordered_set<int>rec;
		for (int &n : nums) {
			if (!rec.insert(n).second)
				return n;
		}
		return -1;
	}

};



//数组特性
class Solution {
public:
	int findRepeatNumber(vector<int>& nums) {
		for (int i = 0; i < nums.size();) {
			if (nums[i] == i) 
				i++;
			else {
				if (nums[i] == nums[nums[i]])
					return nums[i];
				int temp = nums[i];
				nums[i] = nums[temp];
				nums[temp] = temp; //此处不能再使用nums[nums[i]] = temp，因为nums[i]的值已经改变，涉及到第三个位置已经不是两数交换位置
			}
		}
		return -1;
	}

};
