// 题目链接  https://leetcode.cn/problems/reverse-integer/
#include<cstdio>
#include<limits>
using namespace std;

int reverse(int x) {
	int ans = 0;
	/*
	* 取反操作这里也会发生溢出，对于-2147483648取反，直接溢出
	* 参考了网上关于处理此种问题下的溢出
	bool flag = false; // x为负数（flag=true);反之为false
	if (x < 0) {
		flag = true;
		x = -x; // 先取反，方便统一处理

	}
	*/
	while (x) {
		int low = x % 10;
		x = x / 10;
		/*
		* 以下方法在leetcode中处理溢出失效，需要重新设计
		if (ans * 10 / 10 != ans) return 0;  // 处理溢出
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