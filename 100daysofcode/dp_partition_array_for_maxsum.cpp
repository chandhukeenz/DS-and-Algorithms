/*
Partition Array for Maximum Sum
Given an integer array arr, you should partition the array into (contiguous) subarrays of length at most k. 
After partitioning, each subarray has their values changed to become the maximum value of that subarray.
Return the largest sum of the given array after partitioning.
Example 1:
Input: arr = [1,15,7,9,2,5,10], k = 3
Output: 84
Explanation: arr becomes [15,15,15,9,10,10,10]
Example 2:
Input: arr = [1,4,1,5,7,3,6,1,9,9,3], k = 4
Output: 83
Example 3:
Input: arr = [1], k = 1
Output: 1
Constraints:
1 <= arr.length <= 500
0 <= arr[i] <= 109
1 <= k <= arr.length
*/
class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int> dp(k);
        int currentMax,best;
        for (int i=1; i<=n;i++) {
            currentMax = 0;best = 0;
            for (int j=1;j<= k && (i-j)>=0;j++) {
                currentMax = max(currentMax, arr[i-j]);
                best = max(best, dp[(i-j)%k]+(currentMax*j) );
            }
            dp[i%k]=best; 
        }
        return dp[n%k];
    }
};