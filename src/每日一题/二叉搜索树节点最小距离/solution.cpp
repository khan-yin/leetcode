#include<vector>
#include<iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> res;
    void order(TreeNode* root)
    {
        if(root!=NULL)
        {
            order(root->left);
            res.push_back(root->val);
            order(root->right);
        }
    }
    //二叉搜索树的中序遍历是一个递增数组
    int minDiffInBST(TreeNode* root) {
        if(root==NULL)
            return 0;
        order(root);
        sort(res.begin(),res.end());
        int pre=res[0];
        int ans=1000005;
        for(int i=1;i<res.size();i++)
        {
            ans = min(ans,res[i]-pre);
            pre = res[i];
        }
        return ans;
    }
};