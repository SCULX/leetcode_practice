// 题目链接 https://leetcode.cn/problems/find-the-index-of-the-first-occurrence-in-a-string/

#include<cstdio>
#include<string>
#include<vector>

using namespace std;

// 显然是利用kmp算法来求解
int strStr(string haystack, string needle) {
	// ①构造next数组
	int nLen = needle.size();
	int prefix_len = 0;
	vector<int> next(nLen);
	next[0] = 0; // 第一次值为0
	for (int i = 1; i < nLen; i++) {
		if (needle[i] == needle[prefix_len]) {
			// 当前字符依然与前缀之后的字符相似，则相同前缀加1
			prefix_len++;
			next[i] = prefix_len;
		}
		else {
			if (prefix_len == 0) {
				// 当前字符既不与前缀之后的字符相同，也无共同前缀，则最长相同前后缀长度为0
				next[i] = 0;
			}
			else {
				// 修改相同的前后缀长度
				prefix_len = next[prefix_len - 1];
				i--; // 回退一个字符，再次进行比对
			}
		}
	}

	// ② 用next数组和原字符串对比
	int hLen = haystack.size();
	int j = 0; // 子串（needle)的下标
	for (int i = 0; i < hLen; i++) {
		if (haystack[i] == needle[j]) {
			j++; // 匹配下一次字符
		}
		else {
			// 第一个字符不匹配直接进行下一个
			if (i == 0) {
				continue;
			}
			if (j>0) {
				// 不匹配时直接根据next跳过子串前已经相同的部分
				j = next[j - 1];
				i--; // 回退到当前字符
			}
		}

		// 已经匹配完子串了
		if (j == nLen) {
			return i - j + 1;  // 返回第一次匹配下标
		}
	}

	return -1;  // 匹配失败
}

int main() {
	string haystack = "mississippi", needle = "issip";
	int ans = strStr(haystack, needle);
	printf("%d\n", ans);
	return 0;
}