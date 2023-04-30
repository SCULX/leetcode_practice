// ��Ŀ���� https ://leetcode.cn/problems/3sum/
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
	sort(nums.begin(), nums.end());  // ��С�������򣬷���˫ָ��
	int len = nums.size();
	vector<vector<int>> ans;  // �洢���
	if (len < 3) return ans;
	else {
		for (int i = 0; i < len - 1; i++) {
			int low = i + 1, high = len - 1;
			if (nums[i] > 0) break;
			if (i > 0 && nums[i] == nums[i - 1]) continue;  // ȥ���ظ�����
			while (low < high) {
				int sum = nums[i] + nums[low] + nums[high];
				if (sum == 0) {
					ans.push_back({ nums[i],nums[low],nums[high] });
					while (low < high && nums[low] == nums[low + 1]) low++;
					while (low < high && nums[high] == nums[high - 1]) high--;
					low++; // ȥ��֮��ָ��ĵ�ǰλ��
					high--;  // ȥ��֮��ָ��ĵ�ǰλ��
				}
				else if (sum > 0) {
					high--; // ��̫��Ӧ��������
				}
				else {
					low++; // ��̫С��Ӧ��������
				}
			}
		}

	}
	return ans;

}

int main() {
	vector<int> nums = { -1, 0, 1, 2, -1, -4 };
	vector<vector<int>> ans = threeSum(nums);

	for (int i = 0; i < ans.size(); i++) {
		for (int j = 0; j < ans[i].size(); j++) {
			printf("%d ", ans[i][j]);
		}
		printf("\n");
	}


	return 0;
}