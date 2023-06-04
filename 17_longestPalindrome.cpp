// 题目链接  https://leetcode.cn/problems/longest-palindromic-substring/

#include<cstdio>
#include<string>
#include<vector>
using namespace std;

// 动态规划 （原理：回文串在去掉首尾两个字符后依旧是回文串）
// 定义dp(i,j)为字符串s[i]到s[j]是否为回文串
/*
			 ①  true                       , i==j
   dp(i,j) = ②  s[i] == s[j]               , 0< j-i <=2
             ③  dp(i+1,j-1) && s[i]==s[j]  , j-i>2    
*/
string longestPalindrome(string s) {
	int len = s.size();
	// 创建与字符串s长度一致的二维转态数组，并赋初值为false
	vector<vector<bool>> dp(len, vector<bool>(len, false));
	string res = s.substr(0, 1); // 初始化为第一个字符

	// 因为这个转移方程的dp[i][j]需要dp[i+1][j-1]的结果,
	// 所以不能让i,j从0开始往后遍历。可以先顺序填充长度为1，长度为2和长度为3
	// 的dp的值，然后从头遍历，这样能得到结果。
	// 但是若从dp矩阵的右下角往左上遍历，则只需要一个双层循环就可以，所以遍历方法如下：
	for (int i = len-1; i >= 0; i--) {
		for (int j = i + 1; j < len; j++) {
			if (i == j) dp[i][j] == true;  // 对应①
			else if (j - i <= 2) {
				// 对应②
				dp[i][j] = s[i] == s[j] ? true : false;
			}
			else {
				// 对应③
				dp[i][j] = (dp[i + 1][j - 1] && s[i] == s[j])? true : false;
			}

			// 更新最长回文串
			if (dp[i][j] == true && j - i + 1 > res.size()) {
				res = s.substr(i, j - i + 1);
			}
		}
	}
	return res;
}

int main() {

	string s = "bb";
	string ans = longestPalindrome(s);
	printf("%s\n", ans.c_str());
	return 0;
}