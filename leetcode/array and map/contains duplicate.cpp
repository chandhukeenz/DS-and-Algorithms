//contains duplicate
//Input: [1,2,3,1]
//Output: true

//Input: [1,2,3,4]
//Output: false

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        return nums.size() > set<int>(nums.begin(), nums.end()).size();     
    }
};
