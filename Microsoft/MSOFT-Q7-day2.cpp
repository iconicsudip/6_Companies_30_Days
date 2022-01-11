#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    private:
    int largestArea(vector<vector<bool>>&visited,vector<vector<int>>&grid,int row,int col){
        if(row<0 || col<0 || row>=grid.size() || col>=grid[0].size() || grid[row][col]==0 || visited[row][col]==true){
            return 0;
        }
        visited[row][col]=true;        
        return largestArea(visited,grid,row+1,col)+largestArea(visited,grid,row+1,col+1)+largestArea(visited,grid,row+1,col-1)+largestArea(visited,grid,row,col+1)+largestArea(visited,grid,row,col-1)+largestArea(visited,grid,row-1,col)+largestArea(visited,grid,row-1,col-1)+largestArea(visited,grid,row-1,col+1)+1;
    }
    public:
    //Function to find unit area of the largest region of 1s.
    int findMaxArea(vector<vector<int>>& grid) {
        // Code here
        int ans=0;
        vector<vector<bool>>visited(grid.size(),vector<bool>(grid[0].size(),false));
        for(int row=0;row<grid.size();row++){
            for(int column=0;column<grid[0].size();column++){
                if(grid[row][column]==1 && visited[row][column]==false){
                    int countArea = largestArea(visited,grid,row,column);
                    ans = max(ans,countArea);
                }
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.findMaxArea(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends