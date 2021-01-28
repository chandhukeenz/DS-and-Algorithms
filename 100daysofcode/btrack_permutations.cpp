#include<iostream>
using namespace std;

void permute(char *in,int i){
    if(in[i]=='\0'){
        cout<<in<<" ,";
        return;
    }
    for(int j=i;in[j]!='\0';j++){
        swap(in[i],in[j]);
        permute(in,i+1);
    }
}
int main(){
    char in[100];
    cin>>in;
    permute(in,0);
    return 0;
}