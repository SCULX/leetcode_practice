// 题目链接  https://leetcode.cn/problems/sum-root-to-leaf-numbers/

#include <cstdio>
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

// DFS返回int来直接对左右子树求和
int DFS(TreeNode *root, int sum)
{
  if (root == nullptr)
  {
    return 0; // 因为是空的结点,那么组合不了数
  }
  int temp = sum * 10 + root->val; // 根据深度构造这条路径上的数

  if (root->left == nullptr && root->right == nullptr)
  {
    return temp; // 已经到叶节点,直接返回构造的数
  }

  // 当前结点的和是一步一步向上传递,中间不做数字回溯
  return DFS(root->left, temp) + DFS(root->right, temp);
}

// 思路：直接用DFS深度遍历,每遍历完一条路径,就得到一个数字
//  总和 = 左子树的和 + 右子树的和
int sumNumbers(TreeNode *root)
{
  int res = DFS(root, 0);
  return res;
}

int main()
{
  TreeNode *node1 = new TreeNode(4);
  TreeNode *node2 = new TreeNode(9);
  // TreeNode *node3 = new TreeNode(0);
  TreeNode *node4 = new TreeNode(5);
  TreeNode *node5 = new TreeNode(1);

  node1->left = node2;
  //  node1->right = node3;
  node2->left = node4;
  node2->right = node5;

  int res = sumNumbers(node1);
  printf("%d\n", res);
  return 0;
}