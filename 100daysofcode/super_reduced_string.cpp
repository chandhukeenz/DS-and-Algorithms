/*
Reduce a string of lowercase characters in range ascii[‘a’..’z’]by doing a series of operations. In each operation, select a pair of adjacent letters that match, and delete them.

Delete as many characters as possible using this method and return the resulting string. If the final string is empty, return Empty String

Function Description

Complete the superReducedString function in the editor below.

superReducedString has the following parameter(s):

string s: a string to reduce
Returns

string: the reduced string or Empty String
Input Format

A single string, .

Constraints

Sample Input 0

aaabccddd
Sample Output 0

abd
Explanation 0

Perform the following sequence of operations to get the final string:

aaabccddd → abccddd → abddd → abd
Sample Input 1

aa
Sample Output 1

Empty String
Explanation 1

aa → Empty String
Sample Input 2

baab
Sample Output 2

Empty String
Explanation 2

baab → bb → Empty String
*/
#include <bits/stdc++.h>
#include <string>
using namespace std;


string superReducedString(string s) {
    string a;
    for(int i=0; i<s.size(); i++)
    {
        if(i==s.size()-1)
            a.push_back(s[i]);
        else
        {
            if(s[i]!=s[i+1])
                a.push_back(s[i]);
            else
                i++;
        }
    }
    if(!a.size()) return "Empty String";
    if(a.size()==s.size()) return a;
    return superReducedString(a);
    
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = superReducedString(s);

    fout << result << "\n";

    fout.close();

    return 0;
}