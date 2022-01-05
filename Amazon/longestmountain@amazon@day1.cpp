#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int count=0;
        int ans=0;
        for(int i=1;i<arr.size();i++){
            if(arr[i]==arr[i-1]){
                count=0;
                continue;
            }else if(arr[i]>arr[i-1]){
                count++;
            }else if(count>0){
                while(i<arr.size() && arr[i]<arr[i-1]){
                    count++;
                    i++;
                }
                ans = max(ans,count+1);
                count=0;
                i--;
            }
        }
        return ans;
    }
};
int main(){
    Solution c;
    vector<int>arr={2,1,4,7,3,2,5};
    cout<<c.longestMountain(arr);
}