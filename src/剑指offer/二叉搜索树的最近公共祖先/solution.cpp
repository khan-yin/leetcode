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

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans=root;
        while(true)
        {
            if(ans->val<p->val&&ans->val<q->val)
            {
                ans=ans->right;
            }
            else if(ans->val>p->val&&ans->val>q->val)
            {
                ans=ans->left;
            }
            else
            {
                break;
            }
        }
        return ans;
    }
};