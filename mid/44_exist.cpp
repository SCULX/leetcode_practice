// 题目链接  https://leetcode.cn/problems/word-search/

#include<cstdio>
#include<vector>
#include<string>
using namespace std;

bool found = false; // 全局变量found，表示是否再board中匹配到word

/*
 * 在board这个二维矩阵中暴力搜素word，使用深度优先搜索
 * board：二维矩阵
 * row：当前搜索二维矩阵的row行
 * col：当前搜索二维矩阵的col列
 * word：要搜索的单词
 * index：在word中当前要匹配的元素的下标
 * visited：二维矩阵的是否遍历标志
 */
void DFS(vector<vector<char>>& board,int row,int col,
            string word,int index, vector<vector<bool>>& visited)
{
    int m = board.size();  // 矩阵行
    int n = board[0].size();  // 矩阵列

    if(found) return;   // 如果再board中找到了word，则返回

    if(index==word.length()){
        found = true;  // 已经成功匹配到word
        return;
    }

    // 当前遍历的(row,col)已经越界了
    if(row<0 || row>=m || col<0 || col>=n){
        return;
    }

    if(visited[row][col])  return;    // 当前元素被遍历过，则不能再次被遍历

    if(board[row][col] != word[index]){
        return;   // 当前字符和word[index]无法匹配，则换路径匹配
    }

    //------以下是二维数组遍历的模板，上下左右依次遍历，需要防止回溯走相同的路径，务必掌握---------
    visited[row][col] = true;   // (row,col)处的元素被遍历
    DFS(board, row - 1, col, word, index + 1, visited); // 遍历上面元素
    DFS(board, row + 1, col, word, index + 1, visited); // 遍历下面元素
    DFS(board, row, col - 1, word, index + 1, visited); // 遍历左边元素
    DFS(board, row, col + 1, word, index + 1, visited); // 遍历右边元素
    visited[row][col] = false;  // 对(row,col)处元素的四周都遍历完后，为了不影响下次会选择到此点，重置为未遍历
}

// 思路： 在board这个二维矩阵中递归组成字符串，要限制长度为word.length
// 然后判断组成的字符串是否等于word，若等于则直接中断递归和后续的遍历，返回结果
bool exist(vector<vector<char>>& board, string word) {
    int m = board.size();  // 矩阵行
    int n = board[0].size();  // 矩阵列

    vector<vector<bool>> visited(m,vector<bool>(n));  // board中每个元素是否被遍历过的标记

    // 设置所有元素均未被遍历
    for (int i = 0; i < m;i++){
        for (int j = 0; j < n;j++){
            visited[i][j] = false;
        }
    }

    for (int i = 0; i < m;i++){
        for (int j = 0; j < n;j++){
            DFS(board, i, j, word, 0,visited);   // 让矩阵的每个元素都成为一次头节点，这样就保证测试了每种情况
            if(found){
                break;  // 如果在某次遍历中，发现了word，那么就结束循环，直接返回结果
            }
        }
    }

    return found;
}

int main(){

    vector<vector<char>> board = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}
    };
    string word = "ABCED";

    bool isFound = exist(board, word);

    isFound ? printf("true\n") : printf("false\n");
    return 0;
}