/*
 Top K Frequent Elements
Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.
Example 1:
Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
Example 2:
Input: nums = [1], k = 1
Output: [1]
*/
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        for(int num : nums){
            m[num]++;
        }
        vector<int> res;
        priority_queue<pair<int,int>> pq; 
        for(auto it = m.begin(); it != m.end(); it++){
            pq.push(make_pair(it->second, it->first));
            if(pq.size() > (int)m.size()- k){
                res.push_back(pq.top().second);
                pq.pop();
            }
        }
        return res;
    }
};