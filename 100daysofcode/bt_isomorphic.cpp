/*
Check if Tree is Isomorphic 
Given two Binary Trees. Check whether they are Isomorphic or not.

Example 1:

Input:
 T1    1     T2:   1
     /   \        /  \
    2     3      3    2
   /            /
  4            4
Output: No

Example 2:

Input:
T1    1     T2:    1
    /  \         /   \
   2    3       3     2
  /                    \
  4                     4
Output: Yes
*/
/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

// Return True if the given trees are isomotphic. Else return False.
bool isIsomorphic(Node *r1,Node *r2)
{
    if(r1==NULL && r2==NULL) return true;
    if(r1==NULL || r2==NULL) return false;
    if(r1->data!=r2->data) return false;
    return (isIsomorphic(r1->left,r2->left)&&isIsomorphic(r1->right,r2->right))||
           (isIsomorphic(r1->left,r2->right)&&isIsomorphic(r1->right,r2->left));
}