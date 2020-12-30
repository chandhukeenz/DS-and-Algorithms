/*Inversion Count for an array indicates – how far (or close) the array is from being sorted. If array is already sorted then inversion count is 0. If array is sorted in reverse order that inversion count is the maximum. 
Formally speaking, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j 
Example: 

Input: arr[] = {8, 4, 2, 1}
Output: 6
*/
#include<iostream>
using namespace std;
int merge(int arr[],int temp[],int left,int mid,int right){
    int i,j,k;
    int inv_count=0;
    i=left;
    j=mid;
    k=left;
    while((i<= mid-1)&&(j<=right)){
        if(arr[i]<=arr[j]){
            temp[k++]=arr[i++];
        }else{
            temp[k++]=arr[j++];
            inv_count = inv_count+(mid-i);
        }
    }
    while(i<= mid-1)
    temp[k++]=arr[i++];
    while(j<=right)
    temp[k++]=arr[j++];
    for(i=left;i<=right;i++)
    arr[i]=temp[i];
    return inv_count;
}

int _mergesort(int arr[],int temp[],int left,int right){
    int mid,inv_count=0;
    if(right>left){
        mid=(right+left)/2;
        inv_count +=_mergesort(arr,temp,left,mid);
        inv_count += _mergesort(arr,temp,mid+1,right);
        inv_count += merge(arr,temp,left,mid+1,right);
    }
    return inv_count;
}

int main(){
    int arr[]={5,3,2,4,1};
    int n = 5;
    int temp[n];
    int ans = _mergesort(arr,temp,0,n-1);
    cout<<"number of inversions are "<<ans;
    return 0;
}
