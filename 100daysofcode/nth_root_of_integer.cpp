#include<iostream>
using namespace std;

float root_of(int n,int p){
    int start=0,end=n,mid;
    float ans=-1;
    while(start<=end){
        mid=(start+end)/2;
        if(mid*mid==n) return mid;
        if(mid*mid<n){
            ans=mid;
            start=mid+1;
        }else end=mid-1;
    }
    float inc=0.1;
    for(int i=1;i<=p;i++){
        while(ans*ans<=n) ans=ans+inc;
        ans=ans-inc;
        inc=inc/10;
    }
    return ans;
}

int main(){
    int n,p;
    float ans;
    cout<<endl<<"enter the number:";
    cin>>n;
    cout<<endl<<"enter the decimal precision:";
    cin>>p;
    cout<<root_of(n,p);
    return 0;
}