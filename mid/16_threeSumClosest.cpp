// 题目链接 https://leetcode.cn/problems/3sum-closest/

#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

// 与target最接近的两数和
int twoSumClosest(vector<int>& nums, int index, int target) {
	int len = nums.size();
	int low = index, high = len - 1; // 双指针
	int low_num, high_num;  // 最大最小数（为了跳过重复元素）
	int sum = 0,  D_Value ; // 两数和  差值
	int min_D_Value = abs(target - nums[low]- nums[high]);  // 最小差值
	int closest_sum = nums[low] + nums[high];  // 最接近target的两数和的初值

	while (low < high) {
		low_num = nums[low];
		high_num = nums[high];
		sum = low_num + high_num;
		D_Value = abs(target - sum);
		// 更新最接近的两数和
		if (D_Value < min_D_Value) {
			min_D_Value = D_Value;
			closest_sum = sum;
		}

		if (sum < target) {
			// 跳过重复元素
			while (low < high && nums[low] == low_num) low++;
		}
		else if (sum > target) {
			// 跳过重复元素
			while (low < high && nums[high] == high_num) high--;
		}
		else {
			return sum; // 此时恰好为目标值，直接返回，结束循环
		}
	}
	return closest_sum;
}


int threeSumClosest(vector<int>& nums, int target) {
	sort(nums.begin(), nums.end());
	int len = nums.size();
	// 最接近target的三数和 的初值
	int cloestsum = nums[0] + twoSumClosest(nums, 1, target - nums[0]);
	// 差值
	int D_Value = abs(target - cloestsum);
	int min_D_Value = D_Value; // 最小差值的初值

	for (int i = 1; i < len-2; i++) {
		int twosumcloest = twoSumClosest(nums, i + 1, target - nums[i]);
		D_Value = abs(target - nums[i] - twosumcloest);
		// 更新最接近target的三数和
		if (D_Value < min_D_Value) {
			cloestsum = nums[i] + twosumcloest;
			min_D_Value = D_Value;
		}
	}
	return cloestsum;
}

int main() {

	vector<int> nums = { -13,592,-501,770,-952,-675,322,
		-829,-246,657,608,485,-112,967,-30,182,-969,559,
		-286,-64,24,365,-158,701,535,-429,-217,28,948,
		-114,-536,-711,693,23,-958,-283,-700,-672,311,
		314,-712,-594,-351,658,747,949,70,888,166,495,
		244,-380,-654,454,-281,-811,-168,-839,-106,877,
		-216,523,-234,-8,289,-175,920,-237,-791,-976,
		-509,-4,-3,298,-190,194,-328,265,150,210,285,
		-176,-646,-465,-97,-107,668,892,612,-54,-272,
		-910,557,-212,-930,-198,38,-365,-729,-410,932,
		4,-565,-329,-456,224,443,-529,-428,-294,191,
		229,112,-867,-163,-979,236,-227,-388,-209,984,
		188,-549,970,951,-119,-146,801,-554,564,-769,
		334,-819,-356,-724,-219,527,-405,-27,-759,722,
		-774,758,394,146,517,870,-208,742,-782,336,-364,
		-558,-417,663,-914,536,293,-818,847,-322,408,
		876,-823,827,167 };
	int target = 7175;

	int D_Value = threeSumClosest(nums, target);

	printf("%d\n", D_Value);

	return 0;
}