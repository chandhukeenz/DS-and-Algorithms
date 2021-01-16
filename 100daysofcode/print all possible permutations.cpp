/*Permutations
Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.
Example 1:
Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
Example 2:

Input: nums = [0,1]
Output: [[0,1],[1,0]]
Example 3:

Input: nums = [1]
Output: [[1]]
*/
class Solution {
public:
    vector<vector<int>> permute(vector<int> &num){
	    vector<vector<int>> result;
	    permuteRecursive(num,0,result);
	    return result;
    }
	void permuteRecursive(vector<int> &num,int begin,vector<vector<int>> &result){
		if(begin>=num.size()){
		    result.push_back(num);
		    return;
		}
		for(int i=begin;i<num.size();i++){
		    swap(num[begin],num[i]);
		    permuteRecursive(num,begin+1,result);
		    swap(num[begin],num[i]);
		}
    }
};