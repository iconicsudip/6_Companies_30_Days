#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
    static int partition(char arr[],int start,int end,char pivot){
        int i=start+1;
        int j= end;
        while(i<=j){
            while(arr[i]<=pivot && i<=end){
                i++;
            }
            while(arr[j]>pivot){
                j--;
            }
            if(i<=j){
                swap(arr[i],arr[j]);
                i++;
                j--;
            }
        }
        arr[start] = arr[j];
        arr[j]=pivot;
        return j;
    }
    static void quicksort(char *nuts,char *bolts,int start,int end){
        if(start<end){
            int pivot = partition(nuts,start,end,nuts[start]);
            int pivot2 = partition(bolts,start,end,bolts[start]);
            quicksort(nuts,bolts,start,pivot-1);
            quicksort(nuts,bolts,pivot+1,end);
            quicksort(nuts,bolts,start,pivot2-1);
            quicksort(nuts,bolts,pivot2+1,end);
        }
    }
	void matchPairs(char nuts[], char bolts[], int n) {
	    // code here
	    quicksort(nuts,bolts,0,n-1);
	}

};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        char nuts[n], bolts[n];
        for (int i = 0; i < n; i++) {
            cin >> nuts[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> bolts[i];
        }
        Solution ob;
        ob.matchPairs(nuts, bolts, n);
        for (int i = 0; i < n; i++) {
            cout << nuts[i] << " ";
        }
        cout << "\n";
        for (int i = 0; i < n; i++) {
            cout << bolts[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
  // } Driver Code Ends