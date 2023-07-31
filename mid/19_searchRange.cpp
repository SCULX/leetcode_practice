// 题目链接 https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array/

#include<cstdio>
#include<vector>
using namespace std;


// 题目要求时间复杂度是O(logn)，则使用二分查找
vector<int> searchRange(vector<int>& nums, int target) {
	if (nums.size() == 0) return { -1,-1 }; // 特殊情况
	
	int low = 0, high = nums.size() - 1;
	vector<int> ans; // 待返回的结果

	// 寻找左边的第一个是target的下标
	while (low <= high) {
		int mid = (low + high) >> 1;
		
		if (nums[mid] > target) {
			high = mid - 1;
		}
		else if (nums[mid] < target) {
			low = mid + 1;
		}
		else {
			// 因为是寻找左边界，所以当nums[mid]==target时，应该还要往左搜索
			high = mid - 1;
		}
	}
	// 当target比nums中最大数还大时，low最后会在nums.size()处
	if (low == nums.size()) {
		ans.push_back(-1); 
	}
	else {
		if (nums[low] == target) {
			// 经过上面的循环后，low所在下标就是target的最小下标
			ans.push_back(low);
		}
		else {
			// 当不存在target时，则为-1
			ans.push_back(-1);
		}
	}


	// 寻找右边最后一个target的下标
	low = 0, high = nums.size() - 1;  // 重置low与high
	while (low <= high) {
		int mid = (low + high) >> 1;

		if (nums[mid] > target) {
			high = mid - 1;
		}
		else if (nums[mid] < target) {
			low = mid + 1;
		}
		else {
			// 因为是寻找最右边界，当nums[mid]==target时，应当再往右寻找
			low = mid + 1;
		}
	}
	// 当target比nums中最小数还小，那么最终high会在-1处
	if (high == -1) {
		ans.push_back(-1);
	}
	else {
		if (nums[high] == target) {
			// 当遍历完后，high所指位置即为target的最右下标
			ans.push_back(high);
		}
		else {
			// 找不到target
			ans.push_back(-1);
		}
	}
	return ans;
}

int main() {

	vector<int> nums = { 5,7,7,8,8,10 };
	int target = 10;

	vector<int> ans = searchRange(nums, target);
	printf("%d %d\n", ans[0], ans[1]);
	return 0;
}