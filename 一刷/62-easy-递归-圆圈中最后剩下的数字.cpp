#include<unordered_set>
#include<stack>
#include<string>
#include<queue>
#include<list>
using namespace std;

class Solution {
public:
	struct ListNode {
		int val;
		ListNode *next;
		ListNode(int x) : val(x), next(NULL) {}
	};
	//速度太慢超出时间限制
	int lastRemaining(int n, int m) {
		if (m == 1)return n - 1;
		ListNode* dummy = new ListNode(-1);
		ListNode* cur = dummy;
		for (int i = 0; i < n; ++i) {
			ListNode *newHead = new ListNode(i);
			cur->next = newHead;
			cur = newHead;
			if (i == n - 1) {
				cur->next = dummy->next;
				cur = dummy->next;
				dummy->next = NULL;
				delete dummy;
			}
		}

		int p = 1;
		ListNode* pre = cur;
		while (cur&&cur->next) {
			pre = cur;
			cur = cur->next;
			p++;
			if (p == m) {
				pre->next = cur->next;
				cur->next = NULL;
				cur = pre->next;
				p = 1;
			}
		}
		return pre->val;

	}
};


class Solution {
	int f(int n, int m) {
		if (n == 1)
			return 0;
		int x = f(n - 1, m);
		return (m + x) % n;
	}
public:
	int lastRemaining(int n, int m) {
		return f(n, m);
	}
};


class Solution {
public:
	int lastRemaining(int n, int m) {
		int f = 0;
		for (int i = 2; i != n + 1; ++i)
			f = (m + f) % i;
		return f;
	}
};


/*
public int lastRemaining(int n, int m) {
	 if(n==0||m==0)
		return -1;
	 List<Integer> list=new ArrayList<>();
	 for(int i=0;i<n;i++)
		list.add(i);
	 int c=(m-1)%n;
	 while(list.size()!=1) {
		list.remove(c);
		c=(c+m-1)%list.size();
	 }
	 return list.get(0);
 }

作者：yuanninesuns
链接：https://leetcode-cn.com/problems/yuan-quan-zhong-zui-hou-sheng-xia-de-shu-zi-lcof/solution/si-chong-fang-fa-xiang-xi-jie-da-by-yuanninesuns/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/

int lastRemaining(int n, int m) {
	if (n == 0 || m == 0)return -1;
	list<int>rec;
	for (int i = 0; i < n; ++i)
		rec.push_back(i);
	int c = (m - 1) % n;
	while (rec.size() != 1) {
		rec.remove(c);
		c = (c + m - 1) % rec.size();
	}
	return rec.front();
}