#include <iostream>
#include <map>
#include <algorithm>
#include <cstdlib>
#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
class Solution{
  public:
  
    //Function to return the name of candidate that received maximum votes.
    vector<string> winner(string arr[],int n)
    {
        unordered_map<string,int>mp;
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }
        int maxi=mp[arr[0]];
        string name=arr[0];
        for(int i=1;i<n;i++){
            if(mp[arr[i]]>maxi){
                maxi=mp[arr[i]];
                name=arr[i];
            }else if(mp[arr[i]]==maxi){
                if(name>arr[i]){
                    name=arr[i];
                }
            }
        }
        vector<string>ans;
        ans.push_back(name);
        ans.push_back(to_string(maxi));
        return ans;
        // Your code here
        // Return the string containing the name and an integer
        // representing the number of votes the winning candidate got
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    
    for(int i=0;i<t;i++)
    {
        
        
        int n;
        cin>>n;
        
        string arr[n];
        
        for (int i=0;i<n;i++)
        cin>>arr[i];
        Solution obj;
        vector<string> result = obj.winner(arr,n);
        
        cout<<result[0] << " " << result[1] << endl;
    }
    return 0;
}
  // } Driver Code Ends