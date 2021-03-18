#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x),left(NULL),right(NULL) {}
};


// class Solution {
// public:
//     vector<int> preorder;
//     unordered_map<int,int> map;
// public:
//     TreeNode* recur(int root,int left,int right)
//     {
//         if(left>right)
//             return nullptr;
//         TreeNode* node_root = new TreeNode(preorder[root]);
//         int index = map[preorder[root]];
//         node_root->left = recur(root+1,left,index-1);
//         node_root->right = recur(root+1+index-left,index+1,right);
//         return node_root;
//     }

//     TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
//         for(int i=0;i<inorder.size();i++)
//         {
//             map[inorder[i]] = i;
//         }
//         this->preorder = preorder;
//         return recur(0,0,inorder.size()-1);
//     }
// };