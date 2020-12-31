/*Unique Paths
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?

Input: m = 3, n = 2
Output: 3
Explanation:
From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Down -> Down
2. Down -> Down -> Right
3. Down -> Right -> Down
*/
class Solution {
public:
    int uniquePaths(int m, int n) {
        int N = n+m-2;
        int r = m-1;
        double result =1;
        for(int i=1;i<=r;i++){
            result=result*(N-r+i)/i;
        }
        return (int)result;
    }
};

/* number of directions will always be 
 right -> n-1
 down -> m-1
 total = n+m-2
 so the total number of combinations can be n+m-2 C n-1 or n+m-2 C m-1 
 10C3 will be written as (8*9*10)/(3*2*1)
 */