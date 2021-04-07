/*
Alice has a binary string. She thinks a binary string is beautiful if and only if it doesn't contain the substring .
In one step, Alice can change a  to a  or vice versa. Count and print the minimum number of steps needed to make Alice see the string as beautiful.
Function Description
Complete the beautifulBinaryString function in the editor below.
beautifulBinaryString has the following parameter(s):
string b: a string of binary digits
Returns
int: the minimum moves required
Input Format
The first line contains an integer , the length of binary string.
The second line contains a single binary string .

Print the minimum number of steps needed to make the string beautiful.
*/
#include <bits/stdc++.h>

using namespace std;

// Complete the beautifulBinaryString function below.
int beautifulBinaryString(string b) {
   int count=0;
   if(b.size()<3) return 0;
   for(int i=2;b[i];i++){
       if(b[i]=='0'&&b[i-1]=='1'&&b[i-2]=='0'){
           count=count+1;
           b[i]='1';
       }
   }
   return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string b;
    getline(cin, b);

    int result = beautifulBinaryString(b);

    fout << result << "\n";

    fout.close();

    return 0;
}
