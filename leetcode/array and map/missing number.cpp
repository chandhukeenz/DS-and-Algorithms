//missing numbers
//Input: nums = [3,0,1]
//Output: 2
//Input: nums = [0,1]
//Output: 2
//Input: nums = [1]
//Output: 0
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int maxi=0,sum=0,missing,ch=0;
        for(int i=0;i<nums.size();i++){
            sum=sum+nums[i];
            maxi=max(maxi,nums[i]);
            if(nums[i]==0)ch=1;
        }
        missing=((maxi*(maxi+1))/2)-sum;
        if(ch==0)missing=0;else if(missing==0)missing=maxi+1;
        return missing;
    }
};