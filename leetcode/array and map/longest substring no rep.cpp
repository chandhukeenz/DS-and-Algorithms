//Given a string s, find the length of the longest substring without repeating characters.
//Input: s = "pwwkew"
//Output: 3
//Explanation: The answer is "wke", with the length of 3.
//Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int longest=0;
        unordered_map<char,int>seen;
        int start=0;
        for(int i=0;i<s.size();i++){
            if(seen[s[i]]){
                start=max(start,seen[s[i]]);
            }
            // index - beginning of substring + 1 (to include current in count)
            longest=max(longest,i-start+1);
            // store the index of the next char so as to not double count
            seen[s[i]]=i+1;
        }
        return longest;
    }
};
//  a        b     b        a       
//  start,i                      seen[a]=1  longest=1
//  start    i                   seen[b]=2   longest=2
//                 i,start             
//                          i     line 14 will tell start to remain where it is bcos seen[s[i]] ie seen[a] here points to s[1] which is less than the start current pos  
//  output longest = 2                            
