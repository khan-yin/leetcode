#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int> > res;
    void dfs(TreeNode* root,vector<int> path, int target)
    {
        if(root!=NULL)
        {
            target-=root->val;
            path.push_back(root->val);
            if(target==0&&root->left==NULL&&root->right==NULL)
            {
                res.push_back(path);
            }
            dfs(root->left,path,target);
            dfs(root->right,path,target);
        }
    }

    vector<vector<int> > pathSum(TreeNode* root, int target) {
        vector<int> p;
        dfs(root,p,target);
        return this->res;
    }
};