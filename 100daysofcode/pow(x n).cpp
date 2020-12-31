 /*Pow(x, n)
 Implement pow(x, n), which calculates x raised to the power n (i.e. xn).
Example 1:

Input: x = 2.00000, n = 10
Output: 1024.00000
Example 2:

Input: x = 2.10000, n = 3
Output: 9.26100
Example 3:

Input: x = 2.00000, n = -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25
*/
class Solution {
public:
    double myPow(double x, int n) {
        double ans=1.0;
        long long n1=n;
        if(n1<0) n1=-1*n1;
        while(n1){
            if(n1%2){
                ans=ans*x;
                n1--;
            }else{
                x=x*x;
                n1=n1/2;
            }
        }
        if(n<0) ans=(double)(1.0)/(double)(ans);
        return ans;
    }
};

//2^10 -> 4^5
//4^5 ->4*(4)^4