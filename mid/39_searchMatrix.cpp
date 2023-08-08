// 题目链接  https://leetcode.cn/problems/search-a-2d-matrix/


#include<cstdio>
#include<vector>
using namespace std;

// 思路：matrix内部元素已经有序了，可以使用二分搜索来处理
// matrix[i][j]代表的元素在整个元素有序的数组中下标是i*n + j(matrix为m*n矩阵，且下标从0开始)
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size();  // 矩阵的行数
    int n = matrix[0].size();  // 矩阵的列数

    int low = 0, high = m*n - 1;   // 慢指针为矩阵开始位置，快指针为矩阵结束位置

    while(low <= high){
        int mid = (low + high) / 2;
        // 将矩阵重构为一维数组后，在数组中下标为index的元素在原矩阵
        // 的行为index/n; 列为index%n;
        int row_mid = mid / n;
        int col_mid = mid % n;
        if(matrix[row_mid][col_mid] < target){
            low = mid + 1;
        }
        else if(matrix[row_mid][col_mid] > target){
            high = mid - 1;
        }
        else{
            // 找到了元素，直接返回true
            return true;
        }
    }

    return false;  // 循环完之后没有返回，说明没有找到
}

int main(){

    vector<vector<int>> matrix = {
        {1,3,5,7},
        {10,11,16,20},
        {23,30,34,60}
    };

    int target = 20;

    bool is_find = searchMatrix(matrix, target);

    is_find ? printf("Yes!") : printf("No!");
    return 0;
}