#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    static bool dfs(vector<bool>&visited,vector<bool>&dfsvisited,vector<int>adj[],int i){
        visited[i]=true;
        dfsvisited[i]=true;
        for(auto j:adj[i]){
            if(visited[j]==false){
                if(dfs(visited,dfsvisited,adj,j)){
                    return true;
                }
            }else if(dfsvisited[j]==true){
                return true;
            }
        }
        dfsvisited[i]=false;
        return false;
    }
	bool isPossible(int N, vector<pair<int, int> >& pre) {
        vector<int>adj[N];
        for(int i=0;i<pre.size();i++){
	        //[1,0]
	        //0-->1
            int u=pre[i].second;
            int v=pre[i].first;
            adj[u].push_back(v);
        }
        vector<bool>visited(N,false);
        vector<bool>dfsvisited(N,false);
        for(int i =0;i<N;i++){
            if(visited[i]==false){
                if(dfs(visited,dfsvisited,adj,i)){
                    return false;
                }
            }
        }
        return true;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
        int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}  // } Driver Code Ends