// 题目链接  https://leetcode.cn/problems/permutations-ii/

#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

vector<bool> isused;

// nums包含重复数值，待sort后，需要返回不重复的全排列，则在每次树的起始位置跳过重复元素就行
void DFS(vector<int>& nums, vector<vector<int>>& res,
	vector<int>& temp) {
	if (temp.size() == nums.size()) {
		res.push_back(temp);
	}

	for (int i = 0; i < nums.size(); i++) {
		// 当nums[i-1]==fasle时，表示重新建立以nums[i]为头结点的树
		// 则为了保证不出现重复元素，那么就需要跳过nums[i]和之前nums[i-1]一样的树
		while (i != 0 
			&& nums[i] == nums[i - 1] 
			&& isused[i - 1] == false) {
			// 必须判断i+1是否越界，如果i+1==nums.size()，说明已经遍历到数组尾部了
			// 此时表示所有组合都已经尝试过了，所以必须return来终止，否则会陷入死循环
			if (i + 1 < nums.size()) i++;
			else return;
		}
		if (isused[i] == false) {
			// 选择nums[i]
			temp.push_back(nums[i]);
			isused[i] = true;

			DFS(nums, res, temp);  // 选择下一个数

			// 撤销对nums[i]的选择
			temp.pop_back();
			isused[i] = false;
		}
	}
}

vector<vector<int>> permuteUnique(vector<int>& nums) {
	int len = nums.size();
	sort(nums.begin(), nums.end());
	for (int i = 0; i < len; i++) {
		isused.push_back(false);  // 初始化全部是未访问
	}

	vector<int> temp; // 每一种排列组合
	vector<vector<int>> res; // 待返回的结果
	DFS(nums, res, temp);
	return res;
}

int main() {

	vector<int> nums = {1,2,3};
	vector<vector<int>> ans;
	ans = permuteUnique(nums);
	
	for (int i = 0; i < ans.size(); i++) {
		for (int j = 0; j < ans[i].size(); j++) {
			printf("%d ", ans[i][j]);
		}
		printf("\n");
	}
	return 0;
}