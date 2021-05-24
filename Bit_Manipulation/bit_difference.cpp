/*
Bit Difference 
Basic Accuracy: 63.36% Submissions: 15640 Points: 1
You are given two numbers A and B. The task is to count the number of bits needed to be flipped to convert A to B.

Example 1:

Input: A = 10, B = 20
Output: 4
Explanation:
A  = 01010
B  = 10100
As we can see, the bits of A that need 
to be flipped are 01010. If we flip 
these bits, we get 10100, which is B.
Example 2:

Input: A = 20, B = 25
Output: 3
Explanation:
A  = 10100
B  = 11001
As we can see, the bits of A that need 
to be flipped are 10100. If we flip 
these bits, we get 11001, which is B.
*/
class Solution{
    public:
    // Function to find number of bits needed to be flipped to convert A to B
    int countBitsFlip(int a, int b){
        int flip=0;
        for(int i=0;i<32;i++){
            if((a&1)!=(b&1)) flip++;
            a=a>>1;
            b=b>>1;
        }
        return flip;
    }
};