/*
You are given an N*N sudoku grid (N is a multiple of 3). Solve the sudoku and print the solution.
Sample Input
9
5 3 0 0 7 0 0 0 0 
6 0 0 1 9 5 0 0 0 
0 9 8 0 0 0 0 6 0 
8 0 0 0 6 0 0 0 3 
4 0 0 8 0 3 0 0 1 
7 0 0 0 2 0 0 0 6 
0 6 0 0 0 0 2 8 0 
0 0 0 4 1 9 0 0 5 
0 0 0 0 8 0 0 7 9 
Sample Output
5 3 4 6 7 8 9 1 2 
6 7 2 1 9 5 3 4 8 
1 9 8 3 4 2 5 6 7 
8 5 9 7 6 1 4 2 3 
4 2 6 8 5 3 7 9 1 
7 1 3 9 2 4 8 5 6 
9 6 1 5 3 7 2 8 4 
2 8 7 4 1 9 6 3 5 
3 4 5 2 8 6 1 7 9 
*/
#include<iostream>
#include<cmath>
using namespace std;

bool canplace(int mat[][9],int i,int j,int n,int number){
    for(int x=0;x<n;x++){
        if(mat[x][j]==number || mat[i][x]==number) return false;
    }
    int rn=sqrt(n);
    int sx=(i/rn)*rn;
    int sy=(j/rn)*rn;
    for(int x=sx;x<sx+rn;x++){
        for(int y=sy;y<sy+rn;y++){
            if(mat[x][y]==number){
                return false;
            }
        }
    }
    return true;
}

bool  solvesudoku(int mat[][9],int i,int j,int n){
    if(i==n){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<mat[i][j]<<" ";
            }
            cout<<endl;
        }
        return true;
    }
    if(j==n) return solvesudoku(mat,i+1,0,n);
    
    if(mat[i][j]!=0) return solvesudoku(mat,i,j+1,n);
    
    for(int number=1;number<=n;number++){
        if(canplace(mat,i,j,n,number)){
            mat[i][j]=number;
            if(solvesudoku(mat,i,j+1,n)) return true;
        }
    }
    mat[i][j]=0;
    return false;
}

int main(){
    int mat[9][9]={
        {5,3,0,0,7,0,0,0,0},
        {6,0,0,1,9,5,0,0,0},
        {0,9,8,0,0,0,0,6,0},
        {8,0,0,0,6,0,0,0,3},
        {4,0,0,8,0,3,0,0,1},
        {7,0,0,0,2,0,0,0,6},
        {0,6,0,0,0,0,2,8,0},
        {0,0,0,4,1,9,0,0,5},
        {0,0,0,0,8,0,0,7,9}
    };
    solvesudoku(mat,0,0,9);
    return 0;
}