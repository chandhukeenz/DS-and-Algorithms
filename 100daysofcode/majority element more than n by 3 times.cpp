/* Majority Element II
 Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

Follow-up: Could you solve the problem in linear time and in O(1) space?

 

Example 1:

Input: nums = [3,2,3]
Output: [3]
Example 2:

Input: nums = [1]
Output: [1]
Example 3:

Input: nums = [1,2]
Output: [1,2]
*/
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int size=nums.size();
        int n1=-1,n2=-1,c1=0,c2=0;
        vector<int> ans;
        for(int i=0;i<size;i++){
            if(nums[i]==n1) c1++;
            else if(nums[i]==n2) c2++;
            else if(c1==0){
                n1=nums[i];
                c1=1;
            }else if(c2==0){
                n2=nums[i];
                c2=1;
            }else{
                c1--;
                c2--;
            }
        }
        c1=c2=0;
        for(int i=0;i<size;i++){
            if(nums[i]==n1)c1++;
            else if(nums[i]==n2)c2++;
        }
        if(c1>size/3)ans.push_back(n1);
        if(c2>size/3)ans.push_back(n2);
        return ans;
    }
};