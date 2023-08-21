// 题目链接  https://leetcode.cn/problems/validate-binary-search-tree/


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

void traveOrder(TreeNode* root, vector<int>& seq){
    // 遍历左子树
    if(root->left != nullptr){
        traveOrder(root->left, seq);
    }

    if(root != nullptr){
        seq.push_back(root->val);  // 将根节点的值加入序列
    }

    // 遍历右子树
    if(root->right != nullptr){
        traveOrder(root->right, seq);
    }
}

// 思路： BST的中序遍历序列一定是升序的,利用这个性质可以快速判断
bool isValidBST(TreeNode* root) {

    vector<int> seq;

    traveOrder(root, seq);

    for (int i = 0; i < seq.size()-1;i++){
        if(seq[i]>=seq[i+1]){
            return false;
        }
    }

    return true;
}

int main(){

    TreeNode* node1 = new TreeNode(2);
    TreeNode* node2 = new TreeNode(1);
    TreeNode* node3 = new TreeNode(3);
   
    node1->left = node2;
    node1->right = node3;

    bool res = isValidBST(node1);

    res ? printf("true\n") : printf("false");

    return 0;
}