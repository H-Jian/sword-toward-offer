#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
#include<stack>

using namespace std;

//深度优先搜索
class Solution {
public:
	//判断元素是否访问过的数组，不能放在movingCount
	bool rec[100][100] = {false};
	//vector<vector<bool> >rec(100, vector<bool>(100, false));
public:

	int numSum(int n) {
		int sum = 0;
		while (n > 0) {
			sum += n % 10;
			n /= 10;
		}
		return sum;
	}

	int movingCount(int m, int n, int k) {
		
		return DFS(m, n, 0, 0, k);
	}
	int DFS(int m, int n, int i, int j, int k) {
		if (numSum(i) + numSum(j) > k || i < 0 || i >= m || j < 0 || j >= n || rec[i][j]) return 0;
		rec[i][j] = true;
		return 1 + DFS(m, n, i + 1, j, k) + DFS(m, n, i, j + 1, k);
	}
};


//广度优先搜索
//class Solution {
//public:
//	//判断元素是否访问过的数组，不能放在movingCount
//	bool rec[100][100] = { false };
//public:
//
//	int numSum(int n) {
//		int sum = 0;
//		while (n > 0) {
//			sum += n % 10;
//			n /= 10;
//		}
//		return sum;
//	}
//
//	int movingCount(int m, int n, int k) {
//
//		return BFS(m, n, 0, 0, k);
//	}
//	int BFS(int m, int n, int i, int j, int k) {
//		if (numSum(i) + numSum(j) > k || i < 0 || i >= m || j < 0 || j >= n || rec[i][j]) return 0;
//		rec[i][j] = true;
//		return 1 + BFS(m, n, i + 1, j, k) + BFS(m, n, i, j + 1, k);
//	}
//};