// 题目链接  https://leetcode.cn/problems/palindrome-partitioning/

#include<cstdio>
#include<vector>
#include<string>
using namespace std;

// 判断字符串s是否是回文串
bool isPalindromic(string &s,int start,int end){
    
    while(start<end){
        if(s[start] != s[end]){
            return false;
        }

        start++;
        end--;
    }
    return true;
}


void DFS(string s,int start,vector<string>& temp,vector<vector<string>>& res){

    // 当start=s.len,表明已经递归到s的末尾了,此时应该回溯
    if(start == s.length()){
        res.push_back(temp);
        return;
    }

    for (int i = start; i < s.length();i++){
        if (isPalindromic(s, start, i) == false){
            //不是回文串,继续下一轮测试
            continue;
        }

        temp.push_back(s.substr(start, i - start + 1));  // s[start...i]是回文串，则选择这个子串
        
        DFS(s, i + 1, temp, res); // 继续s[i+1,...]子串的循环

        temp.pop_back();  // 撤销选择s[start...i]这个回文子串
    }
}


// 思路：利用DFS思想，先构造s[0...i],若s[0...i]是回文串,那么继续拆分s[i+1,...]后面的串
// 直到字符串结束或者发现后续无法拆分为回文串了
vector<vector<string>> partition(string s) {
    int len = s.length();
    vector<string> temp;  // 每种切割的回文子串
    vector<vector<string>> res;  // 回文子串的总组合

    // 特殊情况,s为空或1个字符时,最终结果就是其本身
    if(len == 0 || len == 1){
        temp.push_back(s);
        res.push_back(temp);
        return res;
    }

    DFS(s, 0, temp, res);
    return res;
}


int main(){

    string s = "aabb";

    vector<vector<string>> res = partition(s);

    for (int i = 0; i < res.size();i++){
        for (int j = 0; j < res[i].size();j++){
            printf("%s ", res[i][j].c_str());
        }
        printf("\n");
    }
    return 0;
}