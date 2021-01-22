/*Tic Tac Toe 
A Tic-Tac-Toe board is given after some moves are played. Find out if the given board is valid, i.e., is it possible to reach this board position after some moves or not.

Note that every arbitrary filled grid of 9 spaces isn’t valid e.g. a grid filled with 3 X and 6 O isn’t valid situation because each player needs to take alternate turns.

Note :  The game starts with X

Example 1:

Input:
board[] = {'X', 'X', 'O', 
           'O', 'O', 'X',
           'X', 'O', 'X'};
Output: Valid
Explanation: This is a valid board.

Example 2:

Input:
board[] = {'O', 'X', 'X', 
           'O', 'X', 'X',
           'O', 'O', 'X'};
Output: Invalid
Explanation: Both X and O cannot win.
*/
class Solution{   
public:
    bool iswin(char *board, char symbol){
        int win[8][3]={{0,1,2},{3,4,5},{6,7,8},{0,3,6},{1,4,7},{2,5,8},{0,4,8},{2,4,6}};
        for(int i=0;i<8;i++){
            if(board[win[i][0]]==symbol && 
               board[win[i][1]]==symbol && 
               board[win[i][2]]==symbol)
               return true;
        }
        return false;
    }
    bool isValid(char board[9]){
        int countx=0,counto=0;
        for(int i=0;i<9;i++){
            if(board[i]=='X') countx++;
            if(board[i]=='O') counto++;
        }
        if(countx==counto || countx==counto+1){
            if(iswin(board,'O')){
                if(iswin(board,'X')) return false;
                if(countx==counto) return true;
            }
            if(iswin(board,'X') && countx!=counto+1) return false;
            
            return true;
        }
        return false;
    }
};