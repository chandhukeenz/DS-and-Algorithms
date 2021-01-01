/*Subarray with given XOR
Problem Description

Given an array of integers A and an integer B.

Find the total number of subarrays having bitwise XOR of all elements equals to B.
Input 1:

 A = [4, 2, 2, 6, 4]
 B = 6
 Output 1:
 4
 */
 int Solution::solve(vector<int> &A, int B) {
    unordered_map<int,int>m;
    int count=0,xorr=0;
    for(auto i:A){
        xorr=xorr ^ i;
        if(xorr==B) count++;
        if(m.find(xorr^B)!=m.end())
           count=count+m[xorr^B];
        m[xorr]++;
    }
    return count;
}
