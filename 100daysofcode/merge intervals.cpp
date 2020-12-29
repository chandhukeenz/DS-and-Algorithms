//Merge Intervals
//Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals,
//and return an array of the non-overlapping intervals that cover all the intervals in the input.

//Example 1:
//Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
//Output: [[1,6],[8,10],[15,18]]
//Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>output;
        if(intervals.size()==0) return output;
        sort(intervals.begin(),intervals.end());
        vector<int> temp = intervals[0];
        for(auto i: intervals){
            if(i[0]<=temp[1]){
                temp[1]=max(i[1],temp[1]);
            }else{
                output.push_back(temp);
                temp=i;
            }
        }
        output.push_back(temp);
        return output;  
    }
};

//have a temp vector of the current range (initially the first vector of intervals)
//whenever the range breaks, push it into the output vector vector and assign temp to be the iterated sorted intervals next vector
//finally push the last temp into the output