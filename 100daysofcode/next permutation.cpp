/*Next Permutation
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such an arrangement is not possible, it must rearrange it as the lowest possible order (i.e., sorted in ascending order).

The replacement must be in place and use only constant extra memory.

Example 1:

Input: nums = [1,2,3]
Output: [1,3,2]
*/
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int j=nums.size()-1,i;
        for(i=j-1;i>=0;i--)
            if(nums[i]<nums[i+1])
                break;
        if(i<0)reverse(nums.begin(),nums.end());
        else{
            while(!(nums[i]<nums[j]))j--;
            swap(nums[i],nums[j]);
            reverse(nums.begin()+i+1,nums.end());  
        }
    }
};

/*
1 3 5 4 2  --> 1 4 2 3 5
1.)traverse from right to left to find i such that,
a[i]<a[i+1]
2.)again traverse from right to left to find j such that,
a[j]>a[i]
3.) now swap this a[i] and a[j]
4.)now reverse from a[i+1] to last
 the goal here is to find the next dictionary sequence to this number
 every number will have a breaking point to an increasing sequence from the right of the number.
 before this breaking point has a number lets say 13 in the eg , now we want the next number to 13
 now again look at the rightside of the breaking point of the number to get the nxt greatest number to 13.
 this can be done by foll second and third step.
 now we have to arrange the rightside number to min possible value. this can be done by step 4...as
the right side was in inc order from right to left before...we reverse it to attain min value 
*/