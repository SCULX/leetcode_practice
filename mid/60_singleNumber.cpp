// 题目链接   https://leetcode.cn/problems/single-number-ii/

#include<cstdio>
#include<vector>
using namespace std;

// 思路: 看似简单的从nums中选出只出现1次的数,其余数都出现了3次.然而你居然无法想到解法
// (使用别人方法) 因为nums中数是整形，即32位，所以可以用一个32位的数组来统计nums中每个元素
// 在32位表示中1出现的次数,因为除了那个target出现了1次，其余都出现了3次，所以统计结果mod 3，
// 就把那些出现3次的数的1出现次数全部清零，剩下的就是出现1次的target
// [真的很妙，但是不难，为什么你想不到？？？]
int singleNumber(vector<int>& nums) {
    vector<int> pos(32,0);  // 初始化每个位置1的个数均为0

    int target = 0;

    for(auto num:nums){
        for (int i = 0; i < 32;i++){
            if((num>>i & 1) == 1){
                // 若num的第i位为1，则统计结果的次数加1
                pos[i]++;
                // mod 3,可以在统计过程中同时处理超过3的部分，确保全部遍历完后pos就是target的二进制表示
                pos[i] = pos[i] % 3;
            }
        }
    }

    // 将pos(target的二进制表示)转化为十进制
    for (int i = 0; i < 32;i++){
        if(pos[i]==1){
            target += (1 << i);
        }
    }

    return target;
}

int main(){

    vector<int> nums = {-2,-2,1,1,4,1,4,4,-4,-2};
    int target = singleNumber(nums);

    printf("%d\n", target);
    return 0;
}