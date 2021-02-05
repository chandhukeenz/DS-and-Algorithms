/*Next Greater Element II
Given a circular array (the next element of the last element is the first element of the array), print the Next Greater Number for every element. The Next Greater Number of a number x is the first greater number to its traversing-order next in the array, which means you could search circularly to find its next greater number. If it doesn't exist, output -1 for this number.

Example 1:
Input: [1,2,1]
Output: [2,-1,2]
Explanation: The first 1's next greater number is 2; 
The number 2 can't find next greater number; 
The second 1's next greater number needs to search circularly, which is also 2.
*/
class Solution {
public:
     vector<int> nextGreaterElements(vector<int>& A) {
        int n = A.size();
        vector<int> st,ans(n, -1);
        for (int i=0;i<2*n;i++) {
            while (st.size() && (A[st.back()]< A[i%n])) {
                ans[st.back()] = A[i%n];
                st.pop_back();
            }
            st.push_back(i % n);
        }
        return ans;
    }
};