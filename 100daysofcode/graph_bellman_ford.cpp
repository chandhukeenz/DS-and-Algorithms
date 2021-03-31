/*
Negative weight cycle 
Given a weighted directed graph with n nodes and m edges. Nodes are labeled from 0 to n-1, the task is to check if it contains a negative weight cycle or not.
Note: edges[i] is defined as u, v and weight.
Example 1:
Input: n = 3, edges = {{0,1,-1},{1,2,-2},
{2,0,-3}}
Output: 1
Explanation: The graph contains negative weight
cycle as 0->1->2->0 with weight -1,-2,-3,-1.
Example 2:
Input: n = 3, edges = {{0,1,-1},{1,2,-2},
{2,0,3}}
Output: 0
Explanation: The graph does not contain any
negative weight cycle.
Your Task:
You don't need to read or print anyhting. Your task is to complete the function isNegativeWeightCycle() which takes n and edges as input paramater
and returns 1 if graph contains negative weight cycle otherwise returns 0.
Expected Time Complexity: O(n*m)
Expected Space Compelxity: O(n)
*/

//bellman ford for negative weight (np in dijkstra).
//not applicable for graphs having negative weight cycles.
// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    int e=edges.size();
	    int dist[n];
	    int start,end,wt;
	    dist[0]=0;
	    for(int i=1;i<n;i++){
	        dist[i]=INT_MAX;
	    }
	    for(int i=0;i<=n-1;i++){
	        for(int j=0;j<e;j++){
	            start=edges[j][0];
	            end=edges[j][1];
	            wt=edges[j][2];
	            if(dist[start]!=INT_MAX && dist[start]+wt<dist[end]){
	               if(i==n-1) return 1;
	               dist[end]=dist[start]+wt;
	            }
	        }
	    }
	    return 0;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int x, y, z;
			cin >> x >> y >> z;
			edges.push_back({x,y,z});
		}
		Solution obj;
		int ans = obj.isNegativeWeightCycle(n, edges);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends