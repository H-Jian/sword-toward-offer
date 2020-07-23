#include<unordered_set>
#include<stack>
#include<string>
#include<queue>
using namespace std;

class Solution {
public:

	//1.记录买入最小值
	//2.记录当前价格和买入最小值的差值，与当前获利作比较，记录当前获利最大值+
	int maxProfit(vector<int>& prices) {
		if (prices.size() <= 1) return 0;
		int cost = INT_MAX, profit = 0;
		for (int price : prices) {
			cost = min(cost, price);
			profit = max(profit, price - cost);
		}
		return profit;
	}
};