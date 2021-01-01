/*Largest subarray with 0 sum
Given an array having both positive and negative integers. The task is to compute the length of the largest subarray with sum 0.

Example 1:

Input:
N = 8
A[] = {15,-2,2,-8,1,7,10,23}
Output: 5
Explanation: The largest subarray with
sum 0 will be -2 2 -8 1 7.
*/
int maxLen(int A[], int n)
{
    // Your code here
    unordered_map<int,int> m;
    int max_length=0,sum=0;
    for(int i=0;i<n;i++){
        sum=sum+A[i];
        if(sum==0) max_length=i+1;
        else{
            if(m.find(sum)!=m.end()){
                max_length=max(max_length,i-m[sum]);
            }else m[sum]=i;
        }
    }
    return max_length;
}
