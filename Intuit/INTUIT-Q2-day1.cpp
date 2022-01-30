#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    static bool checkword(vector<vector<char>>& board,int row,int col,string word,int wordpos){
        if(wordpos==word.size()){
            return true;
        }
        if( (row<0 || row>=board.size()) || (col<0||col>=board[0].size())){
            return false;
        }
        if(board[row][col]!=word[wordpos]){
            return false;
        }
        board[row][col] = '1';
        bool right = checkword(board,row,col+1,word,wordpos+1);//f
        bool left = checkword(board,row,col-1,word,wordpos+1);//f
        bool top = checkword(board,row-1,col,word,wordpos+1);//f
        bool down = checkword(board,row+1,col,word,wordpos+1);//t
        board[row][col] = word[wordpos];
        return right || left || top || down;
        
    }
    bool isWordExist(vector<vector<char>>& board, string word) {
        // Code here
        int pos=0;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]==word[0]){
                    if(checkword(board,i,j,word,pos)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}  // } Driver Code Ends