#include<bits/stdc++.h>
using namespace std;
//https://practice.geeksforgeeks.org/problems/print-anagrams-together/1/#
class Solution{
    public:
        vector<vector<string> > Anagrams(vector<string>& string_list) {
        //code here
            unordered_map<string,vector<string>>mp;
            for(int i=0;i<string_list.size();i++){
                string s=string_list[i];
                sort(s.begin(),s.end());
                mp[s].push_back(string_list[i]);
            }
            vector<vector<string>>ans;
            for(auto it=mp.begin();it!=mp.end();it++){
                vector<string>temp;
                for(int i=0;i<it->second.size();i++){
                    temp.push_back(it->second[i]);
                }
                ans.push_back(temp);
            }
            return ans;
        }
};
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<string> string_list(n);
        for (int i = 0; i < n; ++i)
            cin>>string_list[i]; 
        Solution ob;
        vector<vector<string> > result = ob.Anagrams(string_list);
        sort(result.begin(),result.end());
        for (int i = 0; i < result.size(); i++)
        {
            for(int j=0; j < result[i].size(); j++)
            {
                cout<<result[i][j]<<" ";
            }
            cout<<"\n";
        }
    }

    return 0;
}