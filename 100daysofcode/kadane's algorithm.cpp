 //Maximum Subarray
 //Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

//Example 1:

//Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
//Output: 6
//Explanation: [4,-1,2,1] has the largest sum = 6.

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum,current_sum;
        current_sum=nums[0];
        max_sum = current_sum;
        for(int i=1;i<nums.size();i++){
            current_sum= max(current_sum+nums[i],nums[i]);
            max_sum= max(max_sum,current_sum);
        }
        return max_sum;
    }
};

//2 decisions have to made - what will be my nxt max_sum and current_sum
//current_max is updated to a new nxt element if it is greater than the summation untill that point
//max_sum will be taking up the value of current_sum if it surpasses the past summation max_sum 