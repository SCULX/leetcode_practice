// 题目链接  https://leetcode.cn/problems/restore-ip-addresses/

#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

/*
* 在字符串s种生成合法的ip地址
* s: 原始字符串
* start: 当前处理s[start]开始的子串
* res:  合法ip地址的组合
* temp: 构造的ip地址
*/
void DFS(string s,int start,vector<string>& res,string& temp){

    int count_dot = count(temp.begin(), temp.end(), '.');  // 计数temp中'.'出现的次数

    if(count_dot == 3){
        // 如果已经合理构造了ip地址前3段，后续可以判断剩余字符串长度
        // 若长度大于3，说明无法构造出合理ip地址
        if((s.length()-start > 3) || (start >= s.length())){
            return;
        }
    }
    if(count_dot > 4){
        return;  // 当出现了超过4个.说明不是合法ip
    }

    if(start>=s.length() && count_dot == 4){
        // 已经遍历到s结尾，说明已经组成了合法的ip地址(需要去除最后一个.)
        res.push_back(temp.substr(0,temp.length()-1));
        return;
    }

    if(start+1 <= s.length()){
        // 从字符串中取一位,一定是合法的ip地址
        string str = s.substr(start, 1);
        temp = temp + str + ".";
        DFS(s, start + 1, res, temp);
        temp.erase(temp.length()-2); // 撤销构造str+"."(下同)
    }

    if(start+2 <= s.length()){
        // 从字符串中取2位，若保证没有前导0，即无06这样的子串，则是合法ip地址
        string str = s.substr(start, 2);
        if(str[0] != '0'){
            temp = temp + str + ".";
            DFS(s, start + 2, res, temp);
            temp.erase(temp.length() - 3);
        }
    }

    if(start+3 <= s.length()){
        // 从字符串中取3位，若保证没有前导0，且子串在100~255之间，则是合法ip地址
        string str = s.substr(start, 3);
        if(str[0] != '0' && (str[0]=='1' || (str[0]=='2' && str <= "255"))){
            temp = temp + str + ".";
            DFS(s, start + 3, res, temp);
            temp.erase(temp.length() - 4);
        }
    }

}

// 思路： 因为ip地址的每个段最多3位，所以可用dfs去构造
// 构造分为，取1位，取2位，取3位;在本题的s长度不大时，不会超时
vector<string> restoreIpAddresses(string s) {
    vector<string> res; // 待返回的合法ip地址组合
    string temp;

    if(s.length()<4){
        return {}; // 字符串长度没有4位，无法组成合法ip地址
    }

    DFS(s, 0, res, temp);
    return res;
}

int main(){

    string s = "1111";
    vector<string> res = restoreIpAddresses(s);

    for (int i = 0; i < res.size();i++){
        printf("%s\n", res[i].c_str());
    }
    return 0;
}