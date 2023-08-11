// 题目链接  https://leetcode.cn/problems/combinations/

#include<cstdio>
#include<vector>
using namespace std;

/*
* n：从1到n中选数(两边界包含)
* index: 此次选数的下标(可理解为此次选的数)
* res: 总的组合情况
* temp: 一种组合
* k: 组合中元素个数
*/
void DFS(int n,int index,vector<vector<int>>& res, vector<int>& temp,int k){
    if(temp.size()==k){
        res.push_back(temp);
        return;
    }

    for (int i = index; i <= n;i++){
        temp.push_back(i);  // 选择当前数

        DFS(n, i + 1, res, temp, k);  // 选择下一个数

        temp.pop_back();   // 取消选择当前数
    }
}

// 思路：就是用DFS思想去构建深度为k的树，需要注意组合互不相同
vector<vector<int>> combine(int n, int k) {
    vector<int> temp; // 每种组合
    vector<vector<int>> res; // 总的组合情况

    DFS(n, 1, res, temp, k);
    return res;
}


int main(){

    int n = 4, k = 3;
    vector<vector<int>> res = combine(n, k);

    for (int i = 0; i < res.size();i++){
        for (int j = 0; j < res[i].size();j++){
            printf("%d ", res[i][j]);
        }
        printf("\n");
    }
        return 0;
}