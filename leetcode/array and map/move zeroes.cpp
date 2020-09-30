//move zeroes
//Input: [0,1,0,3,12]
//Output: [1,3,12,0,0]

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i=0,temp;
        for(int j=0;j<nums.size();j++){
            if(nums[j]!=0){
                temp=nums[j];
                nums[j]=nums[i];
                nums[i]=temp;
                i++;
            }
        }
    }
};