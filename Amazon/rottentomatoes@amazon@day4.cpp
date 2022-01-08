#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if(grid.size()==0){
            return 0;
        }
        queue<pair<int,int>>q;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        int x[4]={0,0,1,-1};
        int y[4]={1,-1,0,0};
        int days=0;
        while(!q.empty()){
            int k=q.size();
            while(k--){
                int row = q.front().first,col=q.front().second;
                q.pop();
                for(int i=0;i<4;i++){
                    int nx=row+x[i];
                    int ny=col+y[i];
                    if(nx<0 || ny<0 || nx>=grid.size()||ny>=grid[0].size() || grid[nx][ny]!=1){
                        continue;
                    }else{
                        grid[nx][ny]=2;
                        q.push({nx,ny});
                    }
                }
            }
            if(!q.empty()){
                days++;
            }
        }
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        return days;
    }
};
int main(){
    return 0;
}