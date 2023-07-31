// 题目链接 https://leetcode.cn/problems/rotate-image/

#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

// 顺时针旋转矩阵90度，模拟情况很多细节，出错率较高
// 巧妙的思想： 先求矩阵A的转置B = A^T,然后对B的每行元素再反序，这样就得到了旋转90度后的矩阵
void rotate(vector<vector<int>>& matrix) {
	int n = matrix.size(); // 得到方阵matrix的维度

	// 在原地转置矩阵
	// 思路： 以下三角矩阵为主要转置对象，matrix[row][col]的对角元素为matrix[col][row]
	for (int row = 1; row < n; row++) {
		for (int col = 0; col < row; col++) {
			int temp = matrix[row][col];
			matrix[row][col] = matrix[col][row];
			matrix[col][row] = temp;
		}
	}

	// 对转置后的矩阵的每行进行逆序
	for (int i = 0; i < n; i++) {
		reverse(matrix[i].begin(), matrix[i].end());
	}
}

int main() {

	vector<vector<int>> matrix = {
		{5,1,9,11},
		{2,4,8,10},
		{13,3,6,7},
		{15,14,12,16}
	};

	rotate(matrix);

	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix[i].size(); j++) {
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
	return 0;
}