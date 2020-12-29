//Find Missing And Repeating
//Given an unsorted array Arr of size N of positive integers. One number 'A' from set {1, 2, …N} is missing and one number 'B' occurs twice in array. Find these two numbers.

//Example 1:

//Input:
//N = 2
//Arr[] = {2, 2}
//Output: 2 1
//Explanation: Repeating number is 2 and 
//smallest positive missing number is 1.

class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        int *output = new int[2];
        for(int i=0;i<n;i++){
            if(arr[abs(arr[i])-1]>0){
                arr[abs(arr[i])-1]= -arr[abs(arr[i])-1];
            }else output[0]=abs(arr[i]);
        }
        for(int i=0;i<n;i++){
            if(arr[i]>0) output[1]=i+1;
        }
        return output;
    }
};

//4   3  6  2 1  1
//1   2  3  4 5  6
//-4 -3 -6 -2 1 -1
//now traverse through the array and mark the entry of the each number in its corrs index by making the value at that index negative
//at one point when u chk a number to be already negative that means the number is repeated
//now by again traversing the array we can find the missing value as the index whose value remains positive 