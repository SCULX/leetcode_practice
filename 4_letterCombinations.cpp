// 题目链接 https://leetcode.cn/problems/letter-combinations-of-a-phone-number/

#include<cstdio>
#include<string>
#include<vector>
#include<map>
using namespace std;

// 字典序
map<char, string> myPhoneLetter{
	{'2',"abc"},{'3',"def"},{'4',"ghi"},
	{'5',"jkl"},{'6',"mno"},{'7',"pqrs"},
	{'8',"tuv"},{'9',"wxyz"}
};

/*
* 根据字符串中数字先后顺序，构造树，对树进行DFS
*/
string temp;  // 一次DFS得到的字符串
void DFS(vector<string> str,int index,vector<string> & ans) {
	// 递归边界
	if (index == str.size()) {
		ans.push_back(temp); // 保存每次DFS后的结果
		//这里回溯位置不对，只考虑到了最后一层
		//temp.pop_back(); // 把当前的最后一个字符去掉,为回溯得到正确结果
		return;
	}

	for (int i = 0; i < str[index].size(); i++) {
		temp += str[index][i]; // 加入遍历路径中
		DFS(str, index + 1, ans); // 递归树的下一层
		temp.pop_back();  // 当前字符已经遍历了，应该释放，让其下一次能再次遍历
	}
	return;
}

vector<string> letterCombinations(string digits) {
	int len = digits.length();
	vector<string> ans;
	vector<string> charater;  // 保存数字对应的字符串
	
	if (len == 0) return ans;
	for (int i = 0; i < len; i++) {
		charater.push_back(myPhoneLetter[digits[i]]);
	}

	DFS(charater, 0, ans);
	return ans;

}

int main() {

	vector<string> ans;

	string digits = "2";
	// 时间击败100%，但内存居然只击败10.4%.....
	ans = letterCombinations(digits);
	for (string str : ans) {
		printf("%s\n", str.c_str());
	}

	return 0;
}