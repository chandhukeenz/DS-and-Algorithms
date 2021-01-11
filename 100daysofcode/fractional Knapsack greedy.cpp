/*Fractional Knapsack
Given weights and values of N items, we need to put these items in a knapsack of capacity W to get the maximum total value in the knapsack.
Note: Unlike 0/1 knapsack, you are allowed to break the item. 

Example 1:

Input:
N = 3, W = 50
values[] = {60,100,120}
weight[] = {10,20,30}
Output: 240.00
Explanation: Total maximum value of item
we can have is 240.00 from the given
capacity of sack. 

Example 2:

Input:
N = 2, W = 50
values[] = {60,100}
weight[] = {10,20}
Output: 160.00
Explanation: Total maximum value of item
we can have is 160.00 from the given
capacity of sack.
*/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


 // } Driver Code Ends


//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

bool compare(struct Item a, struct Item b) 
{ 
    double r1,r2;
    r1 = (double)a.value / (double)a.weight; 
    r2 = (double)b.value / (double)b.weight; 
    return r1 > r2; 
} 
double fractionalKnapsack(int W, struct Item arr[], int n) 
{ 
    int curWeight = 0,remain;
    double fval = 0.0; 
    sort(arr, arr + n, compare); 
    for (int i = 0; i < n; i++){ 
        if (curWeight + arr[i].weight <= W){ 
            curWeight += arr[i].weight; 
            fval += arr[i].value; 
        } 
        else{ 
            remain = W - curWeight; 
            fval+= arr[i].value*((double)remain / (double)arr[i].weight); 
            break; 
        } 
    } 
    return fval; 
} 
  

// { Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		cout<<fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}  // } Driver Code Ends