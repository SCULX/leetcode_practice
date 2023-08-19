// 题目链接  https://leetcode.cn/problems/unique-binary-search-trees/

#include<cstdio>
#include<vector>
using namespace std;

// n个结点构成的不同二叉搜索树，个数就是Catalan数：
// Catalan(n)=(2n)! / (n!*(n+1)!)
// 这也是一个可以通过归纳递推总结出来的数
int numTrees(int n) {
    vector<int> dp(n+1,0);
    dp[0] = 1;  // 0个结点的不同二叉搜索树设置位0，是为了方便后续计算
    // 1和2个结点构成的不同二叉搜索树位基础条件
    dp[1] = 1;

    for (int i = 2; i <= n;i++){
        dp[i] = 2 * dp[i - 1];  // i作为头节点, 1...i-1作为左子树或者右子树,那么就是2个dp[i-1]
        // 当二叉搜索树既有左子树,又有右子树时,i不一定时根结点
        // 但是类比n个结点构成的不同二叉树而言,一个二叉树要成为二叉搜索树,那么它每个结点的值一定是固定的
        // 所以可以考虑 (1个结点的左子树,i-1-1个结点的右子树)、(2个结点的左子树,i-1-2个结点的右子树).....(i-1-1个结点的左子树,1个结点的右子树)
        for (int j = 1; j <= i - 2;j++){
            dp[i] += dp[j] * dp[i - 1 - j];
        }
    }
    return dp[n];
}

int main(){

    int n = 3;

    int res = numTrees(n);

    printf("%d\n", res);
    return 0;
}