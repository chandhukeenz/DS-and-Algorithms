//generate string based on the number given by following the number to alphabet order
//for example:
//input:12321
/*output:
LCU
AWU
AWBA
ABCU
ABCBA
*/
#include<iostream>
using namespace std;

void gen_string(char *in, char *out,int i,int j){
    if(in[i]=='\0'){
        out[j]='\0';
        cout<<out<<endl;
        return;
    }
    int d1 =in[i]-'0';
    if(in[i+1]!='\0'){
        int d2 =in[i+1]-'0';
        int sum= 10*d1 +d2;
        if(sum<=26){
            out[j]=sum+'A'-1;
            gen_string(in,out,i+2,j+1);
        }
    }
    out[j]=d1+'A'-1;
    gen_string(in,out,i+1,j+1);
}
int main(){
    char in[100];
    cin>>in;
    char out[100];
    gen_string(in,out,0,0);
    return 0;
}