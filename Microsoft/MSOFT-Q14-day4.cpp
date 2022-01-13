// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int minSteps(int D){
        // code here
        int sum=0;
        int steps=1;
        //5
        //0 + 1 + 3 + 0 + 5 =5
        //1 + 2 + 3 =6
        while(sum<D){
            sum+=steps;
            steps++;
        }
        while((sum-D)%2==1){
            sum+=steps;
            steps++;
        }
        return steps-1;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int D;
        cin>>D;
        
        Solution ob;
        cout<<ob.minSteps(D)<<"\n";
    }
    return 0;
}  // } Driver Code Ends