struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* convertBiNode(TreeNode* node,TreeNode* ans=nullptr) {
        //返回空链的头结点
        if (node == nullptr) return ans;
        //构造右边，返回右边的头结点
        node->right = convertBiNode(node->right, ans);
        //构造左边，返回左边的头结点
        ans = convertBiNode(node->left, node);
        //修改链接
        node->left = nullptr;
        return ans;
    }
};