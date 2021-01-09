//Container With Most Water
//Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.
//Input: [1,8,6,2,5,4,8,3,7]
//Output: 49
class Solution {
public:
    int maxArea(vector<int>& height) {
        int area=0,i=0,j=height.size()-1,hi,hj;
        while(i<j){
            hi=height[i];
            hj=height[j];
            if(hi>hj){
                area=max(area,hj*(j-i));
                j--;
            }else{
                area=max(area,hi*(j-i));
                i++;
            }
        }
        return area;
    }
};