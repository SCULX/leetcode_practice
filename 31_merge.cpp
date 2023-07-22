// 题目链接   https://leetcode.cn/problems/merge-intervals/

#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

bool cmp(vector<int> a, vector<int> b) {
	return a[0] < b[0];
}

vector<vector<int>> merge(vector<vector<int>>& intervals) {
	vector<vector<int>> res;
	// 对区间左值按照升序规则对整个intervals排序
	int len = intervals.size();
	sort(intervals.begin(), intervals.end(), cmp);
	
	// 目前intervals数组中所有的区间都是按照左值升序排列的
	// 则只需要判断intervals[i+1]的左值与intervals[i]的右值
	// 如i的左值<=end，则区间可以合并,并更新最右的区间值； 否则i是作为单独一个区间
	int start=intervals[0][0], end=intervals[0][1];   // 初始化一个合并区间为第一个区间
	for (int i = 1; i < len; i++) {
		if (intervals[i][0] <= end) {
			end = max(end,intervals[i][1]);  // 合并区间，右边界扩大
		}
		else {
			// 区间已经扩大到极限，则得到一个合并后的区间
			res.push_back({start,end});
			// 更新新区间的起始位置和结束位置
			start = intervals[i][0];
			end = intervals[i][1];
		}
	}
	res.push_back({ start,end });  // 压入最后一个区间

	return res;
}

int main() {
	vector<vector<int>> intervalus = {
		{1,3},{1,5}
	};

	vector<vector<int>> res = merge(intervalus);

	for (int i = 0; i < res.size(); i++) {
		printf("[ %d , %d ] ", res[i][0], res[i][1]);
	}
	return 0;
}