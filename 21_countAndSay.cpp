// 题目链接 https://leetcode.cn/problems/count-and-say/

#include<cstdio>
#include<string>
#include<map>
using namespace std;

// 构造对字符串的描述
string constructSay(string str) {
	int len = str.size();
	string ans;
	if (len !=0) {
		char ch = str[0];
		int count = 1;  // 初始第一个字符的数量为1
		for (int i = 1; i < len; i++) {
			if (str[i] == ch) {
				count++;
			}
			else {
				ans.push_back(count+'0'); // 将ch的数量变成字符，存储
				ans.push_back(ch);  // 存储ch

				// 重置字符和数量，用于计数下一个字符
				ch = str[i];
				count = 1;
			}
		}
		// 处理：①len=1的情况  ②len>1情况下最后一个字符的计数
		ans.push_back(count + '0');
		ans.push_back(ch);
	}
	return ans;
}


// 为了防止递归导致超时，应该从1-n迭代，并存储中间结果
string countAndSay(int n) {
	map<int, string>mycountandsay;
	mycountandsay[1] = "1";
	mycountandsay[2] = "11";

	for (int i = 3; i <= n; i++) {
		mycountandsay[i] = constructSay(mycountandsay[i - 1]);
	}

	return mycountandsay[n];
}

int main() {

	int n = 5;
	string ans = countAndSay(n);
	printf("%s\n", ans.c_str());

	return 0;
}