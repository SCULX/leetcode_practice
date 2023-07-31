// 题目链接  https://leetcode.cn/problems/divide-two-integers/

#include<cstdio>
#include <utility>
#include<string>
#include<climits>
using namespace std;

// 求a/b的商
pair<int,int> quotient(long long a, long long b) {
	int ans = 0, remainder = 0; // ans为商,remainder为余数
	long long sum = 0ll; // 防止中间和溢出，必须用long long类型
	if (a < b) {
		return make_pair(0, a);
	}
	while (sum + b <= a) {
		ans++;
		sum += b;
		remainder = a - sum;
	}
	return make_pair(ans, remainder);
	
}

// 根据题意，只能模拟除法运算
int divide(int dividend, int divisor) {
	string ans;
	int result;
	bool flag1 = false, flag2 = false;  // 非负数为false

	// 排除被除数为0，除数不为0
	if (dividend == 0 && divisor !=0) {
		return 0;  
	}

	// 排除除数已经是int_min的情况(该情况下，只有被除数也是int_min商才为1，否则其他情况都是0)
	if (divisor == INT_MIN) {
		if (dividend == INT_MIN) return 1;
		else return 0;
	}

	string str1 = to_string(dividend);
	string str2 = to_string(divisor);
	if (str1[0] == '-') { 
		flag1 = true;
		str1 = str1.substr(1);
	}

	if (str2[0] == '-') {
		flag2 = true;
		str2 = str2.substr(1);
		divisor = -divisor;
	}
	// 注意：不能用atoi来转换，必须atoll，否则leetcode无法处理这种溢出
	long long temp = atoll(str1.substr(0, 1).c_str()); // 这里的中间变量必须为ll类型，否则对于2147483648会溢出
	pair<int, int> res; // 中间商与余数
	for (int i = 1; i <= str1.size(); i++) {
		res = quotient(temp,(long long)divisor);
		ans.push_back(res.first+'0'); // 把商当做char暂存
		string temp_str = to_string(res.second) + str1.substr(i, 1);
		temp = atoll(temp_str.c_str());
	}

	long long n = atoll(ans.c_str()); // 防止int表示溢出.atoi不会自动检查是否溢出，只会出现未定义的行为
	
	if ((flag1 && flag2) || (!flag1 && !flag2)) {
		if (n <= INT_MAX) {
			result = (int)n; // 未溢出，则直接转换
		}
		else {
			result = INT_MAX;
		}
		return result;
	}
	else {
		// 为了防止转int后溢出，这里只能严格用>
		if (-n > INT_MIN) {
			result = -(int)n; // 未溢出，则直接转换
		}
		else {
			result = INT_MIN;
		}
		return result;
	}
	
}


int main() {
	int dividend = -2147483648, divisor = -1017100424;

	// 无语了？？？第一次提交击败12%，稍等之后再提交击败50%.....
	int ans = divide(dividend, divisor);
	printf("%d\n", ans);

	return 0;
}