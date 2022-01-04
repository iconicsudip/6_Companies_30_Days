#include<bits/stdc++.h>
using namespace std;
int countsquares(int n){
    int ans = n*(n+1)/2;
    ans = ans *(2*n+1)/3;
    return ans;
}
int main(){
    int n;
    cout<<"Chessboard number = ";
    cin>>n;
    cout<<countsquares(n);
    return 0;
}