/*Majority Element
Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

Example 1:

Input: nums = [3,2,3]
Output: 3
Example 2:

Input: nums = [2,2,1,1,1,2,2]
Output: 2
*/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=0;
        int element=0;
        for(int num:nums){
            if(count==0){
                element = num;
            }
            if(num==element) count+=1;
            else count-=1;
        }
        return element;
    }
};
//moore's voting algorithm
