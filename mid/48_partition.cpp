// 题目链接  https://leetcode.cn/problems/partition-list/

#include<cstdio>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 思路：最简单直接方法是设置2个新链表；一次遍历原始链表，遇到小于x的结点，则加入a链表;
// 否则加入b链表. 遍历完成后将b链表追加在a链表后即可
ListNode* partition(ListNode* head, int x) {
    ListNode* low_list = new ListNode();  // 小于x结点组成的新链表
    ListNode* great_list = new ListNode();  // 大于等于x结点组成的新链表

    if(head == nullptr || head->next == nullptr){
        return head;
    }

    ListNode* p = low_list;  // low_list的遍历指针
    ListNode* q = great_list;  // great_list的遍历指针

    while(head != nullptr){
        if(head->val < x){
            p->next = head;
            p = p->next;
        }
        else{
            q->next = head;
            q = q->next;
        }

        head = head->next;
    }
    // 合并链表
    p->next = great_list->next;
    q->next = nullptr;  // 设置新链表结束为空
    return low_list->next;
}


int main(){

    ListNode *node1 = new ListNode(1);
    ListNode *node2 = new ListNode(4);
    ListNode *node3 = new ListNode(3);
    ListNode *node4 = new ListNode(2);
    ListNode *node5 = new ListNode(5);
    ListNode *node6 = new ListNode(2);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;

    int x = 3;

    ListNode* head = partition(node1,x);

    printf("%d\n", head->next->next->next->val);

    return 0;
}

