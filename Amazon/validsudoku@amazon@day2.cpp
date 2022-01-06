// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    static bool checksudoku(int row,int col,vector<vector<int>>&mat){
        for(int i=0;i<9;i++){
            if(mat[row][col]==mat[row][i] && col!=i){
                return false;
            }
        }
        for(int i=0;i<9;i++){
            if(mat[row][col]==mat[i][col] && row!=i){
                return false;
            }
        }
        int startrow = 3*(row/3);
        int startcol = 3*(col/3);
        for(int i=startrow;i<startrow+3;i++){
            for(int j=startcol;j<startcol+3;j++){
                if(mat[i][j]==mat[row][col] && i!=row && j!=col){
                    return false;
                }
            }
        }
        return true;
    }
    int isValid(vector<vector<int>> mat){
        // code here
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(mat[i][j]!=0){
                    if(checksudoku(i,j,mat)==false){
                        return false;
                    }
                }
            }
        }
        return true;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        vector<vector<int>> mat(9, vector<int>(9, 0));
        for(int i = 0;i < 81;i++)
            cin>>mat[i/9][i%9];
        
        Solution ob;
        cout<<ob.isValid(mat)<<"\n";
    }
    return 0;
}  // } Driver Code Ends