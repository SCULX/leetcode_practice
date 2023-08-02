// 题目链接  https://leetcode.cn/problems/minimum-path-sum/

#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

// 思路： 依然是利用前34题的动态规划思想，只是在路径中需要计算路径和
int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size();  // 矩阵行数量
    int n = grid[0].size(); // 矩阵列数

    // 动态数组，dp[i][j]表示从（0，0）走到(i,j)的最小路径和
    vector<vector<int>> dp(m, vector<int>(n));

    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            // （0，0）处的dp只是grid的值
            if(i==0 && j==0){
                dp[i][j] = grid[i][j];
            }
            else if(i==0 && j != 0){
                // 当前grid的值加上左边的dp值，实现累加
                dp[i][j] = grid[i][j] + dp[i][j - 1];
            }
            else if(j==0 && i != 0){
                // 当前grid的值加上上面dp的值，实现累加
                dp[i][j] = grid[i][j] + dp[i - 1][j];
            }
            else{
                // 中间的dp值，为当前grid的值加上左边和上边最小的dp值，这样当前dp值就是最小的
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
            }
        }
    }
    return dp[m - 1][n - 1];
}

int main(){

    vector<vector<int>> grid = {
        {1,3,1},
        {1,5,1},
        {4,2,1}
    };

    int res = minPathSum(grid);
    printf("%d\n", res);

    return 0;
}