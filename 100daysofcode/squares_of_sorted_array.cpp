/*
 Squares of a Sorted Array
Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.
Example 1:
Input: nums = [-4,-1,0,3,10]
Output: [0,1,9,16,100]
Explanation: After squaring, the array becomes [16,1,0,9,100].
After sorting, it becomes [0,1,9,16,100].
Example 2:
Input: nums = [-7,-3,2,3,11]
Output: [4,9,9,49,121]
*/
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int i=0,s=nums.size();
        int j=s-1;
        vector<int>output(s);
        for(int k=s-1;k>=0;k--){
            if(abs(nums[i])>abs(nums[j])){
                output[k]=nums[i]*nums[i];
                i++;
            }else{
                output[k]=nums[j]*nums[j];
                j--;
            }
        }
        return output;
    }
};