// 题目链接  https://leetcode.cn/problems/unique-binary-search-trees-ii/

#include<cstdio>
#include<vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 在leftNumber和rightNumber之间构造二叉搜索树
// 算法代码简洁，但逻辑复杂。需要跳出深层递归，从全局掌握
vector<TreeNode*> generateTreeRoot(int leftNumber,int rightNumber){
    
    vector<TreeNode *> res; // 暂存的一个二叉搜索树,会成为子树返回

    // 当leftNumber更大时,表示已经无法构造结点了,就返回空结点
    if(leftNumber > rightNumber){
        res.push_back(nullptr);
        return res;
    }

    for (int i = leftNumber; i <= rightNumber; i++){
        vector<TreeNode *> leftNodes = generateTreeRoot(leftNumber, i - 1);  // 递归构建左子树
        vector<TreeNode *> rightNodes = generateTreeRoot(i + 1, rightNumber);  // 递归构建右子树

        // 左子树和右子树的不同组合会形成不同的二叉搜索树
        for(auto leftNode : leftNodes){
            for(auto rightNode : rightNodes){
                res.push_back(new TreeNode(i,leftNode,rightNode));   // 连接根节点
            }
        }
    }

    return res;
}

// 二叉搜索树也叫二叉查找树，基本性质是左结点<根结点<右结点，所以对这种树中序遍历可以得到有序列表
// 思路：1~n每个结点都可以作为根结点，若选择k作为根结点，那么1~k-1就是左子树，k+1~n就是右子树
// 在左子树上也再次重复上述步骤，就能得到所有不同种类的二叉搜索树
vector<TreeNode*> generateTrees(int n) {

    vector<TreeNode *> res; // 不同二叉搜索树的组合

    res = generateTreeRoot(1, n);

    return res;
}

int main(){

    int n = 3;
    vector<TreeNode *> res = generateTrees(n);

    for(auto Node : res){
        printf("%d\n", Node->val);
    }
    return 0;
}