// 题目链接  https://leetcode.cn/problems/remove-duplicates-from-sorted-list-ii/

#include<cstdio>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


// 思路：使用快慢指针(p,q)来计数结点，r指针来构建新的链表；若结点次数超过1次，则不做操作；反之，则用r指针来追加到新链表中
ListNode* deleteDuplicates(ListNode* head) {

    if(head == nullptr || head->next == nullptr){
        return head;
    }

    // 注: 当p,q初始化为同一个结点时，count数量表示的是p结点的出现次数
    // 即当p,q的val不同时，考虑要不要删除的结点是p，而不是q
    ListNode* p = head;   // 慢指针，指向当前计数元素
    ListNode* q = head;   // 快指针，用于对比计数
    ListNode* r = head;
    head = nullptr;  // 新链表的头结点设置为空
    r = nullptr;  // 在新链表中追加新的结点

    int count = 0; // 记录一个结点出现次数

    while(q !=nullptr){
        
        if(q->val != p->val){
            if(count==1){
                // 说明p结点是唯一的,若head为空,则头节点就是p,否则追加p结点到新链表中
                if(r == nullptr){
                    // 没有头节点，则设置为头节点
                    head = p;
                    r = head;
                    r->next = nullptr;
                } 
                else{
                    // 有头节点，则追加结点
                    r->next = p;
                    r = r->next;
                    r->next = nullptr;
                }  
            }
            p = q;
            count = 1;  // 新结点出现次数重置为1
        }
        else{
            count++;
        }

        q = q->next;
    }

    // 处理最后一个结点
    if(count==1){
        if(r == nullptr){
            head = p;
            r = head;
            r->next = nullptr;
        } 
        else{
            r->next = p;
            r = r->next;
            r->next = nullptr;
        }  
    }

    return head;
}


int main(){

    ListNode *node1 = new ListNode(1);
    ListNode *node2 = new ListNode(2);
    ListNode *node3 = new ListNode(3);
    ListNode *node4 = new ListNode(3);
    ListNode *node5 = new ListNode(4);
    ListNode *node6 = new ListNode(4);
    ListNode *node7 = new ListNode(5);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
    node6->next = node7;

    ListNode *head = deleteDuplicates(node1);

    printf("%d\n", head->next->next->val);

    return 0;
}