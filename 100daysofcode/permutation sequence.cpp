/*Permutation Sequence
The set [1, 2, 3, ..., n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order, we get the following sequence for n = 3:

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

 

Example 1:

Input: n = 3, k = 3
Output: "213"
Example 2:

Input: n = 4, k = 9
Output: "2314"
Example 3:

Input: n = 3, k = 1
Output: "123"
*/
class Solution {
public:
    void setPerm(vector<int>& v,string& ans,int n,int k,vector<int>& factVal){
	   if(n==1){
            ans+=to_string(v.back());
            return;
        }
		int index = (k/factVal[n-1]);
		if(k % factVal[n-1] == 0) index--;
		ans+= to_string(v[index]);  
        v.erase(v.begin() + index);  
        k -= factVal[n-1] * index;   
        setPerm(v,ans,n-1,k,factVal);
    }
    string getPermutation(int n,int k){
        if(n==1) return "1";
        vector<int>factVal = {1,1,2,6,24,120,720,5040,40320,362880};
        string ans = "";
        vector<int> v;
        for(int i=1;i<=n;i++) v.push_back(i);
        setPerm(v,ans,n,k,factVal);
        return ans;
    }
};