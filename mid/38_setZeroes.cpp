// 题目链接  https://leetcode.cn/problems/set-matrix-zeroes/

#include<cstdio>
#include<vector>
using namespace std;


// 根据官方解释，常数空间可以用matrix的第一行和第一列来存储该行该列是否有0，
// 为防止无法区分原始的第一行和第一列是否有0，用额外2个变量来表示这情况
// 更新过程：先根据第一行第一列情况来更新所有元素，然后根据额外的两个变量来跟新第一行和第一列
void setZeroes(vector<vector<int>>& matrix) {
    int m = matrix.size(); // 矩阵行数量
    int n = matrix[0].size(); // 矩阵列数量

    bool rowzero = false, colzero = false;   // 设置第一行和第一列没有0元素

    // 查找第一列是否含有0元素
    for (int i = 0; i < m;i++){
        if(!matrix[i][0]){
            colzero = true;
            break;
        }
    }
    // 查找第一行是否含有0元素
    for (int i = 0; i < n;i++){
        if(!matrix[0][i]){
            rowzero = true;
            break;
        }
    }

    // 寻找除第1行和第1列其余元素中0的位置
    for (int i = 1; i < m;i++){
        for (int j = 1; j < n;j++){
            if(!matrix[i][j]){
                // i行和j列为0，设置第一行的第j个位置元素为0，第一列的第i个位置元素为0，
                // 表示该行或列最后应该重置为0
                matrix[0][j] = 0;
                matrix[i][0] = 0;
            }
        }
    }

    // 更新元素
    for (int i = 1; i < m;i++){
        for (int j = 1; j < n;j++){
            if(!matrix[i][0] || !matrix[0][j]){
                matrix[i][j] = 0;
            }
        }
    }

    // 更新第一行和第一列
    if(rowzero){
        for (int i = 0; i < n;i++){
            matrix[0][i] = 0;
        }
    }
    if(colzero){
        for (int i = 0; i < m;i++){
            matrix[i][0] = 0;
        }
    }
}


//----- 常数空间没有实现，因为最坏情况下是matrix都为0，就需要o(mn)的空间，不存在常数空间-----
// 要原地反转数组，并且0的位置可能因为反转导致位置失效
// 思想： 用二维数组存储0的位置，整个matrix中有多少个0，就需要多少个(i,j)元组来存储
// 实现了常数空间
void setZeroes1(vector<vector<int>>& matrix) {
    int m = matrix.size(); // 矩阵行数量
    int n = matrix[0].size(); // 矩阵列数量

    vector<vector<int>> pos;  // 存储matrix中0的位置

    // 寻找所有0的位置
    for (int i = 0; i < m;i++){
        for (int j = 0; j < n;j++){
            if(matrix[i][j]==0){
                pos.push_back({i, j}); // 以(i,j)这样的二元组来表示0的位置，方便后续对i行和j列统一置0
            }
        }
    }

    // 根据0的位置对该行和该列一致置0
    for (int i = 0; i < pos.size();i++){
        int row = pos[i][0];
        int col = pos[i][1];

        fill(matrix[row].begin(), matrix[row].end(), 0);  // 对row行置0
        // 对col列置0
        for (int j = 0; j < m; j++){
            matrix[j][col] = 0;
        }
    }
}

int main(){

    vector<vector<int>> matrix = {
        {0,1,2,0},
        {3,4,5,2},
        {1,3,1,5}
    };

    setZeroes(matrix);

    for (int i = 0; i < matrix.size();i++){
        for (int j = 0; j < matrix[i].size();j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}