// 题目链接 https://leetcode.cn/problems/decode-ways/

#include<cstdio>
#include<string>
#include<vector>
using namespace std;


// 思路：动态规划
// 设置dp[i]表示字符串s[0....i]的翻译方法数
// 如果s[i]是1-9之间数字，并且单独翻译，那么dp[i]=dp[i-1](因为站在s[0...i-1]的视角，追加了s[i]这个字符，它能翻译，且只有一种翻译，那总的翻译方法数还是不变)
// 如果s[i]可以和s[i-1]联合翻译，如s[i]s[i-1]组合在10~26之间，那么它可以翻译，并且需要保证它只能联合翻译，即s[i-1]s[i]为10或20,那么dp[i]=dp[i-2]
// 如果s[i]既可以单独翻译，又可以联合翻译，那么dp[i]=dp[i-1]+dp[i-2]
int numDecodings(string s) {
    int len = s.length();
    string new_str = " " + s;  // 为s设置前置哨兵，可以从下标1开始进行dp循环遍历复制
    vector<int> dp(len + 1,0);  // dp数组长度为len+1,为方便，为s设置了哨兵
    dp[0] = 1;  // 前置哨兵的翻译数为1，是为了方便s第一个字符翻译方法数

    // 注：以下用2个if，先后顺序已经涵盖了上述的3种转移条件，如果只能联合翻译，那么new_str[i]一定是'0',则第一个if不会执行,执行第2个if时，dp[i]是初值0+dp[i-2]
    for (int i = 1; i <= len;i++){
        // 只要new_str[i]不是0，题目限制s全为数字，那么就一定能翻译
        if(new_str[i] != '0'){
            dp[i] = dp[i - 1];
        }

        // new_str[i]可以和new_str[i-1]联合翻译
        if((new_str[i-1]=='1' && new_str[i]<='9') || (new_str[i-1]=='2' && new_str[i]<='6'))
        {
            dp[i] += dp[i - 2];
        }
    }
    return dp[len];  // 返回结果
}


// -----------DFS暴力搜索不是一个好的方案，还是需要考虑动态规划---------------
// DFS暴力递归搜索会超时(设置备忘录来存储中间结果)
// 是自底向上的逐层加方法数
int DFS(string s,int start,vector<int>& method){
    if(start >= s.length()){
        return 1; // base case 字符串为空时，表示已经完成了一种有效翻译
    }

    if(s[start] == '0'){
        return 0;   // 以0开头的字符串，无法翻译
    }

    // 查找备忘录,若有值则直接返回,减少运算
    if(method[start] != -1){
        return method[start];
    }

    // 排除了以上的情况(不以0开头，那么一定可以截取1个字符来翻译)
    int res = DFS(s, start + 1, method);   // 翻译了s[start],继续选取后面的字符来判断是否翻译

    if(start < s.length()-1 && ((s[start]=='1' && s[start+1]<='9') || (s[start]=='2' && s[start+1]<='6'))){
        // s[start][start+1]的数字在[10,26]之间，则可以进行翻译
        res += DFS(s, start + 2, method);  // 翻译了s[start][start+1],继续选取后续的字符来判断是否翻译
    }

    method[start] = res;  // 存储结果
    return res;
}

// 思路：递归(每次选择都只有两种，取1个字符和2个字符)
int numDecodings1(string s) {
    if(s[0]=='0'){
        return 0; // 字符串存在前导0，无法翻译，所以翻译方法数为0
    }
    vector<int> method(s.length());  // 备忘录(字符串s每位的翻译方法数)
    for (int i = 0; i < s.length();i++){
        method[i] = -1;  // 初始化s[i]起始的字符串翻译方法数位-1，防止与0冲突
    }

    int res = DFS(s, 0, method);

    return res;
}


int main(){

    string s = "11111111111111111";
    int res = numDecodings(s);
    printf("%d\n", res);

    return 0;
}