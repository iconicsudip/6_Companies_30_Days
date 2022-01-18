//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n) ;


 // } Driver Code Ends
//User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution
{
    public:
    static void generate(string s,int open,int close,vector<string>&ans,int n){
        if(s.length()==2*n){
            ans.push_back(s);
            return;
        }
        if(open<n){
            generate(s+"(",open+1,close,ans,n);
        }
        if(open>close){
            generate(s+")",open,close+1,ans,n);
        }
    }
    vector<string> AllParenthesis(int n) 
    {
        // Your code goes here
        vector<string>ans;
        generate("(",1,0,ans,n);
        return ans;
    }
};

// { Driver Code Starts.


int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		Solution ob;
		vector<string> result = ob.AllParenthesis(n); 
		sort(result.begin(),result.end());
		for (int i = 0; i < result.size(); ++i)
			cout<<result[i]<<"\n";
	}
	return 0; 
} 
  // } Driver Code Ends