/*Trapping Rain Water
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.
Example 1:

Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
Example 2:

Input: height = [4,2,0,3,2,5]
Output: 9
*/
class Solution {
public:
    int trap(vector<int>& height) {
        int len=height.size();
        int l=0,r=len-1,vol=0,maxleft=0,maxright=0;
        int hl,hr;
        while(l<=r){
            hl=height[l];
            hr=height[r];
            if(hl<=hr){
                if(hl>=maxleft) maxleft=max(maxleft,hl);
                else vol+=maxleft-hl;
                l++;
            }else{
                if(hr>=maxright) maxright=max(maxright,hr);
                else vol+=maxright-hr;
                r--;
            }
        }
        return vol;
    }
};