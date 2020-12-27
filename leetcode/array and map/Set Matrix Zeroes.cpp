//Given an m x n matrix. If an element is 0, set its entire row and column to 0. Do it in-place.

//Follow up:

//A straight forward solution using O(mn) space is probably a bad idea.
//A simple improvement uses O(m + n) space, but still not the best solution.
//Could you devise a constant space solution?

//Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
//Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int r=matrix.size(),c=matrix[0].size(),col=1;
        
        for(int i=0;i<r;i++){
            if(matrix[i][0]==0) col=0;
            for(int j=1;j<c;j++)
                if(matrix[i][j]==0) matrix[i][0]=matrix[0][j]=0;
        }
        for(int i=r-1;i>=0;i--){
            for(int j=c-1;j>=1;j--)
                if(matrix[i][0]==0 || matrix[0][j]==0) matrix[i][j]=0;
            if(col==0) matrix[i][0]=0;
        }
    }
};

//use the first row and column as an entry for the presence of zero in its' row or colomn.
//have col as 0 if there is any zero in the first column.[j=0 is checked separately and its' entry is done in col](j starts from 1)
//now backtrace the 2d array and convert each number to zero by checking the entries in the flag row and column
//(again j=0 is separately traversed while checking col)
