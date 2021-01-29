/* N-Queens
The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.

 

Example 1:


Input: n = 4
Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above
Example 2:

Input: n = 1
Output: [["Q"]]
*/
class Solution {
    public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> nQueens(n,string(n,'.'));
        solveNQueens(res,nQueens,0,n);
        return res;
    }
    void solveNQueens(vector<vector<string>>&res,vector<string>&nQueens,int row,int &n){
        if (row == n) {
            res.push_back(nQueens);
            return;
        }
        for (int col=0;col!=n; ++col)
            if (isValid(nQueens, row, col, n)) {
                nQueens[row][col] = 'Q';
                solveNQueens(res, nQueens, row + 1, n);
                nQueens[row][col] = '.';
            }
    }
    bool isValid(vector<string> &nQueens,int row,int col,int &n) {
        for (int i=0; i!=row; ++i)
            if (nQueens[i][col] == 'Q')
                return false;
        for (int i=row-1,j=col-1;i>=0 && j>=0;--i,--j)
            if (nQueens[i][j] == 'Q')
                return false;
        for (int i = row-1, j = col+1; i>=0 && j<n; --i, ++j)
            if (nQueens[i][j] == 'Q')
                return false;
        return true;
    }
};