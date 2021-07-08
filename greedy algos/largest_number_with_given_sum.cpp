/*
Largest number with given sum 
Geek lost the password of his super locker. He remembers the number of digits N as well as the sum S of all the digits of his password. He know that his password is the largest number of N digits that can be made with given sum S.
As he is busy doing his homework, help him retrieving his password.
Example 1:
Input:
N = 5, S = 12
Output:
93000
Explanation:
Sum of elements is 12. Largest possible 
5 digit number is 93000 with sum 12.
Example 2:
Input:
N = 3, S = 29
Output:
-1
Explanation:
There is no such three digit number 
whose sum is 29.
*/
class Solution
{
    public:
    //Function to return the largest possible number of n digits
    //with sum equal to given sum.
    string largestNumber(int n, int sum)
    {
        if(9*n >= sum){
            string s="";
            while(n>0){
                if(sum >=9){
                    s+="9";
                    sum-=9;
                }else{
                    s+=to_string(sum);
                    sum-=sum;
                }
                n--;
            }
            return s;
        }
        return "-1";
    }
};