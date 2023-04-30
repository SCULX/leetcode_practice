// ��Ŀ���� https://leetcode.cn/problems/generate-parentheses/

#include<cstdio>
#include<string>
#include<vector>
#include<stack>
using namespace std;

/*
* ˼·������������Ͼ��飩����ڻ����㷨���ж������Ƿ���ԣ�
* ��temp��һ�������������ϣ���temp���κ��Ӵ�����temp[0....i]������������>= ����������
* leftCount:����������
* rightCount:����������
* temp:ÿ��·��������������
* ans:�ܵ�����������
*/
void DFS(int leftCount, int rightCount, string& temp, vector<string>& ans) {
	// �������������������ţ�˵�����Ϸ�
	if (rightCount < leftCount) return;
	if (leftCount < 0 || rightCount < 0) return;
	if (leftCount == 0 && rightCount == 0) {
		ans.push_back(temp); // ���ɵ�һ�����
		return;
	}

	temp.push_back('('); // ���Է�һ��������
	DFS(leftCount - 1, rightCount, temp, ans);
	temp.pop_back();  // �����˴�ѡ��

	temp.push_back(')'); // ���Է�һ��������
	DFS(leftCount, rightCount - 1, temp, ans);
	temp.pop_back();  // �����˴�ѡ��
}

vector<string> generateParenthesis(int n) {
	vector<string> ans; // ���ɵ�����������
	string temp;  // ÿ�����

	if (n == 0) return ans;
	DFS(n, n, temp, ans); // �����ź�������������Ϊn
	return ans;
}

int main() {

	int n = 3;
	vector<string> ans = generateParenthesis(n);

	for (int i = 0; i < ans.size(); i++) {
		printf("%s\n", ans[i].c_str());
	}

	return 0;
}