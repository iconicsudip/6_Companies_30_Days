#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long


 // https://practice.geeksforgeeks.org/problems/ugly-numbers2254/1
class Solution{
public:	
	// #define ull unsigned long long
	/* Function to get the nth ugly number*/
	ull getNthUglyNo(int n) {
	    // code here
        set<long long int>s;
        s.insert(1);
        n--;
        for(int i=1;i<=n;i++){
            auto it = s.begin();
            long long int x = *it;
            s.erase(it);
            s.insert(x*2);
            s.insert(x*3);
            s.insert(x*5);
        }
        return *s.begin();
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.getNthUglyNo(n);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends