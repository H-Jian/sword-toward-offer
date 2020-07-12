#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
#include<stack>

using namespace std;


class Solution {
public:
	//���� ʱ�临�Ӷ�nlogn
	int minArray(vector<int>& numbers) {
		if (numbers.size() == 0) return -1;
		sort(numbers.begin(), numbers.end());
		return numbers[0];
	}
};
//���α�����¼��Сֵ ʱ�临�Ӷ�n
int minArray(vector<int>& numbers) {
	if (numbers.size() == 0) return -1;
	if (numbers.size() == 1) return numbers[0];
	int minNum = INT_MAX;
	for (int i = 0; i < numbers.size(); ++i)
		minNum = min(minNum, numbers[i]);
	return minNum;
}


//���ֲ��� ʱ�临�Ӷ�logn
int minArray(vector<int>& numbers) {
	if (numbers.size() == 0)return -1;
	if (numbers.size() == 1)return numbers[0];
	int i = 0, j = numbers.size() - 1;
	while (i != j){
		int m = (i + j) / 2;
		if (numbers[m] > numbers[j])
			i = m + 1;
		else if (numbers[m] < numbers[j])
			j = m;
		else {
			j = j - 1;
		}
	}
	return numbers[i];
}