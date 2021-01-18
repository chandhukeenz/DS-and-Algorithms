/*Single Element in a Sorted Array
You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once. Find this single element that appears only once.

Follow up: Your solution should run in O(log n) time and O(1) space.

Example 1:

Input: nums = [1,1,2,3,3,4,4,8,8]
Output: 2
Example 2:

Input: nums = [3,3,7,7,10,11,11]
Output: 10
*/
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        int start=0,end=nums.size()-1,mid;
        while(start<end){
            mid=start+((end-start)/2);
            if(nums[mid]!=nums[mid+1] && nums[mid]!=nums[mid-1]) return nums[mid];
            else if(nums[mid]==nums[mid-1]){
                if((mid-start)%2==0) end=mid-2;
                else start=mid+1;
            }else{
                if((end-mid)%2==0) start=mid+2;
                else end=mid-1;
            }
        }
        return nums[start];
    }
};
