/*
Julius Caesar protected his confidential information by encrypting it using a cipher. Caesar's cipher shifts each letter by a number of letters. If the shift takes you past the end of the alphabet, just rotate back to the front of the alphabet. In the case of a rotation by 3, w, x, y and z would map to z, a, b and c.

Original alphabet:      abcdefghijklmnopqrstuvwxyz
Alphabet rotated +3:    defghijklmnopqrstuvwxyzabc
Function Description
Complete the caesarCipher function in the editor below.
caesarCipher has the following parameter(s):
string s: cleartext
int k: the alphabet rotation factor
Returns
string: the encrypted string
Input Format
The first line contains the integer, , the length of the unencrypted string.
The second line contains the unencrypted string, .
The third line contains , the number of letters to rotate the alphabet by.

Constraints
 is a valid ASCII string without any spaces.

Sample Input

11
middle-Outz
2
Sample Output

okffng-Qwvb
Explanation

Original alphabet:      abcdefghijklmnopqrstuvwxyz
Alphabet rotated +2:    cdefghijklmnopqrstuvwxyzab

m -> o
i -> k
d -> f
d -> f
l -> n
e -> g
-    -
O -> Q
u -> w
t -> v
z -> b
*/
#include <bits/stdc++.h>

using namespace std;

// Complete the caesarCipher function below.
string caesarCipher(string s, int k) {
    for (int i = 0; i < s.length(); i++){
        if (65 <= s[i] && s[i] <= 90)
            s[i] = char(65 +(((s[i] - 65) + k) % 26));
        else if (97 <= s[i] && s[i] <= 122)
            s[i] = char(97 +(((s[i] - 97) + k) % 26));
    }       
    return s;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string s;
    getline(cin, s);

    int k;
    cin >> k;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string result = caesarCipher(s, k);

    fout << result << "\n";

    fout.close();

    return 0;
}
