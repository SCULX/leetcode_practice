// 题目链接  https://leetcode.cn/problems/group-anagrams/

#include<cstdio>
#include<vector>
#include<string>
#include<map>
using namespace std;

// 使用hash对strs中每个string进行编码，编码一致的就是“字母异位词”
string strcode(string str) {
	map<char, int> myhashcode;
	string code; // 对单词进行编码的结果

	for (int i = 0; i < str.size(); i++) {
		myhashcode[str[i]] += 1;
	}
	// 26个英文字母的出现次数作为编码
	for (char ch = 'a'; ch <= 'z'; ch++) {
		code.push_back(myhashcode[ch]);
	}

	return code;
}

vector<vector<string>> groupAnagrams(vector<string>& strs) {
	int len = strs.size();
	// 编码一致的单词组合，map表示“编码，字符串集和”
	map<string, vector<string>> equalcodestr; 
	vector<vector<string>> res; // 待返回的结果

	if (len == 0) return { {""} };
	else if (len == 1) return { strs };
	else {
		for (int i = 0; i < len; i++) {
			string code = strcode(strs[i]);
			equalcodestr[code].push_back(strs[i]);
		}

		map<string, vector<string>>::iterator it;
		for (it = equalcodestr.begin(); it != equalcodestr.end(); it++) {
			res.push_back(it->second);
		}

		return res;
	}
}

int main() {
	vector<string> strs = { "eat", "tea", "tan", "ate", "nat", "bat" };
	vector<vector<string>> ans;
	ans = groupAnagrams(strs);
	for (int i = 0; i < ans.size(); i++) {
		for (int j = 0; j < ans[i].size(); j++) {
			printf("%s ", ans[i][j].c_str());
		}
		printf("\n");
	}

	return 0;
}