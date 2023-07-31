// 题目链接 https://leetcode.cn/problems/valid-sudoku/

#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

// 进行模拟，值遍历整个矩阵一次，就把所有情况都确定
// 用3个数组来对应边界情况，row[][]、 col[][] 、 littleGrid[][]
// 分别表示行，列，小宫格内各数字的出现次数。
bool isValidSudoku(vector<vector<char>>& board) {
	int row[9][10]; // 第一个9表示9行，第二个9表示1-9这9个数字(数字9表示至少需要10个长度，下同），模拟hash
	int col[9][10]; // 第一个9表示9列，第二个9表示1-9这9个数字，模拟hash
	// 大board分为了9个小宫格，按照从左到右，从上到下的顺序为9个宫格编号（下标从0开始）
	int littleGrid[9][10];

	// 为以上三个数组全部赋初值为0，表示每个数字出现0次[但leetcode似乎不能处理这个，会报越界错误？]
	fill(row[0], row[0]+ 9 * 10, 0);
	fill(col[0], col[0] + 9 * 10, 0);
	fill(littleGrid[0], littleGrid[0] + 9 * 10, 0);

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (board[i][j] != '.') {
				int num = board[i][j] - '0'; // 将char变int
				row[i][num]++;
				col[j][num]++;

				// 将board[i][j]转化为小宫格位置的公式为
				// i/3得到了行上的第几个宫格，j/3得到了列上的第几个宫格
				// 按照小宫格编号顺序，可以确定board[i][j]处的元素在小宫格的编号是：
				// (i/3)*3 + (j/3)
				littleGrid[(j / 3) + (i / 3) * 3][num]++;

				// 每遍历一个元素，就判断数组中1-9数字出现次数，超过1次，就返回false
				if (row[i][num] > 1 || col[j][num] > 1 || littleGrid[(j / 3) + (i / 3) * 3][num] > 1) {
					return false;
				}
			}
		}
	}
	return true;
}

int main() {

	vector<vector<char>> board = {
		{'5','3','.','.','7','.','.','.','.'},
		{'6','.','.','1','9','5','.','.','.'},
		{'.','9','8','.','.','.','.','6','.'},
		{'8','.','.','.','6','.','.','.','3'},
		{'4','.','.','8','.','3','.','.','1'},
		{'7','.','.','.','2','.','.','.','6'},
		{'.','6','.','.','.','.','2','8','.'},
		{'.','.','.','4','1','9','.','.','5'},
		{'.','.','.','.','8','.','.','7','9'}
	};

	bool ans = isValidSudoku(board);
	if (ans) {
		printf("true\n");
	}
	else {
		printf("false\n");
	}
	return 0;
}