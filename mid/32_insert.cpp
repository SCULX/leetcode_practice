// 题目链接  https://leetcode.cn/problems/insert-interval/

#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

// 把一个区间插入一个有序的区间列表，为了减少时间复杂度，直接在区间列表中找到插入位置即可
vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
	vector<vector<int>> res; // 待返回的结果
	int len = intervals.size(); // 区间列表长度
	if (len == 0) {
		res.push_back(newInterval);  // 结果就为那个插入的列表
	}
	else {
		bool isInsert = false;  // 新区间是否插入了区间列表的标志
		int start = newInterval[0]; // 合并后区间的左端点
		int end = newInterval[1]; // 合并后区间的右端点
		for (int i = 0; i < len; i++) {
			if (intervals[i][0] > end) {
				// 表示插入区间在当前区间的左侧，且不重叠
				if (isInsert == false) {
					// 新区间只能插入一次
					res.push_back({ start,end });
					isInsert = true; // 更新标志
				}
				res.push_back(intervals[i]);
			}
			else if (intervals[i][1] < start) {
				// 表示插入区间在当前区间的右侧，且不重叠
				res.push_back(intervals[i]);
			}
			else {
				// 表示插入区间和当前区间有重叠
				start = min(start, intervals[i][0]); // 新的待插入区间左端点为（start,当前区间左端点）的最小值
				end = max(end, intervals[i][1]); // 新的待插入区间右端点为（end,当前区间右端点）的最大值
			}
		}
		// 处理 ①newInterval为整个区间列表的最后一个
		// ② 最后插入的区间就是res的结尾
		if (isInsert == false) {
			res.push_back({ start,end });
		}
	}

	return res;
}

int main() {

	vector<vector<int>> intervals = {
		{1,5}
	};

	vector<int> newInterval = { 6,8 };

	vector<vector<int>> res = insert(intervals,newInterval);
	for (int i = 0; i < res.size(); i++) {
		printf("[ %d , %d ] ", res[i][0], res[i][1]);
	}
	return 0;
}