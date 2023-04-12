// 题目链接 https://leetcode.cn/problems/zigzag-conversion/
#include<cstdio>
#include<vector>
#include<string>
using namespace std;

string convert1(string s, int numRows) {
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

// 利用N型规律，直接定位下标
string convert(string s, int numRows) {
	/*
	* 规律：①周期T=2*numRows-2
	* ②构造的二维数组中第一行的下标 i = 0 mod T
	* ③构造的二维数组的最后一行的下标 i = numRows-1 mod T
	* ④其余每行在一个周期内至少有2个字母。
	* 第一个字母的i = 行号（从0开始） mod T
	* 第二个字母的i = T-行号 mod T
	*/
	int T = 2 * numRows - 2;
	int len = s.length();

	if (numRows == 1 || len <= numRows) {
		return s;
	}
	string ans; // 转化后的字符串

	for (int index = 0; index < numRows; ++index) {
		// 每个周期依次加入
		for (int i = 0; i +index< len; i += T ) {
			ans += s[i + index];  // 当前周期第一个字符
			if (index > 0 && index < numRows - 1 && i + T - index < len) {
				// 除了第一行，最后一行外，中间行至少有2个字符
				ans += s[i + T - index]; // 当前周期的第二个字符
			}
		}
	}
	return ans;
}


int main() {

	string s = "PAYPALISHIRING";
	int numRows = 3;
	// 模拟一遍，才击败5%.....
	string ans1 = convert1(s, numRows);

	// 数学办法击败了80%以上
	string ans = convert(s, numRows);
	printf("%s\n", ans.c_str());
	return 0;
}