#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
#include<stack>

using namespace std;

class Solution {
public:
	//���ַ�,�ݹ�

	double myPow(double x, int n) {
		long N = n;
		if (N < 0) {
			N = -N;
			x = 1 / x;
		}
		return iPower(x, N);
	}
	double iPower(double x, long N) {
		if (N == 0 || x == 1)  return 1;
		if (N == 1)return x;
		if (N % 2) {
			double square = iPower(x, (N - 1) / 2);
			return square * square*x;
		}
		else {
			double square = iPower(x, N / 2);
			return square * square;
		}
	}
};


//��ʱ
double myPow(double x, int n) {
	double res = 1;
	for (int i = 0; i < abs(n); ++i)
		res *= x;
	return n < 0 ? 1 / res : res;
}
//�����ƽǶ�
//������תʮ����
//https://leetcode-cn.com/problems/shu-zhi-de-zheng-shu-ci-fang-lcof/solution/mian-shi-ti-16-shu-zhi-de-zheng-shu-ci-fang-kuai-s/

double myPow(double x, int n) {
	if (!x || n == 1) return x;
	if (n == 0)return 1;
	long num = n;
	double res = 1;
	if (num < 0) {
		x = 1 / x;
		num = -num;
	}
	while (num){
		if (num & 1)res *= x;//�ж�nת��Ϊ�����ƺ����һλ�Ƿ�Ϊ1
		x *= x;
		num >>= 1;//�൱�ڽ�nת��Ϊ����������ÿһ��������һλ
	}
	return res;
}
