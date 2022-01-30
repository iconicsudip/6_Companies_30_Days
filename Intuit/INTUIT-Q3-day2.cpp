#include<bits/stdc++.h>
using namespace std;
const int MAX_DIGITS = 5;

int missingNumber(const string& str);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        cout << missingNumber(str)<<endl;
    }
	return 0;
}
// } Driver Code Ends


/* You are required to complete this function
which return the required missing number
if present else return -1*/
int getval(string str,int st,int end){
    int num=0;
    for(int i=st;i<end;i++){
        int c = str[i]-'0';
        if(c<0){
            return -1;
        }
        num=num*10+c;
    }
    return num;
}
int missingNumber(const string& str)
{
    // Code here
    //89101113==12
    for(int i=1;i<=6;i++){
        int val = getval(str,0,i);
        if(val==-1){
            break;
        }
        int missingNo = -1;
        bool fail = false;
        for(int j=i;j<str.length();j=j+log10l(val)+1){
            if(getval(str,j,j+1+log10l(val+1))==val+1){
                val++;
            }else if(missingNo==-1 && getval(str,j,j+1+log10l(val+2))==val+2){
                missingNo = val+1;
                val+=2;
            }else{
                fail = true;
                break;
            }
        }
        if(!fail){
            return missingNo;
        }
    }
    return -1;
}