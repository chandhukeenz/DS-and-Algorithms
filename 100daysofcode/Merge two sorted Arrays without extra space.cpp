//Merge Without Extra Space
//Given two sorted arrays arr1[] and arr2[] of sizes N and M in non-decreasing order. Merge them in sorted order without using any extra space. Modify arr1 so that it contains the first N elements and modify arr2 so that it contains the last M elements. 
 
//Example 1:

//Input: 
//N = 4, arr1[] = [1 3 5 7] 
//M = 5, arr2[] = [0 2 6 8 9]
//Output: 
//arr1[] = [0 1 2 3]
//arr2[] = [5 6 7 8 9]
//Explanation: After merging the two 
//non-decreasing arrays, we get, 
//0 1 2 3 5 6 7 8 9.

void merge(int arr1[], int arr2[], int n, int m) 
{ 
    int gap=ceil((n+m)/2);
    int i=0,j=i+gap,temp;
    while(gap>=1){
        while(j<n+m){
            if(i<n&&j<n&&(arr1[i]>arr1[j])) swap(arr[i],arr[j]);
            else if(i<n&&j>=n&&(arr1[i]>arr2[j-n])) swap(arr1[i],arr2[j-n]);
            else if(i>=n&&j>=n&& (arr2[i-n]>arr2[j-n])) swap(arr2[i-n],arr2[j-n]);
            i++;j++;
        }
        gap=gap/2;
        i=0;j=i+gap;
    }
} 
//gap method
