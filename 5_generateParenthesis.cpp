// 题目链接 https://leetcode.cn/problems/generate-parentheses/

#include<cstdio>
#include<string>
#include<vector>
#include<stack>
using namespace std;

/*
* 思路：（借鉴了网上经验）如何在回溯算法中判断括号是否配对？
* 若temp是一个合理的括号组合，则temp的任何子串，即temp[0....i]中左括号数量>= 右括号数量
* leftCount:左括号数量
* rightCount:右括号数量
* temp:每条路径构造的括号组合
* ans:总的括号组合情况
*/
void DFS(int leftCount, int rightCount, string& temp, vector<string>& ans) {
	// 右括号数量多于左括号，说明不合法
	if (rightCount < leftCount) return;
	if (leftCount < 0 || rightCount < 0) return;
	if (leftCount == 0 && rightCount == 0) {
		ans.push_back(temp); // 生成的一种组合
		return;
	}

	temp.push_back('('); // 尝试放一个左括号
	DFS(leftCount - 1, rightCount, temp, ans);
	temp.pop_back();  // 撤销此次选择

	temp.push_back(')'); // 尝试放一个右括号
	DFS(leftCount, rightCount - 1, temp, ans);
	temp.pop_back();  // 撤销此次选择
}

vector<string> generateParenthesis(int n) {
	vector<string> ans; // 生成的括号配对组合
	string temp;  // 每种组合

	if (n == 0) return ans;
	DFS(n, n, temp, ans); // 左括号和右括号数量都为n
	return ans;
}

int main() {

	int n = 3;
	vector<string> ans = generateParenthesis(n);

	for (int i = 0; i < ans.size(); i++) {
		printf("%s\n", ans[i].c_str());
	}

	return 0;
}