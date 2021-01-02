/*Reverse Pairs
Given an array nums, we call (i, j) an important reverse pair if i < j and nums[i] > 2*nums[j].

You need to return the number of important reverse pairs in the given array.

Example1:

Input: [1,3,2,3,1]
Output: 2
*/
class Solution {
public:
    int merge(vector<int>&nums,int low,int mid,int high){
        int count=0,j=mid+1; 
        for(int i=low;i<=mid;i++){
            while(j<=high && nums[i]>2LL*nums[j]) j++;
            count+= (j-(mid+1));
        }
        vector<int>temp;
        int left=low,right=mid+1;
        
        while(left<=mid&&right<=high){
            if(nums[left]<=nums[right]) temp.push_back(nums[left++]);
            else temp.push_back(nums[right++]);
        }
        while(left<=mid) temp.push_back(nums[left++]);
        while(right<=high) temp.push_back(nums[right++]);
        
        for(int i=low;i<=high;i++)
            nums[i]=temp[i-low];
        return count;
    }
    int _mergesort(vector<int>&nums,int low,int high){
        if(low>=high) return 0;
        int mid =(low+high)/2;
        int inv= _mergesort(nums,low,mid);
        inv+= _mergesort(nums,mid+1,high);
        inv+= merge(nums,low,mid,high);
        return inv;
    }
    int reversePairs(vector<int>& nums) {
        return _mergesort(nums,0,nums.size()-1);
    }
};