//Initial Template for C++

#include <bits/stdc++.h>
#include <string>

using namespace std;


class Solution
{
    public:
    //Function to find list of all words possible by pressing given numbers.
    static void combination(unordered_map<int,string>&mp,vector<string>&ans,string op,int a[],int N,int index){
        if(index==N){
            ans.push_back(op);
            return;
        }
        int dial = a[index];
        string temp=mp[dial];
        for(int i=0;i<temp.length();i++){
            op.push_back(temp[i]);
            combination(mp,ans,op,a,N,index+1);
            op.pop_back();
        }
    }
    vector<string> possibleWords(int a[], int N)
    {
        //Your code here
        int index=0;
        vector<string>ans;
        unordered_map<int,string>mp;
        mp[2]="abc";
        mp[3]="def";
        mp[4]="ghi";
        mp[5]="jkl";
        mp[6]="mno";
        mp[7]="pqrs";
        mp[8]="tuv";
        mp[9]="wxyz";
        string output = "";
        combination(mp,ans,output,a,N,index);
        return ans;
    }
};


// { Driver Code Starts.

int main() {
  
	int T;
	
	cin >> T; //testcases
	
	while(T--){ //while testcases exist
	   int N;
	    
	   cin >> N; //input size of array
	   
	   int a[N]; //declare the array
	   
	   for(int i =0;i<N;i++){
	       cin >> a[i]; //input the elements of array that are keys to be pressed
	   }
	   
	   Solution obj;
	   
	  vector <string> res = obj.possibleWords(a,N);
	  for (string i : res) cout << i << " ";
	   cout << endl;
	}
	
	return 0;
}  // } Driver Code Ends