/* Combination Sum II
 Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.

 

Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]
Example 2:

Input: candidates = [2,5,2,1,2], target = 5
Output: 
[
[1,2,2],
[5]
]
*/
class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &candidates, int target){
        sort(candidates.begin(), candidates.end());
        vector<std::vector<int>> result;
        vector<int> combination;
        combinationSum2(candidates, target, result, combination, 0);
        return result;
    }
    void combinationSum2(vector<int> &candidates,int target,vector<vector<int>> &result, vector<int> &combination,int begin){
        if (!target){
            result.push_back(combination);
            return;
        }
        for (int i=begin;i!=candidates.size() && target >= candidates[i];i++)
            if (i==begin||candidates[i]!=candidates[i-1]){
                combination.push_back(candidates[i]);
                combinationSum2(candidates,target-candidates[i],result,combination,i+1);
                combination.pop_back();
            }
    }
};