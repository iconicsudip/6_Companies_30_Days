#include<bits/stdc++.h>
using namespace std;
 // } Driver Code Ends
class Solution
{
	public:
    //Function to find if the given edge is a bridge in graph.
    int isBridge(int V, vector<int> adj[], int c, int d) 
    {
        // Code here
        vector<bool> visited(V,false);
        queue<int>q;
        q.push(c);
        visited[c]=true;
        adj[c].erase(find(adj[c].begin(),adj[c].end(),d));
        adj[d].erase(find(adj[d].begin(),adj[d].end(),c));
        while(!q.empty()){
            int val = q.front();
            q.pop();
            for(int i=0;i<adj[val].size();i++){
                //cout<<adj[val][i]<<" ";
                if(visited[adj[val][i]]==false){
                    q.push(adj[val][i]);
                    visited[adj[val][i]]=true;
                }
            }
        }
        if(visited[d]==false){
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
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        int i=0;
        while (i++<E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back (v);
            adj[v].push_back (u);
        }
        
        int c,d;
        cin>>c>>d;
        
        Solution obj;
    	cout << obj.isBridge(V, adj, c, d) << "\n";
    }

    return 0;
}

  // } Driver Code Ends