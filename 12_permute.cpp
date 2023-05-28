// 题目链接 https://leetcode.cn/problems/permutations/

#include<cstdio>
#include<vector>
using namespace std;

vector<bool> isused;

// 全排列直接利用DFS思想
void DFS(vector<int>& nums, vector<int>& temp,  vector<vector<int>> & ans) {
	// 边界条件
	if (temp.size() == nums.size()) {
		ans.push_back(temp);
		return;
	}

	for (int i = 0; i < nums.size(); i++) {
		if (isused[i]) {
			continue; // 当前数已经访问过，进行下一轮选择
		}
		// 选择当前数
		isused[i] = true;
		temp.push_back(nums[i]);

		DFS(nums, temp, ans); // 进行深度遍历

		// 撤销当前选择的数
		isused[i] = false;
		temp.pop_back();

	}
}

vector<vector<int>> permute(vector<int>& nums) {
	int len = nums.size();
	for (int i = 0; i < len; i++) {
		isused.push_back(false);
	}

	vector<vector<int>> ans; // 最终结果
	vector<int> temp; // 树遍历过程的每条分支

	DFS(nums, temp, ans);
	return ans;
}

int main() {

	vector<int> nums = { 1 };
	vector<vector<int>> ans = permute(nums);

	for (int i = 0; i < ans.size(); i++) {
		for (int j = 0; j < ans[i].size(); j++) {
			printf("%d ", ans[i][j]);
		}
		printf("\n");
	}
	return 0;
}