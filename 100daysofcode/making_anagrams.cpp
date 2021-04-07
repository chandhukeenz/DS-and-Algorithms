/*
We consider two strings to be anagrams of each other if the first string's letters can be rearranged to form the second string. In other words, both strings must contain the same exact letters in the same exact frequency. For example, bacdc and dcbac are anagrams, but bacdc and dcbad are not.

Alice is taking a cryptography class and finding anagrams to be very useful. She decides on an encryption scheme involving two large strings where encryption is dependent on the minimum number of character deletions required to make the two strings anagrams. Can you help her find this number?

Given two strings,  and , that may not be of the same length, determine the minimum number of character deletions required to make  and  anagrams. Any characters can be deleted from either of the strings.

Function Description

Complete the makingAnagrams function in the editor below.

makingAnagrams has the following parameter(s):

string s1: a string
string s2: a string
Returns

int: the minimum number of deletions needed
Input Format

The first line contains a single string, .
The second line contains a single string, .

Constraints

It is guaranteed that  and  consist of lowercase English letters, ascii[a-z].
Sample Input

cde
abc
Sample Output
4


Delete the following characters from our two strings to turn them into anagrams:

Remove d and e from cde to get c.
Remove a and b from abc to get c.
 characters have to be deleted to make both strings anagrams.
*/
#include <bits/stdc++.h>

using namespace std;

// Complete the makingAnagrams function below.
int makingAnagrams(string s1, string s2) {
    int count=0;
    unordered_map<char,int>m;
    for (auto ch:s1)
        m[ch] ? m[ch]+=1 : m[ch]=1;
    for(auto ch:s2){
        if(!m[ch]) count++;
        else m[ch]--;
    }
    for(auto c:s1){
        if(m[c]){
            count+=m[c];
            m[c]=0;
        }
    }
    return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s1;
    getline(cin, s1);

    string s2;
    getline(cin, s2);

    int result = makingAnagrams(s1, s2);

    fout << result << "\n";

    fout.close();

    return 0;
}
