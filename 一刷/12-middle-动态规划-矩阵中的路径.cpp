#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
#include<stack>

using namespace std;

class Solution {
public:
	bool exist(vector<vector<char>>& board, string word) {
		for(int i = 0;i < board.size();++i)
			for (int j = 0; j < board[i].size(); ++j) {
				if (DFS(board, word, i, j, 0)) return true;
			}
		return false;
	}
	bool DFS(vector<vector<char>>& board, string word, int i, int j, int k) {
		if (k == word.size() - 1) return true;
		if (i >= board.size() || i<0 || j >= board[0].size() || j < 0 || board[i][j] != word[k]
			) return false;
		char temp = board[i][j];
		board[i][j] = '/';
		bool res = DFS(board, word, i + 1, j, k + 1) || DFS(board, word, i - 1, j, k + 1) 
			|| DFS(board, word, i, j + 1, k + 1) || DFS(board, word, i, j - 1, k + 1);
		board[i][j] = temp;
		return res;
	}
};


bool exist(vector<vector<char>>& board, string word) {
	if (board.empty() || board[0].empty()) return word.empty();
	for (int i = 0; i < board.size(); ++i)
		for (int j = 0; j < board[i].size(); ++j) {
			if (DFS(board, word, i, j, 0)) return true;
		}
	return false;
}
bool DFS(vector<vector<char>>& board, string &word, int i, int j, int k) {
	if (k == word.size()) return true;
	if (i >= board.size() || i < 0 || j >= board[0].size() || j < 0 || board[i][j] != word[k]
		) return false;
	//char temp = board[i][j];
	board[i][j] = '/';
	if ( DFS(board, word, i + 1, j, k + 1) || DFS(board, word, i - 1, j, k + 1)
		|| DFS(board, word, i, j + 1, k + 1) || DFS(board, word, i, j - 1, k + 1))return true;
	board[i][j] = word[k];
	return false;
}
