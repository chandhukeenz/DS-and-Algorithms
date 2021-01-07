/*Valid Anagram
Given two strings s and t , write a function to determine if t is an anagram of s.

Example 1:

Input: s = "anagram", t = "nagaram"
Output: true
Example 2:

Input: s = "rat", t = "car"
Output: false
*/
class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> m;
        int l1=s.size(),l2=t.size();
        if(l1!=l2) return false;
        for(auto i:s) m[i] ? m[i]+=1 : m[i]=1;
        for(auto i:t){
            if(!m[i]) return false;
            else m[i]-=1;
        }
        return true;
    }
};