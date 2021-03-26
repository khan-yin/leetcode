#include<iostream>
#include<cstdio>
using namespace std;


struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x),left(NULL),right(NULL) {}
};

class Solution {
public:
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if(A==NULL || B==NULL) return false;
        return isSame(A,B) || isSubStructure(A->left,B) || isSubStructure(A->right,B);
    }

    bool isSame(TreeNode* A,TreeNode* B)
    {
        if(B==NULL) return true;
        if(A==NULL || A->val!=B->val) return false;
        return isSame(A->left,B->left) && isSame(A->right,B->right);
    }
};