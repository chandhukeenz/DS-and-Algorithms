/*
A Maze is given as N*N binary matrix of blocks where source block is the upper left most block i.e.,
maze[0][0] and destination block is lower rightmost block i.e., maze[N-1][N-1]. A rat starts from source and has to reach the destination.
The rat can move only in two directions: forward and down. 
In the maze matrix, 0 means the block is a dead end and 1 means the block can be used in the path from source to destination.
Note that this is a simple version of the typical Maze problem. For example, a more complex version can be that the rat can move
in 4 directions and a more complex version can be with a limited number of moves.
input:
{1, 0, 0, 0}
{1, 1, 0, 1}
{0, 1, 0, 0}
{1, 1, 1, 1}
output:
{1, 0, 0, 0}
{1, 1, 0, 0}
{0, 1, 0, 0}
{0, 1, 1, 1}
All enteries in solution path are marked as 1.
*/
#include<iostream>
using namespace std;
bool ratinmaze(char maze[10][10],int soln[][10],int i,int j,int m,int n){
    if(i==m && j==n){
        soln[m][n]=1;
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                cout<<soln[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        return true;
    }
    if(i>m || j>n) return false;
    if(maze[i][j]=='X') return false;
    soln[i][j]=1;
    bool rightsuccess =ratinmaze(maze,soln,i,j+1,m,n);
    bool downsuccess =ratinmaze(maze,soln,i+1,j,m,n);
    //backtracking
    soln[i][j]=0;
    if(rightsuccess || downsuccess) return true;
    return false;
}
int main(){
    char maze[10][10]={"0000","00X0","000X","0X00"};
    int soln[10][10]={0};
    int m=4,n=4;
    bool ans=ratinmaze(maze,soln,0,0,m-1,n-1);
    if(!ans) cout<<"Path doesn't exist";
    return 0;
}