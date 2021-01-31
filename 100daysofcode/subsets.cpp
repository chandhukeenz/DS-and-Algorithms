/*Subsets
Given an integer array nums of unique elements, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

Example 1:

Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
Example 2:

Input: nums = [0]
Output: [[],[0]]
*/
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subs;
        vector<int> sub;
        subsets(nums,0,sub,subs);
        return subs;
    }
    void subsets(vector<int>& nums,int i,vector<int>& sub,vector<vector<int>>& subs) {
        subs.push_back(sub);
        for (int j=i;j<nums.size();j++){
            sub.push_back(nums[j]);
            subsets(nums,j+1,sub,subs);
            sub.pop_back();
        }
    }
};