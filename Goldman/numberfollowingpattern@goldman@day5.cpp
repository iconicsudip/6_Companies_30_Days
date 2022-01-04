#include<bits/stdc++.h> 
using namespace std; 

 //https://practice.geeksforgeeks.org/problems/number-following-a-pattern3126/1
class Solution{   
public:
    string printMinNumberForPattern(string S){
        // code here 
        string ans="";
        stack<int>s;
        int num=1;
        for(int i=0;i<S.length();i++){
            if(S[i]=='D'){
                s.push(num);
                num++;
                //s=3,4,5
            }else{
                s.push(num);//s=1,
                num++;
                while(!s.empty()){
                    ans+=to_string(s.top());
                    s.pop();
                }
                //ans=1,2
                //cout<<ans<<endl;
            }
        }
        s.push(num);
        //s=3,4,5,6
        while(!s.empty()){
            ans+=to_string(s.top());
            s.pop();
        }
        //1,2,6,5,4,3
        return ans;
    }
};


// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.printMinNumberForPattern(S) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends