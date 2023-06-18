// 题目链接 https://leetcode.cn/problems/combination-sum-ii/

#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

vector<bool> isused;
// 固定套路，利用DFS思想进行递归。为了保证每个数只取一次且最后组合不重复
// 则每条路径开头的数字均不同，且按下标递增次序进行组合
/*
* candidates:原始数组
* ans：符合题意的最终集和，包含多个有效的组合
* temp：原始数组中数字的组合
* target：目标数
* index:当前遍历的到数组中元素的下标
* sum:当前遍历路径中数的和
*/
void DFS(vector<int>& candidates, vector<vector<int>>& ans,
	vector<int>& temp, int target, int index, int sum ) {

	if (sum == target) {
		// 当前遍历路径中元素和为target，则是一种有效组合
		ans.push_back(temp);
		return;
	}

	if (sum > target) return;  // 和太大，直接返回

	int len = candidates.size();

	for (int i = index; i < len; i++) {
		if (isused[i] == true) continue;  // 在路径中元素只选择一次

		// 这句语句作用：保证最终结果中不存在相同的组合
		// 当candidates[i] 与 candidates[i - 1]相等时，应该直接跳过
		// i>index来表示新建立的完整分支
		if (i > index && candidates[i] == candidates[i - 1] ) continue;
		
		// 选择当前数
		temp.push_back(candidates[i]);
		sum += candidates[i];
		isused[i] = true;
		DFS(candidates, ans, temp, target, i + 1, sum);


		// 撤销对当前数的选择
		temp.pop_back();
		sum -= candidates[i];
		isused[i] = false;
	}
	return;
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
	sort(candidates.begin(), candidates.end());
	int len = candidates.size();
	for (int i = 0; i < len; i++) {
		isused.push_back(false);
	}
	vector<int> temp;
	vector<vector<int>> ans;
	DFS(candidates, ans, temp, target, 0, 0);
	return ans;
}

int main() {
	vector<int> candidates = { 2,5,2,1,2 };
	int target = 5;

	vector<vector<int>> ans = combinationSum2(candidates,target);

	for (int i = 0; i < ans.size(); i++) {
		for (int j = 0; j < ans[i].size(); j++) {
			printf("%d ", ans[i][j]);
		}
		printf("\n");
	}
	return 0;
}