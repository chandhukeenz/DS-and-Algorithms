/*
Print all possible words from phone digits
Before the advent of QWERTY keyboards, texts and numbers were placed on the same key.
 For example, 2 has “ABC” if we wanted to write anything starting with ‘A’ we need to type key 2 once. 
 If we wanted to type ‘B’, press key 2 twice and thrice for typing ‘C’. Below is a picture of such a keypad.
 Example: 
Input number: 234
Output:
adg adh adi aeg aeh aei afg afh 
afi bdg bdh bdi beg beh bei bfg 
bfh bfi cdg cdh cdi ceg ceh cei 
cfg cfh cfi
*/
#include<iostream>
using namespace std;
char keypad[][10] ={"","","ABC","DEF","GHI","JKL","MNO","PQRS","TUV","WXYZ"};

void gen_names(char *in,char *out,int i,int j){
    if(in[i]=='\0'){
        out[j]='\0';
        cout<<out<<endl;
        return;
    }
    int digit =in[i]-'0';
    if(digit==1 || digit ==0){
        gen_names(in,out,i+1,j);
    }
    for(int k=0;keypad[digit][k]!='\0';k++){
        out[j] =keypad[digit][k];
        gen_names(in,out,i+1,j+1);
    }
    return;
}

int main(){
    char in[100];
    cin>>in;
    char out[100];
    gen_names(in,out,0,0);
    return 0;
}