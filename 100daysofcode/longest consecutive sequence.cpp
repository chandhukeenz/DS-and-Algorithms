/*Longest Consecutive Sequence
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

Follow up: Could you implement the O(n) solution? 

 

Example 1:

Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> a;
        for(int num:nums)
            a.insert(num);
        int max_length=0,current_length,current_num;
        
        for(int num:nums){
            if(!a.count(num-1)){
                current_num =num;
                current_length=1;
                while(a.count(current_num+1)){
                    current_num++;
                    current_length++;
                }
                max_length =max(max_length,current_length);
            }
        }
        return max_length;
    }
};