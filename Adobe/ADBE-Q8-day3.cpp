//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string str) {
        //Your code here
        int ans=0;
        int flag=0;
        for(int i=0;i<str.length();i++){
            if(i==0 && str[i]=='-'){
                flag=1;
                continue;
            }
            if(str[i]>='0' && str[i]<='9'){
                int t= str[i]-'0';
                ans=ans*10+t;
            }else{
                return -1;
            }
        }
        return flag==1?(-1*ans):ans;
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}  // } Driver Code Ends