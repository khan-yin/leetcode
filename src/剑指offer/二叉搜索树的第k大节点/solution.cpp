/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include<iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int k;
    int res;
    //中序遍历倒序为递减序列，中序遍历为递增序列
    void dfs(TreeNode* root)
    {
        if(root!=NULL)
        {
            dfs(root->right);
            if(this->k==0) return;
            this->k--;
            if(this->k==0)
            {
                this->res = root->val;
                return;
            }
            dfs(root->left);
        }
    }
    int kthLargest(TreeNode* root, int k) {
        this->k = k;
        dfs(root);
        return this->res;
    }
};