//generate subsets of the string
//example
//input:abc
//output:"abc", "ab", "ac", "a", "bc", "b", "c", ""
#include<iostream>
using namespace std;

void genSubset(char *in,char *out,int i,int j){
    if(in[i]=='\0'){
        out[j]='\0';
        cout<<"\""<<out<<"\", ";
        return;
    }
    out[j]=in[i];
    //include the curr char
    genSubset(in,out,i+1,j+1);
    //exclude the curr char
    genSubset(in,out,i+1,j);
}


int main(){
    char input[]="abc";
    char output[10];
    genSubset(input,output,0,0);
    return 0;
}
