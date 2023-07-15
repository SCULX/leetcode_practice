// 题目链接  https://leetcode.cn/problems/maximum-subarray/

#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

// 从题目本身“最大子数组和”可大概推测需要用动态规划
// 而此题的动态规划的状态定义需要特殊考虑，必须要涵盖nums[i],否则无法从dp[i-1]得到dp[i]
int maxSubArray(vector<int>& nums) {
	int len = nums.size();
	int res = nums[0]; // 最大的子数组和，初始化为数组第一个元素

	// 定义状态dp[i]为以nums[i]结尾的最大子数组和
	vector<int> dp(len,0);

	dp[0] = nums[0]; // 初始化dp[0]=nums[0]

	// 状态转移只有两种：
	// ①与前面的nums[i-1]联合形成更大子数组：dp[i]=dp[i-1]+nums[i]
	// ②不和nums[i-1]联合，只能单独成为一个子数组: dp[i]=nums[i]
	// 则最终的dp[i]为①和②中结果最大的那个
	for (int i = 1; i < len; i++) {
		dp[i] = max(nums[i], dp[i - 1] + nums[i]);

		// 同时更新最大子数组和(res=最大的dp[i])
		res = max(res, dp[i]);
	}
	return res;
}

int main() {
	vector<int> nums = { 5,4,-1,7,8 };
	int res = maxSubArray(nums);

	printf("%d\n", res);

	return 0;
}