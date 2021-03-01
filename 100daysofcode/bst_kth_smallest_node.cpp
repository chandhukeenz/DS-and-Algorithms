/*
Kth Smallest Element in a BST
Given the root of a binary search tree, and an integer k, return the kth (1-indexed) smallest element in the tree.

Example 1:
Input: root = [3,1,4,null,2], k = 1
Output: 1
Example 2:
Input: root = [5,3,6,2,4,null,null,1], k = 3
Output: 3
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
    //if bst cannot be modified
    int kthSmallest(TreeNode* root, int k) {
        stack<struct TreeNode*>s;
        int count=0;
        while(1){
            while(root){
                s.push(root);
                root=root->left;
            }
            if(s.empty()) break;
            root=s.top();
            s.pop();
            count++;
            if(count==k) break;
            root=root->right;
        }
        return root->val;
    }
};