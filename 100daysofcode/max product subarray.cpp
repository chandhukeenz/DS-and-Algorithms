/*Maximum Product Subarray
Given an integer array nums, find the contiguous subarray within an array (containing at least one number) which has the largest product.

Example 1:

Input: [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.
Example 2:

Input: [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
*/
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty()) return 0;
        int best = INT_MIN, maxProd = 1 ,minProd = 1;   
        for (int n: nums) {
            if (n < 0)swap(maxProd, minProd);
            maxProd = max(maxProd*n, n);
            minProd = min(minProd*n, n);
            best = max(best, maxProd);
        }
        return best;
    }
};