// 题目链接  https://leetcode.cn/problems/subsets-ii/

#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

/*
*   在nums数组中生成长度位length的组合
*   nums: 原始数组
*   index: 从nums中下标位index开始选数
*   temp: 一种排列组合
*   res: 所有的排列组合
*   visited: nums中元素是否被访问标记
*   length: 一种排列组合的长度
*/
void DFS(vector<int>& nums,int index,vector<int>& temp,vector<vector<int>>& res,vector<bool>& visited,int length){

    if(temp.size() == length){
        res.push_back(temp);
        return;
    }

    for (int i = index; i < nums.size();i++){
        // 用!visited[i-1]表示若nums[i-1]没有被访问过，说明是已经组合了一种temp，目前是pop之后的选数
        // 所以为了组合不重复，则跳过与nums[i-1]一样的数
        if(i != 0 && !visited[i-1] && nums[i]==nums[i-1]) continue;

        if(!visited[i]){

            temp.push_back(nums[i]);  // 选择当前数
            visited[i] = true;

            DFS(nums, i + 1,temp, res, visited, length);  // 继续选择下一个数

            temp.pop_back();  // 撤销选择当前数
            visited[i] = false;
        }
    }
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    int len = nums.size();
    sort(nums.begin(), nums.end());  // 先排序数组，这样更方便后续处理

    vector<int> temp;  // 每种排列组合
    vector<vector<int>> res;  // 总的排列组合数
    vector<bool> visited(len);  // nums各元素是否被访问的标记
    res.push_back({});  // 初始化位一个空的集合

    for (int i = 1; i <= len;i++){
        // 每次构建一个长度位i的排列组合，都需要重置visited数组全为false
        for (int j = 0; j < len;j++){
            visited[i] = false;
        }
        DFS(nums, 0, temp, res, visited, i);
        temp.clear();  // 清空临时的排列组合
    }
    return res;
}


int main(){

    vector<int> nums = {1,2,2,3};

    vector<vector<int>> res = subsetsWithDup(nums);

    for (int i = 0; i < res.size();i++){
        for (int j = 0; j < res[i].size();j++){
            printf("%d ", res[i][j]);
        }
        printf("\n");
    }

    return 0;
}