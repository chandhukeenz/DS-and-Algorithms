/*4Sum
Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Notice that the solution set must not contain duplicate quadruplets.

Example 1:

Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
*/
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> output;
        if(nums.empty()) return output;
        int n= nums.size();
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int target_2 = target - nums[j]-nums[i];
                int front = j+1;
                int back = n-1;
                
                while(front<back){
                    int two_sum = nums[front]+nums[back];
                    if(two_sum< target_2) front++;
                    else if(two_sum>target_2) back--;
                    else{
                        vector<int> quad(4,0);
                        quad[0]=nums[i];
                        quad[1]=nums[j];
                        quad[2]=nums[front];
                        quad[3]=nums[back];
                        output.push_back(quad);
                        
                        while(front<back && nums[front]==quad[2]) front++;
                        while(front<back && nums[back]==quad[3]) back--;
                    }
                }
                while(j+1<n && nums[j+1]==nums[j]) j++;
            }
            while(i+1<n && nums[i+1]==nums[i]) i++;
        }
        return output;
    }
};