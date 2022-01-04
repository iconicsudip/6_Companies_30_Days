#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int findPosition(int N , int M , int K) {
        // code here
        int ans = (M+K-1)%N;
        if(ans==0){
            return N;
        }
        return ans;
    }
};
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,M,K;
        
        cin>>N>>M>>K;

        Solution ob;
        cout << ob.findPosition(N,M,K) << endl;
    }
    return 0;
}