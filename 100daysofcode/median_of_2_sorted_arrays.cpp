/*
 Median of Two Sorted Arrays
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
Example 1:
Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
Example 2:
Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
Example 3:
Input: nums1 = [0,0], nums2 = [0,0]
Output: 0.00000
Example 4:
Input: nums1 = [], nums2 = [1]
Output: 1.00000
Example 5:
Input: nums1 = [2], nums2 = []
Output: 2.00000
*/
class Solution {
public:
  double findMedianSortedArrays(vector<int>& nums1,vector<int>& nums2) {
     int m = nums1.size(), n = nums2.size(), l = 0, r = m;
        if (m > n) return findMedianSortedArrays(nums2, nums1);
        while (l <= r) {
            int i = (l+r)/2, j = ((m+n+1)/2)-i;
            if (i && nums1[i-1] > nums2[j])
                r = i-1;
            else if (i < m && nums2[j-1] > nums1[i])
                l = i+1;
            else {
                int lmax = !i ? nums2[j-1] : (!j ? nums1[i-1] : max(nums1[i-1], nums2[j-1]));
                if ((m + n) % 2) return lmax;
                int rmin = (i == m) ? nums2[j] : (j == n ? nums1[i] : min(nums1[i],nums2[j]));
                return 0.5*(lmax + rmin);
            }
        }
        return 0.0;
  }
};