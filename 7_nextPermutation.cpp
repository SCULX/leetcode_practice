// 题目链接： https://leetcode.cn/problems/next-permutation/

#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

void nextPermutation(vector<int>& nums) {
	int len = nums.size();
	int i =0;
	int temp_max_index = len-1;  // 临时储存后续遍历中最大数的下标
	for ( i = len - 1; i > 0; i--) {
		if (nums[i] > nums[i - 1]) {
			if (nums[temp_max_index] > nums[i - 1]) {
				// 若nums[i]之后的数也有比nums[i-1]大的，应该用nums[i+1]
				// 及其以后数中仅比nums[i-1]大的数来交换
				for (int j = len - 1; j > i; j--) {
					if (nums[j] > nums[i - 1]) {
						temp_max_index = j;
						break;
					}
				}
				swap(nums[i-1], nums[temp_max_index]);
			}
			else {
				swap(nums[i], nums[i - 1]);
			}
			// 找到变换位置后，需要对i位置及其之后的进行升序排序
			sort(nums.begin()+i, nums.end());
			break;
		}
		else {
			if (nums[i] > nums[temp_max_index]) {
				temp_max_index = i;
			}
		}
	
	}
	if (i == 0) {
		// 生成最小的字典序
		sort(nums.begin(), nums.end());
	}
}

int main() {
	vector<int> ans = { 3,4,2,1 };
	// 这种根据测试用例无限更变代码，击败20%.....
	nextPermutation(ans);
	for (int i = 0; i < ans.size(); i++) {
		printf("%d ", ans[i]);
	}
	printf("\n");

	return 0;
}