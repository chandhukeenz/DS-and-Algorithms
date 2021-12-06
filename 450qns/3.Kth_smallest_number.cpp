/*Given an array arr[] and an integer K where K is smaller than size of array, the task is to find the Kth smallest element in the given array. It is given that all array elements are distinct.

Example 1:

Input:
N = 6
arr[] = 7 10 4 3 20 15
K = 3
Output : 7
Explanation :
3rd smallest element in the given 
array is 7.
Example 2:

Input:
N = 5
arr[] = 7 10 4 20 15
K = 4
Output : 15
Explanation :
4th smallest element in the given 
array is 15.
Your Task:
You don't have to read input or print anything. Your task is to complete the function kthSmallest() which takes the array arr[], integers l and r denoting the starting and ending index of the array and an integer K as input and returns the Kth smallest element.*/

//min heap O(n + kLogn).
int kthSmallest(int arr[], int l, int r, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i=l;i<=r;i++){
            pq.push(arr[i]);
        }
        for(int i=0;i<k-1;i++) pq.pop();
        int ans = pq.top();
        return ans;
}
//if max heap O(k + (n-k)*Logk)

//quickselect
    void swap(int *a, int *b){
        int temp = *a;
        *a = *b;
        *b = temp;
    }
    int partition(int arr[], int l, int r){
        int n = r-l+1;
	    int pivot = rand() % n;
	    swap(&arr[l+pivot], &arr[r]);
        int x = arr[r], i = l;
        for (int j = l; j <= r - 1; j++) {
            if (arr[j] <= x) {
                swap(&arr[i], &arr[j]);
                i++;
            }
        }
        swap(&arr[i], &arr[r]);
        return i;
    }
    int kthSmallest(int arr[], int l, int r, int k) {
         if (k > 0 && k <= r-l+1){
             int pos = partition(arr,l,r);
             if (pos-l == k-1) return arr[pos];
             if (pos-l > k-1) return kthSmallest(arr, l, pos-1, k);
             return kthSmallest(arr, pos+1, r, k-pos+l-1);
         }
         return -1;
    }
//O(N) best 
//O(N*N) worst