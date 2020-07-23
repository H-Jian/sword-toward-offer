#include<unordered_set>
#include<stack>
#include<string>
#include<queue>
#include<list>
using namespace std;

class Solution {
public:
	//һ����
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

//����0�ĸ����ж��Ƿ�����
//���ݷ���Ԫ���Ƿ��ظ��ж�
//���ݷ���Ԫ�������Сֵ���Ƿ����4�ж�
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



//�����Ż�

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

//���Ż�

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

//������ֻ��¼�����Сֵ����ĸ���
//ʹ��set