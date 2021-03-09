/*
Subarray Sums Divisible by K
Given an array A of integers, return the number of (contiguous, non-empty) subarrays that have a sum divisible by K.
Example 1:
Input: A = [4,5,0,-2,-3,1], K = 5
Output: 7
Explanation: There are 7 subarrays with a sum divisible by K = 5:
[4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]
Note:
1 <= A.length <= 30000
-10000 <= A[i] <= 10000
2 <= K <= 10000
*/
class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        vector<int>counts(K,0);
        int sum=0;
        for(int x:A){
            sum+= (x%K + K)%K;
            counts[sum%K]++;
        }
        int res=counts[0];
        for(int y:counts){
            res+=(y*(y-1))/2;
        }
        return res;
    }
};