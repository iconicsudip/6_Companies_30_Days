#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int speed=1;
        int maxspeed = 0;
        for(int i =0;i<piles.size();i++){
            maxspeed = max(maxspeed,piles[i]);
        }
        while(speed<maxspeed){
            int midspeed = speed + (maxspeed-speed)/2;
            
            int hour=0;
            for(int i=0;i<piles.size();i++){
                if(piles[i]%midspeed!=0){
                    hour+=piles[i]/midspeed +1;
                }else{
                    hour+=piles[i]/midspeed;
                }
            }
            if(hour<=h){
                maxspeed = midspeed;
            }else{
                speed=midspeed+1;
            }
        }
        return maxspeed;
    }
};