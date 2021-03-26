/*
Detect cycle in an undirected graph 
Medium Accuracy: 35.66% Submissions: 67270 Points: 4
Given an undirected graph with V vertices and E edges, check whether it contains any cycle or not. 
Your Task:
You don't need to read or print anything. Your task is to complete the function isCycle() which takes V denoting the number of vertices and adjacency list as input parameters and returns a boolean value denoting if the undirected graph contains any cycle or not.
Expected Time Complexity: O(V + E)
Expected Space Complexity: O(V)
Constraints:
1 ≤ V, E ≤ 105
*/
// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    bool isCyclicUtil(int v,vector<bool>visited,int parent,vector<int>adj[]){
        visited[v]=true;
        vector<int>::iterator i;
        for(i=adj[v].begin();i!=adj[v].end();i++){
            if(!visited[*i]){
                if(isCyclicUtil(*i,visited,v,adj))
                    return true;
            }else if(*i != parent)
                 return true;
        }
        return false;
    }
	bool isCycle(int V, vector<int>adj[]){
	    vector<bool>visited(V,false);
	    for(int node=0;node<V;node++){
	        if(isCyclicUtil(node,visited,-1,adj))
	            return true;
	    }
	    return false;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isCycle(V, adj);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}  // } Driver Code Ends