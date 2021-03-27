/*
Detect cycle in a directed graph 
Given a Directed Graph with V vertices and E edges, check whether it contains any cycle or not.
Your task:
You don’t need to read input or print anything. Your task is to complete the function isCyclic() which takes the integer
 V denoting the number of vertices and adjacency list as input parameters and returns a boolean value denoting if the given directed graph contains a cycle or not.
Expected Time Complexity: O(V + E)
Expected Auxiliary Space: O(V)
*/

//using colors O(V+E) TC 
// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    enum Color {WHITE, GRAY, BLACK};
	bool isCyclicUtil(int u,int *color,vector<int>adj[]){
        color[u]=GRAY;
        vector<int>::iterator i;
        int v;
        for(i=adj[u].begin();i!=adj[u].end();i++){
            v=*i;
            if(color[v]==GRAY) return true;
            if(color[v]==WHITE && isCyclicUtil(v,color,adj)) return true;
        }
        color[u]=BLACK;
        return false;
    }
	bool isCyclic(int V, vector<int>adj[]){
	    int *color=new int[V];
	    for(int i=0;i<V;i++) color[i]=WHITE;
	    for(int i=0;i<V;i++){
	        if(color[i]==WHITE && isCyclicUtil(i,color,adj))
	              return true;
	    }
	    return false;
	}
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends
  //.........................................................
//backtracking
class Solution {
public:
	bool isCyclicUtil(vector<int>adj[],vector<bool>visited,int current){
        if(visited[current]==true)
           return true;
          visited[current]=true;
          bool FLAG = false;
          for(int i=0;i<adj[current].size();i++){
              FLAG = isCyclicUtil(adj,visited,adj[current][i]);
              if(FLAG== true)
                 return true;
          }
          return false;
    }
	bool isCyclic(int V, vector<int>adj[]){
	    vector<bool>visited(V,false);
	    bool FLAG =false;
	    for(int i=0;i<V;i++){
	        visited[i]=true;
	        for(int j=0;j<adj[i].size();j++){
	            FLAG = isCyclicUtil(adj,visited,adj[i][j]);
	            if(FLAG==true)
	               return true;
	        }
	        visited[i]=false;
	    }
	    return false;
	}
};
