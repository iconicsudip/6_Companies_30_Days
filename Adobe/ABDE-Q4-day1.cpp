// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
class Solution{
public:
    static bool solve(vector<vector<int>>&mem,int N,int arr[],int pos,int sum){
        if(sum==0){
            return true;
        }else if(pos>=N || pos<0){
            return false;
        }
        if(mem[pos][sum]!=-1){
            return mem[pos][sum];
        }
        bool inc=solve(mem,N,arr,pos+1,sum-arr[pos]);
        bool exl=solve(mem,N,arr,pos+1,sum);
        mem[pos][sum]=inc||exl;
        return mem[pos][sum];
    }
    int equalPartition(int N, int arr[])
    {
        // code here
        int sum=0;
        for(int i=0;i<N;i++){
            sum+=arr[i];
        }
        if(sum%2!=0){
            return false;
        }
        vector<vector<int>>mem(N+1,vector<int>(sum/2+1,-1));
        if(solve(mem,N,arr,0,sum/2)==true){
            return 1;
        }
        return 0;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}  // } Driver Code Ends