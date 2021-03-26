#include<iostream>
#include<cstdio>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(NULL),right(NULL) {}
};

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return root==NULL? true: check(root->left,root->right);
    }
    
    bool check(TreeNode* L,TreeNode* R)
    {
        if(L==NULL&&R==NULL) return true;
        if(L==NULL || R==NULL || L->val!=R->val) return false;
        return check(L->left,R->right) && check(L->right,R->left); 
    }
};