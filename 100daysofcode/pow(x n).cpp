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
#include<iostream>
using namespace std;

//basic idea:
//when n is even:
//2^10 -> 4^5 =>x*x ^ n/2
//when n is odd:
//4^5 ->4*(4)^4 =>x*(x^n-1)
//here n-1 is even ,so
//=>x*(x*x ^ n/2)
double pow(double x,long long int n){
    if(!n) return 1.0;
    double ans = pow(x*x,n/2)*(n%2?x:1);
    return n>0? ans:1/ans;
}

int main(){
    double x,ans=1.0;
    long long int n;
    cout<<"enter x and n:";
    cin>>x>>n;
    double a=pow(x,n);
    cout<<"The value of "<<x<<"^"<<n<<" is: "<<a;
    return 0;
}