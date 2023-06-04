// 题目链接  https://leetcode.cn/problems/minimum-number-of-frogs-croaking/

#include<cstdio>
#include<string>
#include<map>
#include<vector>
#include<stack>
using namespace std;

/*========minNumberOfFrogs1()函数失效，在字符串特别长时，超时，无法解决========*/

// 构建一个数组，数组中每个元素都为一个栈，栈中元素为逆序的“croak”
// 依次遍历croakOfFrogs，让叫声中每个字符与栈中元素匹配，匹配成功，则弹出栈元素
// 并且每次匹配都保证从数组起始位置开始。如果其中一个栈遍历完，则表明他可以进行下一轮的
// 的匹配，函数使用isused来模拟这种行为。只有在“非传承”中创建新栈，视为需要的最小青蛙数量
int minNumberOfFrogs1(string croakOfFrogs) {
	int len = croakOfFrogs.size();
	int min_number = 1;   // 青蛙最小数量

	vector<stack<char>>  strArray;
	vector<bool> isused; // 当前栈是否在使用（作为传承下一代的标志）
	stack<char> myStack;
	myStack.push('k');
	myStack.push('a');
	myStack.push('o');
	myStack.push('r');
	myStack.push('c');
	strArray.push_back(myStack);  // 初始化栈数组
	isused.push_back(true); // 在使用中

	int j;  // 栈数组的下标

	for (int i = 0; i < len; i++) {
		for (j = 0; j < strArray.size(); j++) {
			if (strArray[j].empty() == true) {
				// 遇到空栈，表明可以顺序叫唤，直接作为j的传承，但是需要新开栈
				if (croakOfFrogs[i] == 'c' && isused[j] == true) {
					// 因为是顺序开栈，符合先后顺序，所以min_number不必加1
					stack<char> myStack;
					myStack.push('k');
					myStack.push('a');
					myStack.push('o');
					myStack.push('r');
					// myStack.push('c');  // 在新建stack时，直接把c匹配了
					strArray.push_back(myStack);
					isused.push_back(true); // 在使用中
					isused[j] = false; // 传承一代后，要关闭传承
					break; // 跳出当前循环，进行下一个字符匹配
				}
				else {
					// 所有栈都空后，当前字符非c,不符合要求，直接返回-1
					if (j == strArray.size() - 1) return -1;
					else {
						continue; // 进行下一个栈匹配
					}
				}
			}
			else {
				if (croakOfFrogs[i] == strArray[j].top()) {
					strArray[j].pop(); // 出栈
					break; // 跳出当前循环，进行下一个字符匹配
				}
				else {
					if (croakOfFrogs[i] == 'c') {
						// 新开一个stack
						stack<char> myStack;
						myStack.push('k');
						myStack.push('a');
						myStack.push('o');
						myStack.push('r');
						// myStack.push('c');  // 在新建stack时，直接把c匹配了
						strArray.push_back(myStack);
						isused.push_back(true); // 在使用中
						min_number++;
						break; // 跳出当前循环，进行下一个字符匹配
					}
					else {
						continue;
					}
				}
			}
		}
		// 遍历完所有栈，都无法匹配，则当前字符是错序的，直接返回-1
		if (j == strArray.size()) return -1;
	}

	// 可能出现croakcroa这种情况，则需要再次判断数组栈中每个栈是否为空
	for (int k = 0; k < strArray.size(); k++) {
		if (strArray[k].empty() != true) {
			return -1;
		}
	}
	return min_number;
}

// 不用全部模拟，只对“croak”中c与k进行枚举和判断，就能得到最大并行的“croak”,即最少青蛙数量。  
// 在遍历过程中记录c、r、o、a、k的数量，每一时刻只要保证他们数量是非递增的，则是合理的叫声
// 并且 c的数量-k的数量  为每时刻的最大并行度，即最少青蛙数量
int minNumberOfFrogs(string croakOfFrogs) {
	int len = croakOfFrogs.size();
	int c_num=0, r_num=0, o_num=0, a_num=0, k_num=0;
	int min_number = 0; // 最小青蛙数量

	for (int i = 0; i < len; i++) {
		switch (croakOfFrogs[i])
		{
		case 'c':
			c_num++;
			break;
		case 'r':
			r_num++;
			break;
		case 'o':
			o_num++;
			break;
		case 'a':
			a_num++;
			break;
		case 'k':
			k_num++;
			break;
		}

		// 更新最小的青蛙数量
		if (c_num >= r_num && r_num >= o_num && o_num >= a_num && a_num >= k_num) {
			// 因为一次有效叫声是c开头，k结束，所以c_num-k_num为当前最大并行叫的青蛙数量
			min_number = max(min_number, c_num - k_num);
		}
		else {
			return -1;
		}
	}
	// 只有c,r,o,a,k的数量相等，才是合理的叫声
	if (c_num == r_num && r_num == o_num && o_num == a_num && a_num == k_num) {
		return min_number;
	}
	else {
		return -1;
	}
}



int main() {
	string croakOfFrogs = "croakcrook";
	// 按照栈和一个一个字符模拟，分支非常复杂，出错太容易了。
	// 必须根据一定规律，简化不必要的模拟，比如本题的c_num - k_num得到了每时刻的最大并行度
	int ans = minNumberOfFrogs(croakOfFrogs);
	printf("%d\n", ans);

	return 0;
}