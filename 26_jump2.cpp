// 题目链接 https://leetcode.cn/problems/jump-game-ii/

#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

/*
* 使用贪心策略，每次都选择能跳转的下标i中i+nums[i]最大的地方
* 这样就能保证局部都是使跳转步数最少的选择，最终也就逼近了全局跳转步数最少的选择
*/
int jump(vector<int>& nums) {
	int len = nums.size();
	if (len == 1) return 0; // 当只有一个元素时，只需要跳跃0步
	int step = 0;  // 跳跃步数
	int curfarest = 0, furfarest = 0; // 当前能跳转到最远的地方的下标  将来能跳转到最远的地方的下标

	for (int i = 0; i < len - 1; i++) {
		furfarest = max(furfarest, nums[i] + i);
		// 当循环中的下标i达到了当前最远下标，那么就需要更新最远下标
		if (curfarest == i) {
			step++;
			// 当前最远下标应该是上次的最远下标，这样就保证了每次都在curfarest到furfarest中寻找能跳到最远的下标
			curfarest = furfarest;
		}
	}
	return step;
}

int main() {

	vector<int> nums = {2,1,1,1,1};

	int step = jump(nums);
	printf("%d\n", step);

	return 0;
}