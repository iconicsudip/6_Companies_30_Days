#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    static void bfs(vector<vector<bool>>&visit,queue<pair<int,int>>&q,vector<vector<int>>& heights){
        int dx[] = {0,0,-1,1};
        int dy[] = {1,-1,0,0};
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            visit[x][y]=true;
            q.pop();
            for(int i=0;i<4;i++){
                int X = x + dx[i];
                int Y = y + dy[i];
                if(X<0 || Y<0 || X>=heights.size() || Y>=heights[0].size() || visit[X][Y]==true){
                    continue;
                }
                if(heights[X][Y]>=heights[x][y]){
                    q.push({X,Y});
                    visit[X][Y]=true;
                }
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        queue<pair<int,int>>pacific;
        queue<pair<int,int>>atlantic;
        vector<vector<bool>>visited1(heights.size(),vector<bool>(heights[0].size(),false));
        vector<vector<bool>>visited2(heights.size(),vector<bool>(heights[0].size(),false));
        for(int i=0;i<heights.size();i++){
            for(int j=0;j<heights[0].size();j++){
                if(j==0 || i==0){
                    pacific.push({i,j});
                    visited1[i][j]=true;
                }
                if(i==heights.size()-1 || j==heights[0].size()-1){
                    atlantic.push({i,j});
                    visited2[i][j]=true;
                }
            }
        }
        bfs(visited1,pacific,heights);
        bfs(visited2,atlantic,heights);
        vector<vector<int>>ans;
        for(int i=0;i<heights.size();i++){
            for(int j=0;j<heights[0].size();j++){
                if(visited1[i][j] && visited2[i][j]){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};