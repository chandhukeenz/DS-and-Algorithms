 /*Search a 2D Matrix
 Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(!matrix.size()) return false;
        int r= matrix.size(),c=matrix[0].size();
        int start=0,end=(r*c)-1,mid;
        while(start<=end){
            mid=(start+(end-start)/2);
            if(matrix[mid/c][mid%c]==target) return true;
            if(matrix[mid/c][mid%c]<target) start=mid+1;
            else end=mid-1;
        }
        return false;
    }
};
