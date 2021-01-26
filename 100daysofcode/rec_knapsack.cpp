/*
Given weights and values of n items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack. 
In other words, given two integer arrays val[0..n-1] and wt[0..n-1] which represent values and weights associated with n items respectively. 
Also given an integer W which represents knapsack capacity, find out the maximum value subset of val[] 
such that sum of the weights of this subset is smaller than or equal to W.
You cannot break an item, either pick the complete item or don’t pick it (0-1 property).
example:
input:weight[]={1,2,3,5};
      price[]={40,20,30,100};
      N=4
      C=7
output:140
*/
#include<iostream>
using namespace std;

int profit(int n,int c,int*wt,int *price){
    if(n==0||c==0) return 0;

    int ans=0;
    int inc,exc;
    inc=exc=0;
    if(wt[n-1]<=c){
        inc=price[n-1]+profit(n-1,c-wt[n-1],wt,price);
    }
    exc=profit(n-1,c,wt,price);
    ans=max(inc,exc);
    return ans;
}

int main(){
    int weight[]={1,2,3,5};
    int price[]={40,20,30,100};
    int n=4;
    int c=7;
    cout<<profit(n,c,weight,price);
    return 0;
}