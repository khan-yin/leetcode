#include<iostream>
#include<algorithm>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) :val(x),left(NULL),right(NULL) {}
};

class Solution {
public:
    bool flag=true;
    int depth(TreeNode* root)
    {
        if(root!=NULL)
        {
            int left = depth(root->left);
            int right = depth(root->right);
            if(left-right<-1||left-right>1)
                this->flag=false;
            return 1+max(left,right);
        }
        return 0;
    }

    bool isBalanced(TreeNode* root) {
        depth(root);
        return this->flag;
    }
};