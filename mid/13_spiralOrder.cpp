// 题目链接 https://leetcode.cn/problems/spiral-matrix/

#include<cstdio>
#include<vector>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
	int rows = matrix.size();  // 矩阵行数
	int cols = matrix[0].size();  // 矩阵列数

	vector<int> ans;  // 返回的结果

	// 定义遍历的外围边界，共需要4个点来确定，每次遍历边界4边中一边，并更新边界
	int top_bound = 0, low_bound = rows - 1; // 上下边界
	int left_bound = 0, right_bound = cols - 1; // 左右边界
	
	// 循环边界条件不能用一半的rows来判断，否则对于特殊的一列矩阵会陷入死循环
	while (ans.size()<rows*cols) {
		// 从左往右遍历
		if (top_bound <= low_bound) {
			for (int i = left_bound; i <= right_bound; i++) {
				ans.push_back(matrix[top_bound][i]);
		    }
			top_bound++; // 上边界向下移动
		}

		// 从上往下遍历
		if (left_bound <= right_bound) {
			for (int i = top_bound; i <= low_bound; i++) {
				ans.push_back(matrix[i][right_bound]);
			}
			right_bound--; // 右边界向左移动
		}

        // 从右往左遍历
		if (top_bound <= low_bound) {
			for (int i = right_bound; i >= left_bound; i--) {
				ans.push_back(matrix[low_bound][i]);
			}
			low_bound--; // 下边界向上移动
		}

		// 从下往上遍历
		if (left_bound <= right_bound) {
			for (int i = low_bound; i >= top_bound; i--) {
				ans.push_back(matrix[i][left_bound]);
			}
			left_bound++; // 左边界向右移动
		}
	}

	return ans;

}

int main() {
	vector<vector<int>> matrix = { {3},{2} };
	vector<int> ans = spiralOrder(matrix);

	for (int i = 0; i < ans.size(); i++) {
		printf("%d ", ans[i]);
	}
	printf("\n");
	
	return 0;
}