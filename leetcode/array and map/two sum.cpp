//Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

//You may assume that each input would have exactly one solution, and you may not use the same element twice.

//You can return the answer in any order.

//Input: nums = [2,7,11,15], target = 9
//Output: [0,1]
//Output: Because nums[0] + nums[1] == 9, we return [0, 1].

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m;
        int size=nums.size();
        int diff;
        vector<int> a(2);
        for(int i=0;i<size;i++){
            diff= target - nums[i];
            if(m.find(diff)!=m.end()&&m.find(diff)->second!=i){
                a[0]=i;
                a[1]=m.find(diff)->second;
                return a;
            }
            m[nums[i]]=i;
        }
        return a;
    }
};