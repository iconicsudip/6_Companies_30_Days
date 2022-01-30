#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void dfs(vector<vector<int>>&grid,int row,int col,int dist){
        if(row<0 || col<0 || row>=grid.size() || col>=grid[0].size()||(grid[row][col]!=0&& grid[row][col]<=dist)){
            return;
        }
        grid[row][col]=dist;
        dfs(grid,row,col+1,dist+1),dfs(grid,row+1,col,dist+1),dfs(grid,row-1,col,dist+1),dfs(grid,row,col-1,dist+1);
    }
    int maxDistance(vector<vector<int>>& grid) {
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    grid[i][j]=0;
                    dfs(grid,i,j,1);
                }
            }
        }
        int ans=-1;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]>1)ans = max(ans,grid[i][j]-1);
            }
        }
        return ans;
    }
};