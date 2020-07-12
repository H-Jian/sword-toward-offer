#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
using namespace std;

class Solution {
public:
	bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
		int n = matrix.size();
		if (n == 0) return false;
		int m = matrix[0].size();
		if (m == 0) return false;
		if (target<matrix[0][0] || target>matrix[n-1][m - 1])return false;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				if (target == matrix[i][j])
					return true;
		return false;
	}
};

bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
	int n = matrix.size();
	if (n == 0) return false;
	int m = matrix[0].size();
	if (m == 0) return false;
	if (target < matrix[0][0] || target > matrix[n - 1][m - 1])return false;
	int row = 0, col = m - 1;
	while (row < n&&col >= 0) {
		int num = matrix[row][col];
		if (num == target) return true;
		else if (num > target) col--;
		else if (num < target) row++;
	}
	return false;
}
