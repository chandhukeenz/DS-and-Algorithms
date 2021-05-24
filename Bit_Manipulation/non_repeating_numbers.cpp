/*
Non Repeating Numbers 
Given an array A containing 2*N+2 positive numbers, out of which 2*N numbers exist in pairs whereas the other two number occur exactly once and are distinct. Find the other two numbers.
Example 1:
Input: 
N = 2
arr[] = {1, 2, 3, 2, 1, 4}
Output:
3 4 
Explanation:
3 and 4 occur exactly once.
Example 2:
Input:
N = 1
arr[] = {2, 1, 3, 2}
Output:
1 3
Explanation:
1 3 occur exactly once.
*/
class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        int xorrTotal=0;
        for(int i=0;i<nums.size();i++){
            xorrTotal=xorrTotal^nums[i];
        }
        int rightsetbitnumber= xorrTotal & -xorrTotal;
        int x=0,y=0;
        for(int i=0;i<nums.size();i++){
            if((nums[i] & rightsetbitnumber)==0){
                x=x^nums[i];
            }else y=y^nums[i];
        }
        vector<int>nonrepeating;
        if(x>y)swap(x,y);
        nonrepeating.push_back(x);
        nonrepeating.push_back(y);
        return nonrepeating;
    }
};