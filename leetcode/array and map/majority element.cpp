//Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

//You may assume that the array is non-empty and the majority element always exist in the array.

//Input: [2,2,1,1,1,2,2]
//Output: 2

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
