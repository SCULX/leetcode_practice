// 题目链接  https://leetcode.cn/problems/binary-tree-level-order-traversal-ii/

#include <cstdio>
#include <vector>
#include <queue>
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

// 思路：这是逆序的层序遍历,所以在使用队列时,需要模拟每次孩子结点都插入头部
vector<vector<int>> levelOrderBottom(TreeNode *root)
{
    vector<int> eachlevelNodes; // 每层的结点
    vector<vector<int>> res;    // 总的结点
    queue<TreeNode *> myQueue;  // 结点队列

    if (root == nullptr)
    {
        return res; // 返回空
    }

    // 头节点不为空,直接插入队列
    myQueue.push(root);

    while (!myQueue.empty())
    {
        int len = myQueue.size(); // 队列的长度,用于控制遍历深度

        for (int i = 0; i < len; i++)
        {
            TreeNode *temp = myQueue.front();    // 先取出队列中头结点
            eachlevelNodes.push_back(temp->val); // 暂存结点的值

            if (temp->left != nullptr)
            {
                myQueue.push(temp->left);
            }

            if (temp->right != nullptr)
            {
                myQueue.push(temp->right);
            }
            myQueue.pop(); // 结点已经遍历完,直接pop
        }

        // 经过for循环,已经得到了一层的所有结点值,在res的头部插入
        res.insert(res.begin(), eachlevelNodes);
        eachlevelNodes.clear(); // 清空这层的结点值,防止影响下一层
    }

    return res;
}

int main()
{
    TreeNode *node1 = new TreeNode(3);
    TreeNode *node2 = new TreeNode(9);
    TreeNode *node3 = new TreeNode(20);
    TreeNode *node4 = new TreeNode(15);
    TreeNode *node5 = new TreeNode(7);

    node1->left = node2;
    node1->right = node3;
    node3->left = node4;
    node3->right = node5;

    vector<vector<int>> res = levelOrderBottom(node1);

    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
        {
            printf("%d ", res[i][j]);
        }
        printf("\n");
    }

    return 0;
}