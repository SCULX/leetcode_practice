// 题目链接   https://leetcode.cn/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

#include <cstdio>
#include <vector>
#include <algorithm>
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

/*
 *  inorder: 中序序列
 *  instart, inend: 中序序列的起始位置和结束位置(相对inorder中的位置)
 *  postorder: 后序序列
 *  poststart, postend: 后序序列的起始位置和结束位置(相对postorder中的位置)
 */

TreeNode *build(vector<int> &inorder, int instart, int inend,
                vector<int> &postorder, int poststart, int postend)
{
    if (instart > inend)
    {
        return nullptr;
    }
    int root_val = postorder[postend]; // 后序序列的最后一个元素
    TreeNode *root = new TreeNode(root_val);

    // 在中序序列中找到root_val的下标
    int index = distance(inorder.begin(), find(inorder.begin(), inorder.end(), root_val));

    int count = index - instart; // 左子树的结点个数(为了方便在后序序列中找到左子树)

    root->left = build(inorder, instart, index - 1, postorder, poststart, poststart + count - 1); // 根结点的左子树在中序遍历中寻找
    root->right = build(inorder, index + 1, inend, postorder, poststart + count, postend - 1);    // 根节点的右子树在中序遍历中寻找

    return root;
}

// 思路：找到根节点,然后递归构建
TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
{

    TreeNode *root = build(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1); // 后序遍历的最后一个结点是根结点
    return root;
}

int main()
{
    vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> postorder = {9, 15, 7, 20, 3};

    TreeNode *root = buildTree(inorder, postorder);

    printf("%d\n", root->left->val);
    return 0;
}