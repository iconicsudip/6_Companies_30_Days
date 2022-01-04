#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution {
	public:
	int mod = 1e9+7;
	int CountWays(string str){
	    // Code here
	   // if(str[0]=='0')return 0;
	    for(int i=1;i<str.length();i++){
	        if(str[i]=='0' &&str[i-1]=='0')return 0;
	    }
	    int n= str.length();
	    int dp[n+1];
	   // memset(dp,0,sizeof(dp));
	    dp[0]=1;
	    dp[1]=1;
	    if(n==1 && str[0]!='0')
        return 1;
        if(str[0]=='0')
        return 0;
	    for(int i=2;i<n+1;i++){
	        dp[i]=0;
	       // cout<<dp[i-1]<<" "<<dp[i-2]<<" "<<i<<" "<<str[i-2]<<endl;
	        if(str[i-1]>'0')dp[i] =dp[i-1];
	        if(str[i-2]=='1' || (str[i-2]=='2'&&str[i-1]<'7'))dp[i] =(dp[i-2]+dp[i])%mod;
	    }
	    return dp[n]%mod;
	}

};
// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.CountWays(str);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends