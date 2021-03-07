/*
Given a string S. The task is to count the number of substrings which contains equal number of lowercase and uppercase letters. 
Example 1:
Input:
S = "gEEk"
Output: 3
Explanation: There are 3 substrings of
the given string which satisfy the
condition. They are "gE", "gEEk" and "Ek".
Your Task:
The task is to complete the function countSubstring() which takes the string S as input parameter and returns the number of substrings which contains equal number of uppercase and lowercase letters.

Constraints:
1 ≤ |S| ≤ 103
*/
class Solution
{
    public:
    int countSubstring(string S)
    {
        int ans=0;
        for(int i=0;i<S.size();i++)
        {
            int c=0;
            for(int j=i;j<S.size();j++)
            {
                if(S[j]>='a'&&S[j]<='z')
                    c++;
                else
                    c--;
                if(c==0)
                    ans++;
            }
        }
        return ans;
    }
};