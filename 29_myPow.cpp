// 题目链接 https://leetcode.cn/problems/powx-n/

#include<cstdio>
#include<algorithm>
#include<climits>
using namespace std;

// -----myPow1()无法通过所有测试用例，通过算法详见myPow()-----
// n在int表示范围，可正可负，为整数 ； x=0时，n>0
double myPow1(double x, int n) {
	double ans=1.0;  // 待返回的结果

	if (x == 0) return 0;  // 特殊情况1：x为0时，n>0,结果总是为0
	else if (x == 1) return 1; // 特殊情况2： x=1时，结果总是为1
	else if (x == -1) return n % 2 == 0 ? 1 : -1; // 特殊情况3： x=-1时，n为偶数结果为1，否则为-1
	else if (n == 0) return 1;  // 特殊情况4：n=0时，x不为0，结果总是为1
	else {
		if (n > 0) {
			// 处理n>0的情况，则是正常的幂次
			for (int i = 0; i < n; i++) {
				ans *= x;
			}
		}
		else {
			// 处理n<0的情况，则是x的倒数的绝对值(n)的幂次
			// 这里要特别注意n=-2^31的情况，直接取反会超过int表示范围，所以需要采取其他办法
			if (n == INT_MIN) {
				n = -(n + 1); // 使n变成INT_MAX
				for (int i = 0; i < n; i++) {
					ans *= x;
				}
				// 在前面求ans时，少计算了乘一个x，所以求倒数后整体再除一个x
				ans = 1 / ans / x;
			}
			else {
				for (int i = 0; i < -n; i++) {
					ans *= x;
				}
				ans = 1 / ans;  // 整体求倒数
			}
		}
	}
	return ans;
}

// 根据leetcode官方解答，得到了一种以分治+迭代的高效算法
// 这里只考虑n>0的情况
// 推导过程见 https://note.youdao.com/s/XsuPZ5Jb
double quickMulti(double x, long long n) {
	double res = 1.0;
	double accumulate = x;

	while (n != 0) {
		if (n % 2 == 1) {
			// 如果这位数为1，则累积到结果中
			res *= accumulate;
		}
		// 每一位都翻倍，同时计算结果和中间结果
		accumulate *= accumulate;

		n = n / 2;
	}
	return res;
}

double myPow(double x, int n) {
	long long N = n;
	double res;
	if (N >= 0) {
		res = quickMulti(x, N);
	}
	else {
		res = 1 / quickMulti(x, -N);
	}
	return res;
}

int main() {

	double x = 2.00000;
	int n = -2147483648;
	double res = myPow(x, n);
	printf("%.5lf\n", res);

	return 0;
}

