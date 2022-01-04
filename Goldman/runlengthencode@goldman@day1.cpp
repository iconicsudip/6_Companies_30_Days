#include <bits/stdc++.h>
using namespace std;
//https://practice.geeksforgeeks.org/problems/run-length-encoding/1/
string encode(string src); 
int main() {
    int T;
    cin>>T;
    while(T--)
    {
        string str;
        cin>>str;
        
        cout<<encode(str)<<endl;
    }
    return 0;
}

string encode(string src){     
  //Your code here 
    int count=1;
    string s="";
    char prev  = src[0];
    for(int i=1;i<src.length();i++){
        if(src[i]==prev){
            count++;
        }else{
            s=s+prev+to_string(count);
            count=1;
            prev = src[i];
        }
    }
    s+=prev+to_string(count);
    return s;
}