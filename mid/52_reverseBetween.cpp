// 题目链接  https://leetcode.cn/problems/reverse-linked-list-ii/

#include<cstdio>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 思路：在一个链表种反转部分连续结点
// 第一次遍历，定位left和right的结点，给出指针
// 第二次对left和right之间进行反转
ListNode* reverseBetween(ListNode* head, int left, int right) {
    // 只有一个结点反转，反转结果仍然不变
    if(left == right){
        return head;
    }

    ListNode* dummy = new ListNode(0, head); // 空结点，指向头节点的指针

    ListNode* low = dummy;  // 慢指针,指向left结点
    ListNode* fast = dummy;  // 快指针,指向right结点
    ListNode* pre = dummy;   // left结点的前驱

    int index = -1;  // 结点的下标

    while(fast != nullptr){
        index++;
        if(index == left-1){
            pre = fast;
            low = fast->next;
        }
        
        if(index == right){
            break; // fast已经指向了right这个结点
        }

        fast = fast->next;  // fast继续指向下一个结点
    }

    // 反转链表，当low=fast时，表明right结点已经反转到了left位置，说明反转已经完成
    while(low != fast){
        pre->next = low->next;
        low->next = fast->next;
        fast->next = low;
        low = pre->next;
    }

    return dummy->next;
}

int main(){

    ListNode *node1 = new ListNode(1);
    ListNode *node2 = new ListNode(2);
    ListNode *node3 = new ListNode(3);
    ListNode *node4 = new ListNode(4);
    ListNode *node5 = new ListNode(5);
    ListNode *node6 = new ListNode(6);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;

    int left = 2, right = 4;

    ListNode* root = reverseBetween(node1, left, right);

    printf("%d\n", root->next->val);

    return 0;
}