/*
Unique Binary Search Trees
Given an integer n, return the number of structurally unique BST's (binary search trees) which has exactly n nodes of unique values from 1 to n.
Example 1:
Input: n = 3
Output: 5
Example 2:

Input: n = 1
Output: 1
*/
class Solution {
public:
    int numTrees(int n) {
        vector<int>a;
        a.push_back(1);
        a.push_back(1);
        for(int i=2;i<=n;i++){
            int x=0;
            for(int j=0;j<i;j++){
                x+=a[j]*a[i-j-1];
            }
            a.push_back(x);
        }
        return a.back();
    }
};