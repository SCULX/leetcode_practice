// ��Ŀ���� https://leetcode.cn/problems/zigzag-conversion/
#include<cstdio>
#include<vector>
#include<string>
using namespace std;

string convert(string s, int numRows) {
	int len = s.length();
	vector<vector<char>> Nstr(numRows,vector<char>(len,' '));
	vector<vector<int>> flag(numRows,vector<int>(len,0)); // ��Ƕ�ά������ĳλ�Ƿ���Ч
	int turn = 0;  // ת��0��ʾ���£�1��ʾ�����ϣ�
	int row = 0, col = 0;
	for (int i = 0; i < len; i++) {
		Nstr[row][col] = s[i];
		flag[row][col] = 1;  // ��λ��Ч
		// ��������if˳�򲻿ɵ���������ֻ�������˳���ִ��˳���������numRows=1�����
		if (row == 0) {
			turn = 0;
		}
		if (row == numRows - 1) {
			turn = 1;
		}

		if (turn == 1) {
			// �±߽磬��������
			row = row>0?--row:row;
			col++;
		}
		else
		{
			row++;
		}
	}
	// ��ʱNstr���Ѿ����к���N���ַ�����������Ҫת��Ϊ�ַ���
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
	// ģ��һ�飬�Ż���5%.....
	string ans = convert(s, numRows);
	printf("%s\n", ans.c_str());
	return 0;
}