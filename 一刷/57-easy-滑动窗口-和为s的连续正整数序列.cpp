#include<unordered_set>
#include<stack>
#include<string>
#include<queue>
#include<list>
#include<deque>
using namespace std;

class Solution {
public:
	vector<vector<int>> findContinuousSequence(int target) {
		vector<vector<int>>res;
		if (target <= 2)return res;
		vector<int>temp;
		int i = 1, j = 2;
		int sum = 3;
		while (j < target && i<j) {
			if (sum < target) { 
				j++;
				sum += j;
			}
			else if (sum == target) {
					for (int k = i; k <= j; ++k)
						temp.push_back(k);
					res.push_back(temp);
					temp.clear();
					sum = sum - i;
					i++;
					//j++;
					//sum += j;
			}
			else if (sum > target) {
				while (sum > target) {
					sum -= i;
					i++;
				}
				//if (sum == target) {
				//	for (int k = i; k <= j; ++k)
				//		temp.push_back(k);
				//	res.push_back(temp);
				//	temp.clear();
				//	sum = sum - i;
				//	i++;
				//}
				//else if (sum < target) {
				//	j++;
				//	summ += j;
				//}
			}
		}
	}
};