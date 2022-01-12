#include <bits/stdc++.h>
using namespace std;


class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int k) {
        // Your code goes here
        sort(arr.begin(),arr.end());
        set<vector<int>>s;
        //0 0 1 1 2
        for(int i=0;i<arr.size()-3;i++){
            for(int j=i+1;j<arr.size()-2;j++){
                int start = j+1;
                int end=arr.size()-1;
                while(start<end){
                    int sum = arr[i]+arr[j]+arr[start]+arr[end];
                    if(sum==k){
                        s.insert({arr[i],arr[j],arr[start],arr[end]});
                        start++;
                        end--;
                    }else if(sum>k){
                        end--;
                    }else{
                        start++;
                    }
                }
            }
        }
        vector<vector<int>>ans;
        for(auto c:s){
            ans.push_back(c);
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}