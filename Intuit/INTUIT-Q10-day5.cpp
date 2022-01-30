#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<bool> visited(isConnected.size(),false);
        int ans=0;
        for(int k=0;k<isConnected.size();k++){
            if(visited[k]){
                continue;
            }
            queue<int>q;
            q.push(k);
            ans++;
            while(!q.empty()){
                int cur = q.front();
                q.pop();
                visited[cur]=true;
                for(int i=0;i<isConnected[cur].size();i++){
                    if(visited[i]==false && isConnected[cur][i]==1){
                        q.push(i);
                        visited[i]=true;
                    }
                }
            }
        }
        return ans;
    }
};