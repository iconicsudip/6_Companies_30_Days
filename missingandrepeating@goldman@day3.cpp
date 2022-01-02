#include <bits/stdc++.h>

using namespace std;

 // https://practice.geeksforgeeks.org/problems/find-missing-and-repeating2512/1/.
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        // code here
        int ans[2]={0};
        for(int i=0;i<n;i++){
            if(arr[abs(arr[i])-1]>0){
                arr[abs(arr[i])-1]= -arr[abs(arr[i])-1];
            }else{
                ans[0]=abs(arr[i]);
            }
        }
        for(int i=0;i<n;i++){
            if(arr[i]>0){
                ans[1]=i+1;
            }
        }
        int *temp = ans;
        return temp;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}