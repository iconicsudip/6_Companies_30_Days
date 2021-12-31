#include<bits/stdc++.h>
using namespace std;
//https://practice.geeksforgeeks.org/problems/count-the-subarrays-having-product-less-than-k1708/1/
class Solution{
public:
    int countSubArrayProductLessThanK(const vector<int> &a, int n, long long k){
        int start = 0;
        int end = 0;
        long long int p = 1;
        int ans = 0;
        while (end < a.size()){
            p *= a[end];
            while (start < end && p >= k){
                p /= a[start++];
            }
            if (p < k){
                ans = ans + (end - start + 1);
            }
            end++;
        }
        return ans;
    }
};
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        long long int k;
        cin >> n >> k;
        vector<int> arr(n);
        for (i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        cout << obj.countSubArrayProductLessThanK(arr, n, k) << endl;
    }
    return 0;
}