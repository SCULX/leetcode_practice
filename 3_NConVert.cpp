// 题目链接 https://leetcode.cn/problems/zigzag-conversion/
#include<cstdio>
#include<vector>
#include<string>
using namespace std;

string convert(string s, int numRows) {
	int len = s.length();
	vector<vector<char>> Nstr(numRows,vector<char>(len,' '));
	vector<vector<int>> flag(numRows,vector<int>(len,0)); // 标记二维数组中某位是否有效
	int turn = 0;  // 转向（0表示向下，1表示向右上）
	int row = 0, col = 0;
	for (int i = 0; i < len; i++) {
		Nstr[row][col] = s[i];
		flag[row][col] = 1;  // 此位有效
		// 以下两个if顺序不可调换，这里只是运用了程序执行顺序巧妙处理了numRows=1的情况
		if (row == 0) {
			turn = 0;
		}
		if (row == numRows - 1) {
			turn = 1;
		}

		if (turn == 1) {
			// 下边界，需向上走
			row = row>0?--row:row;
			col++;
		}
		else
		{
			row++;
		}
	}
	// 此时Nstr中已经排列好了N型字符串，但是需要转化为字符串
	string str = "";
	for (int i = 0; i < Nstr.size(); i++) {
		for (int j = 0; j < Nstr[i].size(); j++) {
			if (flag[i][j] == 1) {
				str.push_back(Nstr[i][j]);
			}
		}
	}
	return str;
}

int main() {

	string s = "PAYPALISHIRING";
	int numRows = 3;
	// 模拟一遍，才击败5%.....
	string ans = convert(s, numRows);
	printf("%s\n", ans.c_str());
	return 0;
}