/*
PRATA - Roti Prata
no tags 
IEEE is having its AGM next week and the president wants to serve cheese prata after the meeting. 
The subcommittee members are asked to go to food connection and get P(P<=1000) pratas packed for the function.
The stall has L cooks(L<=50) and each cook has a rank R(1<=R<=8). A cook with a rank R can cook 1 prata in the first R minutes 1 more prata in the next 2R minutes, 1 more prata in 3R minutes and so on(he can only cook a complete prata) ( For example if a cook is ranked 2.. 
he will cook one prata in 2 minutes one more prata in the next 4 mins an one more in the next 6 minutes hence in total 12 minutes he cooks 3 pratas in 13 minutes also he can cook only 3 pratas as he does not have enough time for the 4th prata). 
The webmaster wants to know the minimum time to get the order done. Please write a program to help him out.

Input
The first line tells the number of test cases. Each test case consist of 2 lines. In the first line of the test case we have P the number of prata ordered. In the next line the first integer denotes the number of cooks L and L integers follow in the same line each denoting the rank of a cook.

Output
Print an integer which tells the number of minutes needed to get the order done.
*/
#include<iostream>
#include<climits>
using namespace std;

bool ispossible(int arr[],int n,int p,int min_time){
    int time=0;
    int cook=0;
    int k=0;
    for(int i=0;i<p;i++){
        if(time+(arr[cook]*(k+1))>min_time){
            cook++;
            time=arr[cook];
            k=1;
            if(cook>=n) return false;
        }else{
            time+=(arr[cook]*(k+1));
            k++;
        }
    }
    return true;
}

int mintime(int arr[],int n,int p){
    int start=0,end=(arr[0]*(p*(p+1)))/2;
    int ans=INT_MAX;
    while(start<=end){
        int mid=(start+end)/2;
        if(ispossible(arr,n,p,mid)){
            ans=min(ans,mid);
            end=mid-1;
        }else start=mid+1;
    }
    return ans;
}
int main(){
    int p;
    cin>>p;
    int arr[100];
    int n;
    cin>>n;
    for(int i=0;i<n;i++) cin>>arr[i];
    cout<<mintime(arr,n,p)<<endl;
    return 0;
}
