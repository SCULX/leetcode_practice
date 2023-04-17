// ��Ŀ���� https://leetcode.cn/problems/zigzag-conversion/
#include<cstdio>
#include<vector>
#include<string>
using namespace std;

string convert1(string s, int numRows) {
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

// ����N�͹��ɣ�ֱ�Ӷ�λ�±�
string convert(string s, int numRows) {
	/*
	* ���ɣ�������T=2*numRows-2
	* �ڹ���Ķ�ά�����е�һ�е��±� i = 0 mod T
	* �۹���Ķ�ά��������һ�е��±� i = numRows-1 mod T
	* ������ÿ����һ��������������2����ĸ��
	* ��һ����ĸ��i = �кţ���0��ʼ�� mod T
	* �ڶ�����ĸ��i = T-�к� mod T
	*/
	int T = 2 * numRows - 2;
	int len = s.length();

	if (numRows == 1 || len <= numRows) {
		return s;
	}
	string ans; // ת������ַ���

	for (int index = 0; index < numRows; ++index) {
		// ÿ���������μ���
		for (int i = 0; i +index< len; i += T ) {
			ans += s[i + index];  // ��ǰ���ڵ�һ���ַ�
			if (index > 0 && index < numRows - 1 && i + T - index < len) {
				// ���˵�һ�У����һ���⣬�м���������2���ַ�
				ans += s[i + T - index]; // ��ǰ���ڵĵڶ����ַ�
			}
		}
	}
	return ans;
}


int main() {

	string s = "PAYPALISHIRING";
	int numRows = 3;
	// ģ��һ�飬�Ż���5%.....
	string ans1 = convert1(s, numRows);

	// ��ѧ�취������80%����
	string ans = convert(s, numRows);
	printf("%s\n", ans.c_str());
	return 0;
}