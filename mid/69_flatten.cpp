// 题目链接    https://leetcode.cn/problems/flatten-binary-tree-to-linked-list/

#include <cstdio>
#include <vector>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void inorder(TreeNode *root, vector<int> &inorder_sei)
{
    if (root == nullptr)
    {
        return;
    }

    inorder_sei.push_back(root->val);

    inorder(root->left, inorder_sei);
    inorder(root->right, inorder_sei);
}

// 思路：最简单的方法就是首先得到先序序列,然后在先序序列中设置右孩子为下一个数,左孩子为null
void flatten(TreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }
    vector<int> inorder_sei; // 以root为根结点的树的先序序列
    inorder(root, inorder_sei);

    int len = inorder_sei.size();
    TreeNode *pre = root; // 构造的链表数的头结点就是原树的头结点
    pre->left = nullptr;

    for (int i = 1; i < len; i++)
    {
        TreeNode *newNode = new TreeNode(inorder_sei[i]);
        pre->right = newNode;
        pre = newNode;
    }
}

int main()
{
    TreeNode *node1 = new TreeNode(1);
    TreeNode *node2 = new TreeNode(2);
    TreeNode *node3 = new TreeNode(5);
    TreeNode *node4 = new TreeNode(3);
    TreeNode *node5 = new TreeNode(4);
    TreeNode *node6 = new TreeNode(6);

    node1->left = node2;
    node1->right = node3;
    node2->left = node4;
    node2->right = node5;
    node3->right = node6;

    flatten(node1);

    printf("%d\n", node1->right->right->val);

    return 0;
}