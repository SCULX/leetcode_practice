// 题目链接  https://leetcode.cn/problems/multiply-strings/

#include<cstdio>
#include<string>
#include<vector>
using namespace std;

/*
* 模拟字符串的乘法，类似“大数相乘”。但需要减少分支，机械化流程
* 可以对num1，num2的每一位分别相乘，并对应到相应位置，最后将对应位置的数相加
* 结果用数组存储，如“123 X 456”,num1的下标i与num2的下标j相乘的结果，
* 最终对应到结果数组的i+j和i+j+1的两个位置
*/
string multiply(string num1, string num2) {
	// 特殊情况处理
	if (num1 == "0" || num2 == "0") return "0";
	int len1 = num1.size();
	int len2 = num2.size();
	string ans;  // 待返回的结果

	// 自然数的积的位数 = 自然数的位数和 或 位数和少1
	vector<int> res(len1+len2,0);  // 存储结果的数组,初始化全为0

	for (int i = len1-1; i >= 0; i--) {
		for (int j = len2-1; j >= 0; j--) {
			int number1 = num1[i] - '0';
			int number2 = num2[j] - '0';
			int temp = number1 * number2;

			// num1下标i与num2下标j的乘积存储到结果数组对应位置
			res[i + j + 1] += temp;
			if (res[i + j + 1] >= 10) {
				res[i + j] += (res[i + j + 1] / 10);  // 进位
				res[i + j + 1] %= 10; // 只保留1位
			}

		}
	}

	for (int i = 0; i < res.size(); i++) {
		if (i == 0 && res[0] == 0) {
			continue;
		}
		ans.push_back(res[i]+'0');
	}
	return ans;
}

int main() {
	string num1 = "1345";
	string num2 = "0";

	string ans = multiply(num1, num2);
	printf("%s\n", ans.c_str());

	return 0;
}