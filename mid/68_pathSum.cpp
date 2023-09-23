// 题目链接   https://leetcode.cn/problems/path-sum-ii/

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

vector<vector<int>> res; // 能构成target的结点组合
vector<int> tempNode;    // 构成target的一种结点组合

void DFS(TreeNode *root, int targetSum, int sum)
{
    // 选择当前结点
    sum += root->val;
    tempNode.push_back(root->val);

    if (sum == targetSum && root->left == nullptr && root->right == nullptr)
    {
        res.push_back(tempNode); // 找到一种组合
        return;
    }

    if (root->left != nullptr)
    {
        DFS(root->left, targetSum, sum);
        // 撤销选择当前结点
        tempNode.pop_back();
    }

    if (root->right != nullptr)
    {
        DFS(root->right, targetSum, sum);
        // 撤销选择当前结点
        tempNode.pop_back();
    }
}

// 思路： 使用DFS去探索路径
vector<vector<int>> pathSum(TreeNode *root, int targetSum)
{
    if (root == nullptr)
    {
        return res;
    }

    DFS(root, targetSum, 0);
    return res;
}

int main()
{
    TreeNode *node0 = new TreeNode(5);
    TreeNode *node1 = new TreeNode(4);
    TreeNode *node2 = new TreeNode(8);
    TreeNode *node3 = new TreeNode(11);
    TreeNode *node4 = new TreeNode(13);
    TreeNode *node5 = new TreeNode(4);
    TreeNode *node6 = new TreeNode(7);
    TreeNode *node7 = new TreeNode(2);
    TreeNode *node8 = new TreeNode(5);
    TreeNode *node9 = new TreeNode(1);

    node0->left = node1;
    node0->right = node2;
    node1->left = node3;
    node2->left = node4;
    node2->right = node5;
    node3->left = node6;
    node3->right = node7;
    node5->left = node8;
    node5->right = node9;

    int targetSum = 22;
    vector<vector<int>> res = pathSum(node0, targetSum);

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