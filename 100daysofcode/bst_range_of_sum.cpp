/*
Range Sum of BST
Given the root node of a binary search tree, return the sum of values of all nodes with a value in the range [low, high].
Example 1:
Input: root = [10,5,15,3,7,null,18], low = 7, high = 15
Output: 32
Example 2:
Input: root = [10,5,15,3,7,13,18,1,null,6], low = 6, high = 10
Output: 23
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
class Solution
{
public:
    int rangeSumBST(TreeNode *root, int low, int high)
    {
        if (root == NULL)
            return 0;
        int sum = 0;
        if (root->val < low)
            sum += rangeSumBST(root->right, low, high);
        if (root->val > high)
            sum += rangeSumBST(root->left, low, high);
        if (root->val >= low && root->val <= high)
        {
            sum += root->val;
            if (root->val == low)
                sum += rangeSumBST(root->right, low, high);
            else if (root->val == high)
                sum += rangeSumBST(root->left, low, high);
            else
            {
                sum += rangeSumBST(root->right, low, high);
                sum += rangeSumBST(root->left, low, high);
            }
        }
        return sum;
    }
};