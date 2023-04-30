// ��Ŀ���� https://leetcode.cn/problems/letter-combinations-of-a-phone-number/

#include<cstdio>
#include<string>
#include<vector>
#include<map>
using namespace std;

// �ֵ���
map<char, string> myPhoneLetter{
	{'2',"abc"},{'3',"def"},{'4',"ghi"},
	{'5',"jkl"},{'6',"mno"},{'7',"pqrs"},
	{'8',"tuv"},{'9',"wxyz"}
};

/*
* �����ַ����������Ⱥ�˳�򣬹���������������DFS
*/
string temp;  // һ��DFS�õ����ַ���
void DFS(vector<string> str,int index,vector<string> & ans) {
	// �ݹ�߽�
	if (index == str.size()) {
		ans.push_back(temp); // ����ÿ��DFS��Ľ��
		//�������λ�ò��ԣ�ֻ���ǵ������һ��
		//temp.pop_back(); // �ѵ�ǰ�����һ���ַ�ȥ��,Ϊ���ݵõ���ȷ���
		return;
	}

	for (int i = 0; i < str[index].size(); i++) {
		temp += str[index][i]; // �������·����
		DFS(str, index + 1, ans); // �ݹ�������һ��
		temp.pop_back();  // ��ǰ�ַ��Ѿ������ˣ�Ӧ���ͷţ�������һ�����ٴα���
	}
	return;
}

vector<string> letterCombinations(string digits) {
	int len = digits.length();
	vector<string> ans;
	vector<string> charater;  // �������ֶ�Ӧ���ַ���
	
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
	// ʱ�����100%�����ڴ��Ȼֻ����10.4%.....
	ans = letterCombinations(digits);
	for (string str : ans) {
		printf("%s\n", str.c_str());
	}

	return 0;
}