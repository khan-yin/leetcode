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
#include<cstdio>
#include<vector>
#include<string>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<string> total;
public:
    void dfs(TreeNode* root,string s)
    {
        if(root!=nullptr)
        {
            s+=std::to_string(root->val);
            if(root->left==nullptr&&root->right==nullptr)
            {
                total.push_back(s);
                return;
            }
            dfs(root->left,s+"->");
            dfs(root->right,s+"->");
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        string s="";
        if(root!=nullptr)
            dfs(root,"");
        return total;
    }
};