// 题目链接 https://leetcode.cn/problems/binary-tree-level-order-traversal/

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

// 思路：使用队列来模拟层序遍历
// 取出队列的头元素,若该结点有孩子,则分别把它的左孩子和右孩子依次插入队尾
// 一直遍历到队列为空(对于左或右孩子为空的,则不处理)
vector<vector<int>> levelOrder(TreeNode *root)
{
    queue<TreeNode *> myQueue; // 存储结点的队列

    vector<int> eachLevelValue; // 每一层的结点数值
    vector<vector<int>> res;    // 最终层序遍历的结果

    if (root == nullptr)
    {
        return res;
    }

    myQueue.push(root); // 插入头结点
    while (!myQueue.empty())
    {
        int len = myQueue.size(); // 用于区分控制遍历的第几层

        for (int i = 0; i < len; i++)
        {
            TreeNode *temp = myQueue.front(); // 得到队头结点
            eachLevelValue.push_back(temp->val);

            if (temp->left != nullptr)
            {
                myQueue.push(temp->left); // 左孩子入队
            }

            if (temp->right != nullptr)
            {
                myQueue.push(temp->right); // 右孩子入队
            }
            myQueue.pop(); // 将队头元素移除
        }
        res.push_back(eachLevelValue); // 得到一层的遍历结果
        eachLevelValue.clear();        // 清除元素,防止影响下一层遍历
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

    vector<vector<int>> res = levelOrder(node1);

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