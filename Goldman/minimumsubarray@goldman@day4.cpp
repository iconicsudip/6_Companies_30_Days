#include<bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/minimum-size-subarray-sum/
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        /*
        2:0
        
        */
        int sum=0;
        int j=0;
        int ans=INT_MAX;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            //sum=6;
            while(j<nums.size() && sum>=target){
                if(sum>=target){
                    ans = min(ans,i-j+1);
                    //ans=3
                }
                sum-=nums[j];
                j++;
            }
        }
        return (ans==INT_MAX)?0:ans;
    }
};