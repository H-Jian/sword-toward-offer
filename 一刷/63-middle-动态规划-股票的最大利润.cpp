#include<unordered_set>
#include<stack>
#include<string>
#include<queue>
using namespace std;

class Solution {
public:

	//1.��¼������Сֵ
	//2.��¼��ǰ�۸��������Сֵ�Ĳ�ֵ���뵱ǰ�������Ƚϣ���¼��ǰ�������ֵ+
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