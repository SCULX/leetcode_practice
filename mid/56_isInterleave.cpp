// 题目链接  https://leetcode.cn/problems/interleaving-string/

#include<cstdio>
#include<string>
#include<vector>
using namespace std;

// 字符串题目一般都是DFS或者DP,然而对于大多数题目难度大的,一定会用DP,因为DFS会超时
// 思路：此题用动态规划,用填表法去理解这个状态转移
// dp[i][j]表示字符串s1[0...i]和s2[0...j]是否交错组成了s3[0...(i+j)]
// 为了方便处理，需要在字符串前加空格
// 若s1[i]=s3[i+j]或者s2[j]=s3[i+j],那么需要看dp[i-1][j]和dp[i][j-1]的值来确定dp[i][j]
// 可以理解为：
// 如果s1的第i个元素和s3的第i+j个元素相等,那么s1的前i个元素和s2的前j个元素是否能组成s3的前i+j个元素取决于s1的
// 前i-1个元素和s2的前j个元素能否交错组成s3的前i+j-1个元素
bool isInterleave(string s1, string s2, string s3) {
    if(s1.length()+s2.length() != s3.length()){
        return false;
    }

    s1 = " " + s1;
    s2 = " " + s2;
    s3 = " " + s3;

    int len1 = s1.length();
    int len2 = s2.length();

    vector<vector<int>> dp(len1, vector<int>(len2));
    dp[0][0] = 1; // 设置初始值dp[0][0]为1

    for (int i = 0; i < len1;i++){
        for (int j = 0; j < len2;j++){
            if(j != 0){
                if(s2[j]==s3[i+j] && dp[i][j-1]==1){
                    dp[i][j] = 1;
                }else{
                    dp[i][j] = 0;
                }
            }
            if(i != 0){
                if(s1[i]==s3[i+j] && dp[i-1][j]==1){
                    dp[i][j] |= 1;
                }else{
                    dp[i][j] |= 0;
                }
            }
        }
    }

    return dp[len1-1][len2-1] == 1;
}


// 回溯算法是直接易想到的,然而遇到字符串题目,超时是注定的,所以考虑备忘录
bool track(string& s1,int start1, string& s2,int start2, string& s3,int k, vector<vector<int>>& mem){
    bool is_fit = false; // 是否匹配的标记

    // 此函数保证了s1.length+s2.length = s3.length
    if(start1+start2 == s3.length()){
        mem[start1][start2] = 1;
        return true;
    }
    
    if(mem[start1][start2] != -1){
        if(mem[start1][start2]==1){
            return true;
        }else{
            return false;
        }
    }

    // s1可以匹配
    if(start1<s1.length() && s1[start1]==s3[k]){
        is_fit = track(s1, start1 + 1, s2, start2, s3, k + 1,mem);
    }

    // s2可以匹配
    if(start2<s2.length() && s2[start2]==s3[k]){
        // 当s1[start1]==s3[k]==s2[start2]时，本算法是让s1先去匹配,直到无法匹配使得is_fit为false,
        // 然后回溯让s2去匹配
        // 若本身s1[start1] != s3[k],得到is_fit就是每次进入函数的声明初始值为false,也能正确非回溯匹配s2
        if(!is_fit){
            is_fit = track(s1, start1, s2, start2 + 1, s3, k + 1,mem);
        }
    }

    // 存入备忘录
    if(is_fit){
        mem[start1][start2] = 1;
    }else{
        mem[start1][start2] = 0;
    }

    return mem[start1][start2]==1;
}

bool isInterleave1(string s1, string s2, string s3) {
    int len1 = s1.length();
    int len2 = s2.length();
    int len3 = s3.length();

    if(len3 != (len1+len2)){
        return false;
    }
    vector<vector<int>> mem(len1+1, vector<int>(len2+1));  // 备忘录
    for (int i = 0; i <= len1;i++){
        for (int j = 0; j <= len2;j++){
            mem[i][j] = -1;  // 初始化为-1
        }
    }

    bool res = track(s1, 0, s2, 0, s3, 0, mem);
    return res;
}

int main(){
    string s1 = "aabcc";
    string s2 = "dbbca";
    string s3 = "aadbbcbcac";

    bool res = isInterleave(s1, s2, s3);

    res ? printf("true\n") : printf("false");

    return 0;
}