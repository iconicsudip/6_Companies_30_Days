#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    static bool isPossible(vector<int>& arr,int mid,int days){
        int sum=0;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
            if(sum>mid){
                days--;
                sum=arr[i];
            }
        }
        return days>=1;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int wSum=0;
        int maxi = 0;
        for(int i=0;i<weights.size();i++){
            wSum+=weights[i];
            maxi=max(maxi,weights[i]);
        }
        int low = maxi;
        int high = wSum;
        int ans = 0;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(isPossible(weights,mid,days)){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};