// 题目链接 https://leetcode.cn/problems/combination-sum/description/

#include<cstdio>
#include<vector>
using namespace std;

/*
* 不同于两数之和，需要用双指针。当数组中每个数可以选择多次时，
* 用DFS的回溯算法能更好的解决问题
*/
void DFS(vector<int>& candidates,int index, int target,
	int sum,vector<int> & temp , vector<vector<int>> & ans) {
	
	// 边界条件
	if (sum == target) {
		ans.push_back(temp);
		return;
	}
	if (sum > target) {
		return;
	}

	for (int i = index; i < candidates.size(); i++) {
		temp.push_back(candidates[i]); // 选择下标index的数
		sum += candidates[i];

		// 深度遍历再次用i，实现一个数可选择多次的目的
		DFS(candidates, i, target, sum, temp, ans);

		temp.pop_back();   // 撤销对下标为index的数选择
		sum -= candidates[i];
	}
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
	vector<vector<int>> ans;  // 总的组合
	vector<int> temp; // 每种组合
	if (candidates.size() == 0) return ans;

	DFS(candidates, 0, target, 0, temp, ans);
	return ans;
}


int main() {
	vector<int> candidates = { 2 };
	int target = 1;
	vector<vector<int>> ans;
	ans = combinationSum(candidates, target);

	for (int i = 0; i < ans.size(); i++) {
		for (int j = 0; j < ans[i].size(); j++) {
			printf("%d ", ans[i][j]);
		}
		printf("\n");
	}

	return 0;
}