// 题目链接 https://leetcode.cn/problems/swap-nodes-in-pairs/

#include<cstdio>

// 官方链表定义
struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* swapPairs(ListNode* head) {
	if (head == nullptr || head->next == nullptr) return head;

	ListNode* p, * q,* temp; // 三个临时结点，用于遍历
	p = head;
	q = head->next;
	head = q; // 首先确定了头结点
	
	// 应先使p结点的next先变，再变q的next
	p->next = q->next;
	q->next = p;

	temp = p; // 第一轮的末结点

	while (true) {
		// 下一轮的两个结点
		p = p->next;
		if (p == nullptr) {
			break;  // 刚好两两配对交换结束
		}
		q = p->next;
		if (q == nullptr) {
			break;  // 只有一个结点，无需交换，循环结束
		}

		// 应先使p结点的next先变，再变q的next
		p->next = q->next;
		q->next = p;

		temp->next = q;
		temp = p; // 上一轮的末结点

	}
	return head;
}

int main() {
	int head[] = { 1, 2, 3, 4 };

	ListNode * listnode1 = new ListNode(head[0]);
	ListNode * listnode2 = new ListNode(head[1]);
	ListNode * listnode3 = new ListNode(head[2]);
	ListNode * listnode4 = new ListNode(head[3]);

	listnode1->next = listnode2;
	listnode2->next = listnode3;
	listnode3->next = listnode4;
	
	// 这类题的测试用例自己实现较难，即不易验证是否有效
	ListNode * res = swapPairs(listnode1);

	printf("ans: %d", res->next->next->val);

	return 0;
}