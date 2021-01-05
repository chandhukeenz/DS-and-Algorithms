/*Max Consecutive Ones
Input: [1,1,0,1,1,1]
Output: 3
Explanation: The first two digits or the last three digits are consecutive 1s.
The maximum number of consecutive 1s is 3.
*/
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count=0,max_len=0;
        for(auto i:nums){
            if(i) max_len=max(max_len,++count);
            else count=0;
        }
        return max_len;
    }
};
	