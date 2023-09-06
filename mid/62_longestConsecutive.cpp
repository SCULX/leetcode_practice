// 题目链接    https://leetcode.cn/problems/longest-consecutive-sequence/

#include<cstdio>
#include<vector>
#include<unordered_set>
using namespace std;

// 寻找最长连续子序列(nums本身无序),需要事件复杂度为o(n)
// 但是你居然想不到解法,根本原因是int是可以 表示10^9数量级的数据
// 而且去开哈希,虽然空间复杂度非常高,但官方解答也是这种方法
int longestConsecutive(vector<int>& nums) {

    if(nums.size()==0){
        return 0;
    }
    
    unordered_set<int> num_sets;  // 构建哈希表

    int len = nums.size();
    for (int num : nums){
        num_sets.insert(num);
    }

    // 先找这个连续序列的起始元素,然后再循环里面去逐渐增大元素
    // 查看元素是否在哈希表中,若存在则长度加1
    int max_len = 1;  // 最长连续序列的长度

    for(int num_set:num_sets){
        // 如果存在num_set-1这个数,说明num_set不是连续序列的起始元素
        if(num_sets.find(num_set-1) != num_sets.end()){
            continue;  // 查看num_sets中下一个元素是否为起始元素
        }

        int cur_num = num_set;  // 当前元素是连续序列的起始元素
        int len = 1;  // 当前连续序列长度
        while(num_sets.find(cur_num + 1) != num_sets.end()){
            cur_num++;
            len++;
        }

        max_len = max(max_len, len);
    }

    return max_len;
}

int main(){

    vector<int> nums = {0,3,7,2,5,8,4,6,0,1};

    int res = longestConsecutive(nums);

    printf("%d\n", res);
    return 0;
}