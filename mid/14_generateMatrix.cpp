// 题目链接 https://leetcode.cn/problems/spiral-matrix-ii/

#include<cstdio>
#include<vector>
using namespace std;

vector<vector<int>> generateMatrix(int n) {
	vector<vector<int>> ans(n, vector<int>(n, -1)); // 定义n*n的矩阵，且赋初值为-1

	// 定义遍历的外围边界，共需要4个点来确定，每次遍历边界4边中一边，并更新边界
	int top_bound = 0, low_bound = n - 1; // 上下边界
	int left_bound = 0, right_bound = n - 1; // 左右边界
	int index_num = 1; // 欲插入的数值
	// 
	while (index_num<=n*n) {
		// 从左往右遍历
		if (top_bound <= low_bound) {
			for (int i = left_bound; i <= right_bound; i++) {
				ans[top_bound][i] = index_num++;
			}
			top_bound++; // 上边界向下移动
		}

		// 从上往下遍历
		if (left_bound <= right_bound) {
			for (int i = top_bound; i <= low_bound; i++) {
				ans[i][right_bound] = index_num++;
			}
			right_bound--; // 右边界向左移动
		}

		// 从右往左遍历
		if (top_bound <= low_bound) {
			for (int i = right_bound; i >= left_bound; i--) {
				ans[low_bound][i] = index_num++;
			}
			low_bound--; // 下边界向上移动
		}

		// 从下往上遍历
		if (left_bound <= right_bound) {
			for (int i = low_bound; i >= top_bound; i--) {
				ans[i][left_bound] = index_num++;
			}
			left_bound++; // 左边界向右移动
		}
	}
	return ans;
}

int main() {
	int n = 9;
	vector<vector<int>> ans = generateMatrix(n);

	for (int i = 0; i < ans.size(); i++) {
		for (int j = 0; j < ans[i].size(); j++) {
			printf("%d ", ans[i][j]);
		}
		printf("\n");
	}
	return 0;
}