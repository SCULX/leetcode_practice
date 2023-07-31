// 题目链接  https://leetcode.cn/problems/unique-paths-ii/

#include<cstdio>
#include<vector>
using namespace std;

// 思想：依然利用动态规划思想，设置dp[i][j]表示走到(i,j)的不同路径数量
// 一般情况下，dp[i][j]=dp[i-1][j]+dp[i][j-1],但是对于(i,j)处为障碍，难么此处的dp(i,j)=0
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size();  // 矩形的行数
    int n = obstacleGrid[0].size();  // 矩形的列数

    vector<vector<int>> dp(m, vector<int>(n));
    bool rowflag = false; // 第一行是否有障碍的标志
    bool colflag = false; // 第一列是否有障碍的标志

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0)
            {
                if (obstacleGrid[i][j] == 0 && !rowflag)
                    dp[i][j] = 1;
                else
                {
                    dp[i][j] = 0;
                    rowflag = true;
                    // 如果是第一列有障碍，那么同时将第一列障碍标识设为true，防止[[1],[0]]这种特殊情况
                    if (j == 0)
                        colflag = true;
                }
            }
            else if (j == 0)
            {
                if (obstacleGrid[i][j] == 0 && !colflag)
                    dp[i][j] = 1;
                else
                {
                    dp[i][j] = 0;
                    colflag = true;
                }
            }
            else {
                // 若当前没有障碍，才能用递推公式求解
                if(obstacleGrid[i][j]==0) dp[i][j] = dp[i - 1][j] + dp[i][j - 1];

                // 若当前有障碍，那么路径走法只能为0
                else dp[i][j]=0;
            }
        }
    }
    return dp[m - 1][n - 1];
}

int main(){

    vector<vector<int>> obstacleGrid={
        {1},
        {0}
    };

    int res = uniquePathsWithObstacles(obstacleGrid);
    printf("%d\n",res);

    return 0;
}