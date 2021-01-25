/*Check If All 1's Are at Least Length K Places Away
Given an array nums of 0s and 1s and an integer k, 
return True if all 1's are at least k places away from each other, 
otherwise return False.
Example 1:
Input: nums = [1,0,0,0,1,0,0,1], k = 2
Output: true
Explanation: Each of the 1s are at least 2 places away from each other.
Example 2:
Input: nums = [1,0,0,1,0,1], k = 2
Output: false
Explanation: The second 1 and third 1 are only one apart from each other.
*/
class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int c;
        if(nums[0]==0) c=1;
        else c=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==0) c++;
            else{
                if(c<k) return false;
                else c=0;
            }
        }
        return true;
    }
};