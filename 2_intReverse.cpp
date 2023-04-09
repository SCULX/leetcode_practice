// ��Ŀ����  https://leetcode.cn/problems/reverse-integer/
#include<cstdio>
#include<limits>
using namespace std;

int reverse(int x) {
	int ans = 0;
	/*
	* ȡ����������Ҳ�ᷢ�����������-2147483648ȡ����ֱ�����
	* �ο������Ϲ��ڴ�����������µ����
	bool flag = false; // xΪ������flag=true);��֮Ϊfalse
	if (x < 0) {
		flag = true;
		x = -x; // ��ȡ��������ͳһ����

	}
	*/
	while (x) {
		int low = x % 10;
		x = x / 10;
		/*
		* ���·�����leetcode�д������ʧЧ����Ҫ�������
		if (ans * 10 / 10 != ans) return 0;  // �������
		else {
			ans = ans * 10 + low;
		}
		*/
		if (ans > INT_MAX / 10 || ans == INT_MAX / 10 && low > 7) return 0;
		else if (ans < INT_MIN / 10 || ans == INT_MIN / 10 && low < -8) return 0;
		else {
			ans = ans * 10 + low;
		}
	}
	return ans;
}

int main() {

	int x = -2147483648;
	printf("%d\n", reverse(x));

	return 0;
}