/*
Largest Rectangle in Histogram
Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.

Example:

Input: [2,1,5,6,2,3]
Output: 10
*/

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> indexes;
        int maxArea = 0;
        heights.push_back(0);
        indexes.push(0);
        for (int i = 1; i < heights.size(); i++){
            while(!indexes.empty() && heights[i] < heights[indexes.top()]){
                int h = heights[indexes.top()];
                indexes.pop();
                int prev = indexes.empty() ? -1 : indexes.top();
                maxArea = max(maxArea, (i - prev -1) * h);
            }
            indexes.push(i);
        }
        return maxArea;
    }
};