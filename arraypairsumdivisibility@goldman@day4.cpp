#include <bits/stdc++.h>
using namespace std;

 //https://practice.geeksforgeeks.org/problems/array-pair-sum-divisibility-problem3257/1
class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        // Code here.
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]%k]++;
        }
        if(mp[0]%2==1){
            return false;
        }
        int i=1,j=k-1;
        while(i<j){
            if(mp[i]!=mp[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}  // } Driver Code Ends