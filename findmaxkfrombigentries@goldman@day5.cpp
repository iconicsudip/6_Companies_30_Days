#include<bits/stdc++.h>
using namespace std;
vector<int> findarray(vector<int> &v,int n){
    vector<int>ans;
    unordered_map<int,int>mp;
    for( int i=0;i<n;i++){
        int max = 0;
        int pos=0;
        for(int j=0;j<v.size();j++){
            if(v[j]>max){
                max=v[j];
                pos = j;
            }
        }
        mp[pos]=max;
        v[pos]=0;
        ans.push_back(max);
    }
    for(auto c:mp){
        v[c.first] = c.second;
    }
    return ans;
}
int main(){
    vector<int> v={2, 6, 41, 85, 0, 3, 7, 6, 10};
    int n=3;
    vector<int>ans=findarray(v,n);
    for(auto c:ans){
        cout<<c<<" ";
    }
    return 0;
}