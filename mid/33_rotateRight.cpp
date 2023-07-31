// 题目链接 https://leetcode.cn/problems/rotate-list/

#include<cstdio>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}	
};

// 思路：  先遍历一遍链表，将末尾结点连接到头结点构成循环链表
// 然后，设置快慢指针，顺着链表方向移动len-k%len-1个距离，就得到了待返回链表的头结点，
// 将慢指针的结点next设为null，返回快指针指向的结点即可
ListNode* rotateRight(ListNode* head, int k) {
	// 空结点或一个结点的移动结果永远是本身
	if (head == nullptr || head->next == nullptr) return head;
 
	int len = 1; // 链表长度
	ListNode* p = head;
	while (p->next != nullptr) {
		len++;
		p = p->next;
	}

	ListNode* low = head; // 慢指针
	ListNode* fast = head->next; // 快指针
	// 构建循环链表
	p->next = head;
	// 快慢指针移动len-k%len-1步
	int count = len - k%len - 1;
	while (count--) {
		low = fast;
		fast = fast->next;
	}
	// 断开循环链表，返回以fast为头结点的单链表
	low->next = nullptr;
	return fast;
}

int main() {

	ListNode* node1 = new ListNode(1);
	ListNode* node2 = new ListNode(2);
	ListNode* node3 = new ListNode(3);
	ListNode* node4 = new ListNode(4);
	ListNode* node5 = new ListNode(5);
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;

	int k = 3;
	ListNode* res = rotateRight(node1, k);
	printf("%d , %d\n", res->val, res->next->next->val);
	return 0;
}