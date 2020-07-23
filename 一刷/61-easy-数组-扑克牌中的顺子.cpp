#include<unordered_set>
#include<stack>
#include<string>
#include<queue>
#include<list>
using namespace std;

class Solution {
public:
	//一副牌
	bool isStraight(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		if (nums[1] == 0) {
			for (int i = 3; i < 5; ++i) {
				if (nums[i] == nums[i - 1]) return false;
			}
			if (nums[4] - nums[2] < 5) return true;
			else return false;
		}
		else if (nums[0] == 0) {
			for (int i = 2; i < 5; ++i) {
				if (nums[i] == nums[i - 1]) return false;
			}
			if (nums[4] - nums[1] < 5) return true;
			else return false;
		}
		else {
			for (int i = 1; i < 5; ++i) {
				if (nums[i - 1] + 1 != nums[i]) return false;
			}
		}
		return true;
	}
};

//根据0的个数判断是否连续
//根据非零元素是否重复判断
//根据非零元素最大最小值差是否大于4判断
bool isStraight(vector<int>& nums) {
	sort(nums.begin(), nums.end());
	if (nums[3] == 0 || nums[4] == 0)return true;
	else if (nums[2] == 0) {
		if (nums[3] == nums[4]) return false;
		else if (nums[4] - nums[3] < 5)return true;
		else return  false;
	}
	else if (nums[1] == 0) {
		for (int i = 3; i < 5; ++i) {
			if (nums[i] == nums[i - 1]) return false;
		}
		if (nums[4] - nums[2] < 5) return true;
		else return false;
	}
	else if (nums[0] == 0) {
		for (int i = 2; i < 5; ++i) {
			if (nums[i] == nums[i - 1]) return false;
		}
		if (nums[4] - nums[1] < 5) return true;
		else return false;
	}
	else {
		for (int i = 1; i < 5; ++i) {
			if (nums[i - 1] + 1 != nums[i]) return false;
		}
	}
	return true;

}



//代码优化

bool isStraight(vector<int>& nums) {
	sort(nums.begin(), nums.end());
	if (nums[nums.size() - 1] == 0 || nums[nums.size() - 2] == 0)return true;
	int zeroNums = 0;
	int i = 0;
	for (; i < nums.size()-1; ++i) {
		if (0 == nums[i]) zeroNums++;
		else if (nums[i] == nums[i + 1]) return false;
	}
	return (nums[nums.size() - 1] - nums[zeroNums] <= 4);
}

//再优化

bool isStraight(vector<int>& nums) {
	sort(nums.begin(), nums.end());
	//if (nums[nums.size() - 1] == 0 || nums[nums.size() - 2] == 0)return true;
	int zeroNums = 0;
	int i = 0;
	for (; i < nums.size() - 1; ++i) {
		if (0 == nums[i]) zeroNums++;
		else if (nums[i] == nums[i + 1]) return false;
	}
	if (zeroNums == 4 || zeroNums == 5) return true;
	return nums[nums.size() - 1] - nums[zeroNums] <= 4;
}

//不排序，只记录最大最小值和零的个数
//使用set