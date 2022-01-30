#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    static void dfs(vector<bool>&visited,vector<bool>&dfsvisited,vector<int>adj[],int i,vector<int> &ans,bool &cycle){
        visited[i]=true;
        dfsvisited[i]=true;
        for(auto j:adj[i]){
            if(visited[j]==false){
                dfs(visited,dfsvisited,adj,j,ans,cycle);
            }else if(dfsvisited[j]==true){
                cycle=true;
                return;
            }
        }
        dfsvisited[i]=false;
        ans.push_back(i);
    }
    vector<int> findOrder(int num, vector<vector<int>>& p) {
        vector<int>adj[num];
        for(int i=0;i<p.size();i++){
            int u=p[i][1];
            int v=p[i][0];
            adj[u].push_back(v);
        }
        vector<int>ans;
        vector<bool>visited(num,false);
	    vector<bool>dfsvisited(num,false);
        bool cycle=false;
        for(int i=0;i<num;i++){
            if(visited[i]==false){
                dfs(visited,dfsvisited,adj,i,ans,cycle);
            }
        }
        reverse(ans.begin(),ans.end());
        return cycle?vector<int>():ans;
    }
};