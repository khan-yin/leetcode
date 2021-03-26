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

    TreeNode* mirrorTree(TreeNode* root) {
        if(root==NULL) return root;
        TreeNode* temp = root ->right;
        root->right = mirrorTree(root->left);
        root->left = mirrorTree(temp);
        return root;
    }
};