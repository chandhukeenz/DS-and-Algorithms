/*
Smallest Subtree with all the Deepest Nodes
Given the root of a binary tree, the depth of each node is the shortest distance to the root.
Return the smallest subtree such that it contains all the deepest nodes in the original tree.
A node is called the deepest if it has the largest depth possible among any node in the entire tree.
The subtree of a node is tree consisting of that node, plus the set of all descendants of that node.
Example 1:
Input: root = [3,5,1,6,2,0,8,null,null,7,4]
Output: [2,7,4]
Explanation: We return the node with value 2, colored in yellow in the diagram.
The nodes coloured in blue are the deepest nodes of the tree.
Notice that nodes 5, 3 and 2 contain the deepest nodes in the tree but node 2 is the smallest subtree among them, so we return it.
Example 2:
Input: root = [1]
Output: [1]
Explanation: The root is the deepest node in the tree.
Example 3:
Input: root = [0,1,3,null,2]
Output: [2]
Explanation: The deepest node in the tree is 2, the valid subtrees are the subtrees of nodes 2, 1 and 0 but the subtree of node 2 is the smallest.
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
     TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return deep(root).second;
    }
     pair<int,TreeNode*> deep(TreeNode* root) {
        if (!root) 
            return {0, NULL};
        pair<int, TreeNode*> l = deep(root->left), r = deep(root->right);
        int d1 = l.first, d2 = r.first;
        return {max(d1,d2)+1, d1==d2?root:(d1>d2)?l.second:r.second};
    }
};