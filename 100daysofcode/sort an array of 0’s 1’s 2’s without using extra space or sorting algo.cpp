//Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

//Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

//Follow up:

//Could you solve this problem without using the library's sort function?
//Could you come up with a one-pass algorithm using only O(1) constant space?

//Example 1:
//Input: nums = [2,0,2,1,1,0]
//Output: [0,0,1,1,2,2]
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int start=0,end=nums.size()-1,index=0;
        while(start<end && index<=end){
            if(nums[index]==0){
                nums[index]=nums[start];
                nums[start]=0;
                start++;
                index++;
            }else if(nums[index]==2){
                nums[index]=nums[end];
                nums[end]=2;
                end--;
            }else index++;
        }
    }
};
//move index and chk for 0 and 2
//if 0 swap with start ,inc start and index 
// if 2 swap with end,dec end
//if 1 just inc index

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int a=0,b=0,c=0,j=0;
        for(int i=0;i<nums.size();i++)
            nums[i]==0?a++:nums[i]==1?b++:c++;
        for(int i=0;i<nums.size();i++){
        if (a!=0){
            nums[i] =0;
            a--;
        }
        else if (b!=0){
            nums[i] = 1;
            b--;
        }
        else if (c!= 0){
            nums[i] =2;
            c--;
        }
    }
    }
};

//count number of 0,1,2
//overwrite the array 
