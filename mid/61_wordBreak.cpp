// 题目链接  https://leetcode.cn/problems/word-break/

#include<cstdio>
#include<string>
#include<vector>
#include<unordered_set>
using namespace std;


// 思路：动态规划,思想真的很简单,但是想到的点有点超出你的想象了
// 设置dp(s.length())的数组  dp[i]表示s[0...i]是否能由wordDict组成
// 在0...i中设置一个界限为j,若dp[j]=true(表示s[0...j]是否能由wordDict组成),并且s[j+1...i]
// 在wordDict中,说明s[0...i]能由wordDict组成,即dp[i]为true    
bool wordBreak(string s, vector<string>& wordDict) {

    // 根据官方答案说使用unordered_set来模拟哈希表,查找更快
    unordered_set<string> wordDictSet;  //  wordDict转化为哈希表
    for(string word:wordDict){
        wordDictSet.insert(word);
    }

    int len = s.length();
    vector<int> dp(len + 1);   // 创建dp动态数组(为了方便处理,特别增加一个前置的dp元素)

    for (int i = 0; i < len;i++){
        dp[i] = 0;  // 初始化所有数组元素为0,表示s[0...i]无法由wordDict组成
    }

    dp[0] = 1;  // 设置dp[0]为1,表示空字符串能由wordDict组成
    for (int i = 1; i <= len ;i++){
        for (int j = 0; j < i;j++){
            // 注意：s.substr()要从i开始,而不是i+1
           if(dp[j]==1 && wordDictSet.find(s.substr(j,i-j)) != wordDictSet.end()){
               dp[i] = 1;
               break;   // 只要存在一种合理的组成,就直接退出
            }
        }
    }

    return dp[len] == 1;
}



//-------------  暴力回溯果然超时--------------------------
bool DFS(string s, int index, vector<string>& wordDict){
    bool is_match = false;  // 初始是否匹配为不匹配
    int len = wordDict.size();

    if(index >= s.length()){
        return true;
    }

    for (int i = 0; i < len;i++){
        // 若wordDict[i]的第一个字符与当前要匹配的s[index]起的字符串都不同,那么直接跳过这个wordDict[i]
        if(s[index] != wordDict[i][0]){
            continue;
        }

        // 截取s[index]开始的与wordDict长度一样的字符串
        string str = s.substr(index, wordDict[i].length());

        if(str == wordDict[i]){
            is_match = DFS(s, index + wordDict[i].length(), wordDict);
        }

        if(is_match){
            // 只要发现有一条路是完全匹配的，直接返回，不必进行后面的回溯判断
            return true;
        }
    }

    return is_match;
}

// 思路：字符串的题要不就是DFS，要不就是动态规划。只要DFS超时，那么此题解法就是动态规划
bool wordBreak1(string s, vector<string>& wordDict) {
    bool res = DFS(s, 0, wordDict);
    return res;
}

int main(){

    string s = "abcd";

    vector<string> wordDict = {"a","abc","b","cd"};

    bool res = wordBreak(s, wordDict);

    res ? printf("true\n") : printf("false\n");

    return 0;
}