/*Write a function to generate all possible n pairs of balanced parentheses.
Examples:

Input: n=1
Output: ()
Explantaion: This the only sequence of balanced 
parenthesis formed using 1 pair of balanced parenthesis. 

Input : n=2
Output: 
()()
(())
Explantaion: This the only two sequences of balanced 
parenthesis formed using 2 pair of balanced parenthesis. 
*/
#include<iostream>
using namespace std;

void genBracket(char *out,int n,int idx,int open,int close){
    if(idx==2*n){
        out[idx] ='\0';
        cout<<out<<endl;
        return;
    }

    if(open<n){
        out[idx]='(';
        genBracket(out,n,idx+1,open+1,close);
    }
    if(close<open){
        out[idx]=')';
        genBracket(out,n,idx+1,open,close+1);
    }
    return;
}

int main(){
    int n;
    cin>>n;
    char out[1000];
    int idx=0;
    genBracket(out,n,0,0,0);
    return 0;
}