// 题目链接 https://leetcode.cn/problems/jump-game/

#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

// 利用贪心思想，构造一个全局最优的最长跳转到的下标，
// 每次循环得到局部的最长跳转到的下标，更新全局并处理异常情况
bool canJump(vector<int>& nums) {
	int len = nums.size();
	int farest = 0;  // 全局最优解（最长跳转到的下标）
	for (int i = 0; i < len - 1; i++) {
		// 得到遍历中i处能到达的最远下标farest
		farest = max(farest, nums[i] + i);

		if (farest <= i) {
			// 当farest<=i时，表明i之前已经结束跳跃，或者遇到了nums[i]=0的情况
			// 此时已经无法继续往后跳转了，则返回false
			return false;
		}
	}
	// 最终对比farest，如果到达了数组最后的下标len-1，则表示能跳跃，否则不能
	if (farest >= len - 1) return true;
	else return false;
}

int main() {

	vector<int> nums = { 3,2,1,0,4 };

	bool ans = canJump(nums);
	if (ans) printf("true\n");
	else printf("false\n");

	return 0;
}