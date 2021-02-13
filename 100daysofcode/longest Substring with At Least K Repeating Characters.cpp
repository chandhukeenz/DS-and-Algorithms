/*
Longest Substring with At Least K Repeating Characters

Given a string s and an integer k, return the length of the longest substring of s such that the frequency of each character in 
this substring is greater than or equal to k.

Example 1:

Input: s = "aaabb", k = 3
Output: 3
Explanation: The longest substring is "aaa", as 'a' is repeated 3 times.
Example 2:

Input: s = "ababbc", k = 2
Output: 5
Explanation: The longest substring is "ababb", as 'a' is repeated 2 times and 'b' is repeated 3 times.
*/
class Solution {
public:
    int longestSubstring(string s, int k) {
        
        int n = s.length();
        unordered_map<char, int> count;
        
        for (char c : s) ++count[c];
        
        int mid = 0;
        
        while (mid < n && count[s[mid]] >= k) ++mid;
        
        if (mid == n) return n;
        int left = longestSubstring(s.substr(0, mid), k);
        
        while (mid < n && count[s[mid]] < k) ++mid;
        
        if(mid == s.length()) return left; 
        
        int right = longestSubstring(s.substr(mid), k);
        return max(left, right);
    }
};