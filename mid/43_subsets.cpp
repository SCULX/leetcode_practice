// 题目链接  https://leetcode.cn/problems/subsets/

#include<cstdio>
#include<vector>
using namespace std;

/*
* 从nums中选择target个元素(求nums中元素个数为target的组合)
* nums: 原始集合
* index: 在nums中选择下标为index的元素
* temp: 子集合的一种情况
* res: 所有的子集的组合
* target： 子集中元素个数
*/
void DFS(vector<int>& nums,int index,vector<int>& temp,vector<vector<int>>& res,int target){
    if(temp.size() == target){
        res.push_back(temp);
        return;
    }

    for (int i = index; i < nums.size();i++){
        temp.push_back(nums[i]); // 选择当前数

        DFS(nums, i + 1, temp, res, target); // 选择下一个元素

        temp.pop_back();  // 撤销选择当前数
    }
}

// 思路：求nums的子集合，总数共有2^n(n为nums的元素个数)
// 可以视为从nums中选择0,1,2,...n个元素的组合情况
// 而且本题确定了nums中元素互异
vector<vector<int>> subsets(vector<int>& nums) {
    int len = nums.size(); // 数组元素数量

    vector<int> temp; // 一种子集
    vector<vector<int>> res; // 总的子集情况

    res.push_back({});  // 初始化总的子集. 空集是任何集合的子集

    if (len == 0)
    {
        return res;
    }
    if(len == 1){
        res.push_back(nums);  // 子集还包括本身
        return res;
    }

    for (int i = 1; i < len;i++){
        // 依次选择i(1,2,..n-1)个元素的子集
        DFS(nums, 0, temp, res, i);  
    }

    res.push_back(nums);  // 全集是自己的子集

    return res;
}


int main(){

    vector<int> nums = {0};

    vector<vector<int>> res = subsets(nums);

    for (int i = 0; i < res.size();i++){
        for (int j = 0; j < res[i].size();j++){
            printf("%d ", res[i][j]);
        }
        printf("\n");
    }

    return 0;
}