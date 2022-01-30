#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to find the largest number after k swaps.
    long int maxi;
    string swap(string &str,int i,int j){
        char temp = str[i];
        str[i]=str[j];
        str[j]=temp;
        return str;
    }
    void solve(string str,int k){
        maxi = max(stol(str),maxi);
        if(k==0){
            return;
        }
        for(int i=0;i<str.length()-1;i++){
            for(int j = i+1;j<str.length();j++){
                if(str[i]<str[j]){
                    str = swap(str,i,j);
                    solve(str,k-1);
                    str = swap(str,i,j);
                }
            }
        }
    }
    string findMaximumNum(string str, int k)
    {
       // code here.
       maxi=stol(str);
       solve(str,k);
       return to_string(maxi);
    }
};

// { Driver Code Starts.

int main()
{
    int t, k;
    string str;

    cin >> t;
    while (t--)
    {
        cin >> k >> str;
        Solution ob;
        cout<< ob.findMaximumNum(str, k) << endl;
    }
    return 0;
}
  // } Driver Code Ends