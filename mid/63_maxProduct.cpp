// 题目链接   https://leetcode.cn/problems/maximum-product-subarray/

#include <cstdio>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

// 思路：不要陷入一个局部信息，看似是求最大积，但是因为负数存在，也需要设置一个最小值
// 用动态规划，max_dp[i]表示以num[i]结尾的最大乘积；min_dp[i]表示以num[i]为结尾的最小乘积
// 理解为最大的数乘以一个负数就变成了一个最小数，再乘一个负数，就变成了最大的正数，所以最大最小值在遇到负数时会反转
// 所以状态转移为max_dp[i+1] = max{ max_dp[i]*nums[i], nums[i], min_dp[i]*nums[i] }
// min_dp[i] = min{ max_dp[i]*nums[i], nums[i], min_dp[i]*nums[i] }
int maxProduct(vector<int> &nums)
{
    int len = nums.size();

    vector<int> max_dp(len);
    vector<int> min_dp(len);

    // 初始化最大最小乘积均为nums[0]
    max_dp[0] = nums[0];
    min_dp[0] = nums[0];

    for (int i = 1; i < len; i++)
    {
        // 需要注意连乘会超过int的表示范围，但是由于题目保证最终结果是int型，所以遇到这种情况直接跳过
        if ((long)max_dp[i - 1] * nums[i] > INT_MAX || (long)max_dp[i - 1] * nums[i] < INT_MIN)
        {
            continue;
        }
        // C++中max()函数只是求两个两个数的最大值，min()也一样，所以求多个数的最大最小值需要嵌套
        max_dp[i] = max(max(max_dp[i - 1] * nums[i], nums[i]), min_dp[i - 1] * nums[i]);
        min_dp[i] = min(min(max_dp[i - 1] * nums[i], nums[i]), min_dp[i - 1] * nums[i]);
    }

    return *max_element(max_dp.begin(), max_dp.end());
}

int main()
{

    vector<int> nums = {0, 10, 10, 10, 10, 10, 10, 10, 10, 10, -10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 0};

    int res = maxProduct(nums);

    printf("%d\n", res);
    return 0;
}