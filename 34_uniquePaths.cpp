// 题目链接   https://leetcode.cn/problems/unique-paths/

#include<cstdio>
#include<vector>
using namespace std;

// 思路：用动态规划来解。因为只能向右和向下走，所以设置
// dp[i][j]表示从start走到（i,j）的不同路径的数量
// 则对于i,j均不为0的情况下，dp[i][j]=dp[i-1][j]+dp[i][j-1]
// 于是可以递推到dp[m-1][n-1]，就得到了结果
int uniquePaths(int m, int n) {
	vector<vector<int>> dp(m,vector<int>(n));  // 定义动态数组，dp[i][j]表示从（0,0）走到（i,j）的不同路径数量

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (i == 0) dp[i][j] = 1;  // 对于第一行，只能向右走，所以只有1种路径
			else if (j == 0) dp[i][j] = 1;  // 对于第一列，只能向下走，所以只有1种路径
			else dp[i][j] = dp[i - 1][j] + dp[i][j - 1];  // 递推求解
		}
	}
	return dp[m - 1][n - 1];
}

int main() {
	int m = 3, n = 3;

	int res = uniquePaths(m, n);
	printf("%d\n", res);
	return 0;
}