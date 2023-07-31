// 题目链接 https://leetcode.cn/problems/4sum/

#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

//----回溯法在测试用例到282/292就直接超时，并且难以调试，所以回溯在此问题失效

//vector<bool> flag;  // 当前数是否遍历的标志
//
//// 利用DFS思想才构造4层的树，但是复杂度很高，需要利用有序数组来剪枝
///*
//* nums: 原始有序数组（从小到大排序）
//* target： 求和后的目标值
//* index: 当前遍历的下标
//* temp: 遍历树的每条路径（每一种数组中选取的4个数的组合）
//* ans: 最终的结果
//* sum: 当前遍历中的数字和
//*/
//void DFS(vector<int>& nums, int target, int index,
//	vector<int>& temp, vector<vector<int>>& ans, int & sum) {
//
//	if (temp.size() == 4 ) {
//		if (sum == target) {
//			ans.push_back(temp);
//		}
//		return;
//	}
//
//	for (int i = index; i < nums.size(); i++) {
//		if (flag[i] == false) {
//			sum += nums[i];
//			// 剪枝
//			if (i !=0 && nums[i] == nums[i - 1] && flag[i - 1] == false) {
//				sum -= nums[i];
//				continue;
//			}
//
//			flag[i] = true; // 选择当前数
//			temp.push_back(nums[i]);
//			
//			DFS(nums, target,i+1, temp, ans, sum); // 下一轮选择
//			
//			flag[i] = false; // 撤销当前选择
//			sum -= nums[i];
//			temp.pop_back();
//			
//		}
//	}
//}

//vector<vector<int>> fourSum(vector<int>& nums, int target) {
//	// 先排序
//	sort(nums.begin(), nums.end());
//	for (int i = 0; i < nums.size(); i++) {
//		flag.push_back(false);  // 初始化每个数都没遍历
//	}
//
//	vector<int> temp;
//	vector<vector<int>> ans;
//	int sum = 0;
//	DFS(nums, target, 0,temp, ans, sum);
//
//	return ans;
//}

// 注：target必须改为long类型，这是官方测试用例决定的，
// 只需要改twoSum和threeSum的就行，fourSum的target是不会溢出的（详见nums1的测试例子）
vector<vector<int>> twoSum(vector<int>& nums, int index, long target) {
	int len = nums.size();
	int low = index, high = len - 1;
	int sum = 0, low_num = 0, high_num = 0;
	vector<vector<int>> ans; // 待返回的结果
	
	while (low < high) {
		low_num = nums[low];
		high_num = nums[high];
		sum = low_num + high_num;
		if (sum > target) {
			// 去掉重复的数字，保证最终结果不会出现重复
			while (low<high && nums[high] == high_num) high--;
		}
		else if (sum < target) {
			while (low < high && nums[low] == low_num) low++;
		}
		else {
			ans.push_back({ nums[low],nums[high] });
			while (low < high && nums[high] == high_num) high--;
			while (low < high && nums[low] == low_num) low++;
		}
	}
	return ans;
}

vector<vector<int>> threeSum(vector<int>& nums,int index,long target) {
	int len = nums.size();
	vector<vector<int>> temps; // 两数和返回的结果
	vector<vector<int>> ans;  // 待返回的结果

	for (int i = index; i < len; i++) {
		temps = twoSum(nums, i + 1, target - nums[i]);
		if (temps.size() != 0) {
			for (vector<int>& temp : temps) {
				temp.push_back(nums[i]);
				ans.push_back(temp);
			}
		}
		// 跳过重复元素，保证最终结果不重复
		while (i < len-1 && nums[i] == nums[i+1]) i++;
	}
	return ans;
}

// 利用“两数和”的双指针来模拟
vector<vector<int>> fourSum(vector<int>& nums, int target) {
	sort(nums.begin(), nums.end());  // 排序
	int len = nums.size();
	vector<vector<int>> temps; // 三数和的结果
	vector<vector<int>> ans; // 待返回的结果

	for (int i = 0; i < len-1; i++) {
		temps = threeSum(nums, i + 1, target - nums[i]);
		if (temps.size() != 0) {
			for (vector<int>& temp : temps) {
				temp.push_back(nums[i]);
				ans.push_back(temp);
			}
		}
		// 跳过重复元素，保证最终结果不重复
		while (i < len - 1 && nums[i] == nums[i + 1]) i++;
	}
	return ans;
}

int main() {
	vector<int> nums = { 91277418,66271374,38763793,4092006,
		11415077,60468277,1122637,72398035,-62267800,
		22082642,60359529,-16540633,92671879,-64462734,
		-55855043,-40899846,88007957,-57387813,-49552230,
		-96789394,18318594,-3246760,-44346548,-21370279,
		42493875,25185969,83216261,-70078020,-53687927,
		-76072023,-65863359,-61708176,-29175835,85675811,
		-80575807,-92211746,44755622,-23368379,23619674,
		-749263,-40707953,-68966953,72694581,-52328726,
		-78618474,40958224,-2921736,-55902268,-74278762,
		63342010,29076029,58781716,56045007,-67966567,
		-79405127,-45778231,-47167435,1586413,-58822903,
		-51277270,87348634,-86955956,-47418266,74884315,
		-36952674,-29067969,-98812826,-44893101,-22516153,
		-34522513,34091871,-79583480,47562301,6154068,
		87601405,-48859327,-2183204,17736781,31189878,
		-23814871,-35880166,39204002,93248899,-42067196,
		-49473145,-75235452,-61923200,64824322,-88505198,
		20903451,-80926102,56089387,-58094433,37743524,
		-71480010,-14975982,19473982,47085913,-90793462,
		-33520678,70775566,-76347995,-16091435,94700640,
		17183454,85735982,90399615,-86251609,-68167910,
		-95327478,90586275,-99524469,16999817,27815883,
		-88279865,53092631,75125438,44270568,-23129316,
		-846252,-59608044,90938699,80923976,3534451,
		6218186,41256179,-9165388,-11897463,92423776,
		-38991231,-6082654,92275443,74040861,77457712,
		-80549965,-42515693,69918944,-95198414,15677446,
		-52451179,-50111167,-23732840,39520751,-90474508,
		-27860023,65164540,26582346,-20183515,99018741,
		-2826130,-28461563,-24759460,-83828963,-1739800,
		71207113,26434787,52931083,-33111208,38314304,
		-29429107,-5567826,-5149750,9582750,85289753,
		75490866,-93202942,-85974081,7365682,-42953023,
		21825824,68329208,-87994788,3460985,18744871,
		-49724457,-12982362,-47800372,39958829,-95981751,
		-71017359,-18397211,27941418,-34699076,74174334,
		96928957,44328607,49293516,-39034828,5945763,
		-47046163,10986423,63478877,30677010,-21202664,
		-86235407,3164123,8956697,-9003909,-18929014,-73824245 };
	int target = -236727523;

	vector<int> nums1 = { 1000000000,1000000000,1000000000,1000000000 };
	int target1 = -294967296;
	
	vector<vector<int>> ans;
	ans = fourSum(nums1, target1);

	for (int i = 0; i < ans.size(); i++) {
		for (int j = 0; j < ans[i].size(); j++) {
			printf("%d ", ans[i][j]);
		}
		printf("\n");
	}

	return 0;
}