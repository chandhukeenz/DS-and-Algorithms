 /*Group Anagrams
 Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

Example 1:

Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
Example 2:

Input: strs = [""]
Output: [[""]]
Example 3:

Input: strs = ["a"]
Output: [["a"]]
*/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> output;
        if(strs.size() == 0) return output;
        map<string,vector<string>> dict;
        for(string s: strs){
            string sorted = s;
            sort(sorted.begin(),sorted.end());
            dict[sorted].push_back(s);
        }
        map<string,vector<string>>::iterator i = dict.begin();
        while(i != dict.end()){
            output.push_back(i ->second);
            i++;
        }
        return output;
    }
};