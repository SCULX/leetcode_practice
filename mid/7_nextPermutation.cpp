// 题目链接： https://leetcode.cn/problems/next-permutation/

#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

void nextPermutation1(vector<int>& nums) {
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

// 改进算法
/*
* 思想：从右至左寻找第一对nums[i]>nums[i-1]的，这样保证i-1~n的数是降序的；
* 此时再次从n至i寻找第一个比nums[i-1]大的数，并交换这个数，既保证了那个数是只比nums[i-1]大一点的数，
* 也保证了交换之后i~n的数都是降序的，此时只需要升序排列这些数，就可以实现下一个排序
*/
void nextPermutation(vector<int>& nums) {
	int len = nums.size();
	int index = 0; // 重排的起始下标

	for (int i = len - 1; i > 0; i--) {
		if (nums[i] > nums[i - 1]) {
			// 已经寻找到应该交换的位置
			for (int j = len - 1; j >= i; j--) {
				if (nums[j] > nums[i - 1]) {
					swap(nums[j], nums[i - 1]);
					index = i;
					break;
				}
			}
			break;
		}
	}
	sort(nums.begin() + index, nums.end());

}

int main() {
	vector<int> ans = { 4,5,2,6,3,1 };
	// 这种根据测试用例无限更变代码，击败20%.....
	// nextPermutation1(ans);

	// 改进算法思想是一致的，但是原算法分支太多，导致效率太低，然而新算法也是时间70%，空间40%
	nextPermutation(ans);
	for (int i = 0; i < ans.size(); i++) {
		printf("%d ", ans[i]);
	}
	printf("\n");

	return 0;
}