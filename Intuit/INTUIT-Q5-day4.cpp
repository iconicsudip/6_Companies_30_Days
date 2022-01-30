#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    static bool isPossible(vector<int>&nums,int mid,int m){
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(sum>mid){
                sum=nums[i];
                m--;
            }
        }
        return m>=1;
    }
    int splitArray(vector<int>& nums, int m) {
        int sumnum=0;
        int maxi=0;
        for(int i=0;i<nums.size();i++){
            sumnum+=nums[i];
            maxi=max(maxi,nums[i]);
        }
        int low = maxi;
        int high = sumnum;
        int ans = INT_MAX;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(isPossible(nums,mid,m)){
                ans = min(ans,mid);
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};