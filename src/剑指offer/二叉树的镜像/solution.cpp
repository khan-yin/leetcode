#include<iostream>
#include<cstdio>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(NULL),right(NULL) {}
};

class Solution {
public:
    void preorder(TreeNode* & p,TreeNode* root)
    {
        if(root!=NULL)
        {
            p = new TreeNode(root->val);
            preorder(p->left,root->right);
            preorder(p->right,root->left);
        }
    }

    TreeNode* mirrorTree(TreeNode* root) {
        if(root==NULL) return root;
        TreeNode *  p = new TreeNode(root->val);
        preorder(p->left,root->right);
        preorder(p->right,root->left);
        return p;
    }
};