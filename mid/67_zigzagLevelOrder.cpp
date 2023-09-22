// 题目链接  https://leetcode.cn/problems/binary-tree-zigzag-level-order-traversal/

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

// 思路：锯齿形的遍历,还是使用队列来模拟,只是入队需要利用一个标志来
// 判断是入左子树,还是右子树
vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{

    queue<TreeNode *> myQueue; // 存储结点的队列

    vector<int> eachLevelValue; // 每一层的结点数值
    vector<vector<int>> res;    // 最终层序遍历的结果

    bool order = false; // 顺序,false表示从左到右,否则为从右到左

    if (root == nullptr)
    {
        return res;
    }

    myQueue.push(root); // 插入头结点

    while (!myQueue.empty())
    {
        int len = myQueue.size(); // 队列中元素个数,用于控制遍历第几层
        order = !order;           // 换次序
        for (int i = 0; i < len; i++)
        {
            TreeNode *curNode = myQueue.front();

            // 从右到左的顺序插入结点,只在取值时逆序
            if (curNode->right != nullptr)
            {
                myQueue.push(curNode->right);
            }

            if (curNode->left != nullptr)
            {
                myQueue.push(curNode->left);
            }

            if (order == false)
            {
                eachLevelValue.push_back(curNode->val);
            }
            else
            {
                // 目前顺序是从右到左,所以取值需要逆序
                eachLevelValue.insert(eachLevelValue.begin(), curNode->val);
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

    vector<vector<int>> res = zigzagLevelOrder(node1);

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