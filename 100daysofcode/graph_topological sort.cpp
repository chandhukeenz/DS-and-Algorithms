/*
Topological sort 
Given a Directed Graph with V vertices and E edges, Find any Topological Sorting of that Graph.
Your Task:
You don't need to read input or print anything. Your task is to complete the function topoSort()  which takes the integer V denoting the number of vertices and adjacency list as input parameters and returns an array consisting of a the vertices in Topological order.
 As there are multiple Topological orders possible, you may return any of them.
Expected Time Complexity: O(V + E).
Expected Auxiliary Space: O(V).
*/

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