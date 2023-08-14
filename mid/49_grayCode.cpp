// 题目链接  https://leetcode.cn/problems/gray-code/

#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;

// 格雷码是一个有着很重要应用的实际编码,此题可以通过列举找出规律(但你没发现)
// 但最重要是学会二进制与格雷码相互转化
// 二进制转格雷码方法：原始二进制 (异或) 二进制右移1位
vector<int> grayCode(int n) {
    vector<int> res;
    for (unsigned i = 0; i < pow(2,n);i++){
        int gray_code = (i >> 1) ^ i;
        res.push_back(gray_code);
    }
    return res;
}

int main(){

    int n = 4;
    vector<int> res = grayCode(n);

    for (int i = 0; i < res.size();i++){
        printf("%d ", res[i]);
    }
    printf("\n");
    return 0;
}