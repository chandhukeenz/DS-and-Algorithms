using namespace std;
#include <iostream>
#include<vector>

struct minMaxPair{
    int min;
    int max;
};

struct minMaxPair getMinMax(vector<int>arr,int n){
    struct minMaxPair minMax;
    int i=0;
    if(!n%2){
        if(arr[0]>arr[1]){
            minMax.min=arr[1];
            minMax.max=arr[0];
        }else{
            minMax.min=arr[0];
            minMax.max=arr[1];
        }
        i=2;
    }else{
        minMax.min=arr[0];
        minMax.max=arr[0];
        i=1;
    }
    while(i < n-1){
        if(arr[i] > arr[i+1]){
            if(arr[i] > minMax.max) minMax.max = arr[i];
            if(arr[i+1] < minMax.min) minMax.min = arr[i+1];
        }else{
            if(arr[i+1] > minMax.max) minMax.max = arr[i+1];
            if(arr[i] < minMax.min) minMax.min = arr[i];
        }
        i+=2;
    }
    return minMax;
}
int main(){
    vector<int> arr ={67,1000,2,99,1,33};
    int n=arr.size();
    minMaxPair minMax = getMinMax(arr,n);
    cout<<"max: "<<minMax.max<<"\nmin: "<<minMax.min;
    return 0;
}