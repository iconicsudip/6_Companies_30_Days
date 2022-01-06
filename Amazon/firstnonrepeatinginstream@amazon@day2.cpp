#include<bits/stdc++.h>
using namespace std;

 //https://practice.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1#
class Solution {
	public:
		string FirstNonRepeating(string A){
		    vector<char>v;
		    unordered_map<char,int>mp;
		    string ans="";
		    for(int i=0;i<A.size();i++){
		        mp[A[i]]++;
		        if(mp[A[i]]==1){
		            v.push_back(A[i]);
		        }
		        int f=0;
		        for(int j=0;j<v.size();j++){
		            if(mp[v[j]]==1){
		                ans =ans+v[j];
		                f=1;
		                break;
		            }
		        }
		        if(f==0){
		            ans=ans+"#";
		        }
		    }
		    return ans;
		}
    //2nd solution
    // public:
    // string FirstNonRepeating(string A){
    //     queue<char>v;
    //     unordered_map<char,int>mp;
    //     string ans="";
    //     for(int i=0;i<A.size();i++){
    //         mp[A[i]]++;
    //         if(mp[A[i]]==1){
    //             v.push(A[i]);
    //         }
    //         while(!v.empty() && mp[v.front()]!=1){
    //             v.pop();
    //         }
    //         if(!v.empty()){
    //             ans=ans+v.front();
    //         }else{
    //             ans=ans+"#";
    //         }
    //     }
    //     return ans;
	// }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends