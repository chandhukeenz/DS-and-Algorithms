/*
Topological sort 
Given a Directed Graph with V vertices and E edges, Find any Topological Sorting of that Graph.
Your Task:
You don't need to read input or print anything. Your task is to complete the function topoSort()  which takes the integer V denoting the number of vertices and adjacency list as input parameters and returns an array consisting of a the vertices in Topological order.
 As there are multiple Topological orders possible, you may return any of them.
Expected Time Complexity: O(V + E).
Expected Auxiliary Space: O(V).
*/

//kahn's algorithm 
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	vector<int> topoSort(int V, vector<int> adj[]) {
	     vector<int> inDegree(V, 0);
	     queue<int> q;
	     vector<int> topsort;
	     int count = 0;
	     for(int u = 0;u < V; u++) {
	         vector<int>::iterator i;
	         for (i = adj[u].begin();i != adj[u].end(); i++)
	         inDegree[*i]++;
	     }
	     for(int i = 0; i < V; i++)
	         if(inDegree[i] == 0) q.push(i);
	     while (!q.empty()){
	         int u = q.front();
	         q.pop();
	         topsort.push_back(u);
	         vector<int>::iterator i;
	         for (i = adj[u].begin();i!= adj[u].end(); i++)
	         if (--inDegree[*i] == 0) q.push(*i);
	         count++;
	     }
	     return topsort;
	}
};

// { Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}  // } Driver Code Ends
//dfs method input: acyclic graphs only
class Solution{
	public:
	void topoSortUtil(int v,vector<bool> visited,vector<int>&output,vector<int>adj[]){
	    visited[v]=true;
	    vector<int>::iterator i;
	    for(i=adj[v].begin();i!=adj[v].end();i++){
	        if(!visited[*i])
	            topoSortUtil(*i,visited,output,adj);
	    }
	    output.push_back(v);
	}
	vector<int> topoSort(int V, vector<int> adj[]) {
	    vector<int>output;
	    vector<bool>visited(V,false);
	    for(int i=0;i<V;i++){
	        if(visited[i]==false)
	           topoSortUtil(i,visited,output,adj);
	    }
	    reverse(output.begin(),output.end());
	    return output;
	}
};