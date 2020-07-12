#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
using namespace std;

class Solution {
public:
	//����+˫ָ�����
	int findRepeatNumber(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int i = 0, j = 1;
		while (j < nums.size()) {
			if (nums[i++] == nums[j++]) return nums[i];
		}
		return -1;
	}
};


//����Ԫ�ص�Ψһ��
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



//��������
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
				nums[temp] = temp; //�˴�������ʹ��nums[nums[i]] = temp����Ϊnums[i]��ֵ�Ѿ��ı䣬�漰��������λ���Ѿ�������������λ��
			}
		}
		return -1;
	}

};
