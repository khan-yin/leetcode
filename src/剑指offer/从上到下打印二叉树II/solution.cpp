#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
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
    vector<vector<int> > levelOrder(TreeNode* root) {
        vector<vector<int> > res;
        queue<TreeNode*> q;
        if(root!=NULL) q.push(root);
        while(!q.empty())
        {
            vector<int> tmp;
            int size = q.size();
            while(size--)
            {
                    TreeNode* t = q.front();
                    q.pop();
                    // res.push_back(t->val);
                    tmp.push_back(t->val);
                    if(t->left!=NULL)
                        q.push(t->left);
                    if(t->right!=NULL)
                        q.push(t->right);
            }
            res.push_back(tmp);
        }
        return res;
    }
};