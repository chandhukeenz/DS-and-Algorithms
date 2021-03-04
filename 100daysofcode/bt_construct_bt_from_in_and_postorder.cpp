/*
Construct Binary Tree from Inorder and Postorder Traversal
Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and
 postorder is the postorder traversal of the same tree, construct and return the binary tree.
Example 1:
Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
Output: [3,9,20,null,null,15,7]
Example 2:
Input: inorder = [-1], postorder = [-1]
Output: []
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    unordered_map<int,int>m;
    TreeNode* build(vector<int>& inorder, vector<int>& postorder,int &rootIdx,int left,int right){
        if(left>right) return NULL;
        int pivot=m[postorder[rootIdx]];
        rootIdx--;
        TreeNode* node=new TreeNode(inorder[pivot]);
        node->right=build(inorder,postorder,rootIdx,pivot+1,right);
        node->left=build(inorder,postorder,rootIdx,left,pivot-1);
        return node;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int rootIdx=postorder.size()-1;
        for(int i=0;i<inorder.size();i++){
            m[inorder[i]]=i;
        }
        return build(inorder,postorder, rootIdx, 0,inorder.size()-1);
    }
};