/*
Daily Temperatures
Given a list of daily temperatures T, return a list such that, for each day in the input, 
tells you how many days you would have to wait until a warmer temperature. If there is no future day for which this is possible, 
put 0 instead.
For example, given the list of temperatures T = [73, 74, 75, 71, 69, 72, 76, 73], your output should be [1, 1, 4, 2, 1, 1, 0, 0].
*/
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        if (T.empty()){
            return vector<int>();
        }
        stack<pair<int,int>> s;
        s.push(make_pair(T.back(), 0));
        int len=T.size();
        vector<int> ans(len, 0);
        for (int i = len-2; i >= 0; i--){
            int count = 1;
            while (!s.empty() && T[i] >= s.top().first){
                count += s.top().second;
                s.pop();
            }
            if (s.empty()){
                s.push(make_pair(T[i], 0));
            }
            else{
                s.push(make_pair(T[i], count));
                ans[i] = count;
            }
        }
        return ans;
    }
};