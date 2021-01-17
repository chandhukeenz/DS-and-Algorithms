/*Search in Rotated Sorted Array
You are given an integer array nums sorted in ascending order (with distinct values), and an integer target.

Suppose that nums is rotated at some pivot unknown to you beforehand (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

If target is found in the array return its index, otherwise, return -1.

 

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
Example 3:

Input: nums = [1], target = 0
Output: -1
*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start =0,end=nums.size()-1;
        int mid;
        while(start<=end){
            mid=(start+end)/2;
            if(nums[mid]==target) return mid;
            else if(nums[start]<=nums[mid]){
                if(nums[start]<=target and nums[mid]>=target) end=mid-1;
                else start=mid+1;
            }else{
                if(nums[end]>=target and nums[mid]<=target) start=mid+1;
                else end=mid-1;
            }
        }
        return -1;
    }
};