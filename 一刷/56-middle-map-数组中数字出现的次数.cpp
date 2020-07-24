#include<unordered_set>
#include<stack>
#include<string>
#include<queue>
#include<list>
#include<deque>
#include<unordered_map>
using namespace std;

class Solution {
public:
	int singleNumber(vector<int>& nums) {
		if (nums.size() == 1) return nums[0];
		else if (nums.size() <= 3) return 0;
		sort(nums.begin(), nums.end());
		int i = 0, j = 2;
		while (j < nums.size()) {
			if (nums[i] == nums[j]) {
				i += 3;
				j += 3;
			}
			else return nums[i];
		}
		return nums[i];
	}
};

//class unorderedMap_value_finder {
//public:
//	unorderedMap_value_finder(int &temp) :num(temp) {};
//	int operator () (const std::unordered_map<int, int>::value_type &pair) {
//		if (pair.second.compare(num) == 1)
//			return pair.first;
//	}
//public:
//	const int num;
//};
//
//int singleNumber(vector<int>& nums) {
//	if (nums.size() == 1) return nums[0];
//	else if (nums.size() <= 3) return 0;
//	unordered_map<int, int>rec;
//	for (int &num : nums) {
//		if (rec.find(num) == rec.end())
//			rec[num] = 1;
//		else
//			rec[num]++;
//	}
//	
//	return (*(find_if(rec.begin(), rec.end(), 1))).first;
//}
