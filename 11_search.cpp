// 题目链接 https://leetcode.cn/problems/search-in-rotated-sorted-array/

#include<cstdio>
#include<vector>
using namespace std;

// 题目要求时间复杂度为O(logn),则需使用二分查找
int search(vector<int>& nums, int target) {
	int len = nums.size();
	int low = 0, high = len - 1;
	bool flag = false; // 以nums[0]为参考，判断target应该是正向（true)寻找or反向（false）寻找

	while (low<=high && low>=0 && high<len) {
		if (nums[low] == target) return low;
		else flag = nums[low] < target ? true : false;
		int mid = (low + high) / 2;

		if (nums[mid] == target) {
			return mid;
		}
		else if (nums[mid]<target) {
			// 必须保证以下语句在一次循环中执行一次，所以要else
			if (nums[mid] < nums[low] && flag == true) high = mid - 1;
			else if (nums[mid] < nums[low] && flag == false) low = mid + 1;
			else low = mid + 1; // 此处的else包含条件：nums[mid] >= nums[low]
		}
		else {
			// 同上原因。否则会出现low与high混乱变值导致无法继续查找
			if (nums[mid] < nums[low]) high = mid - 1;
			else if (nums[mid] > nums[low] && flag == true) high = mid - 1;
			// 此处else不能向上述去写，否则[3,1]找1时会出现问题。
			// 这里为省略多余的判断，只能大概分类判断条件，此处条件包括：
			// nums[mid] > nums[low] && flag == false 和 nums[mid]==nums[low]两种情况
			else low = mid + 1; 
		}
	}
	return -1; // 未找到目标值
}

int main() {
	vector<int> nums = { 1,3 };
	int ans = search(nums, 3);
	printf("%d\n", ans);

	return 0;
}