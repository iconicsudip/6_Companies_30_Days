#include<bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/greatest-common-divisor-of-strings/submissions/
class Solution {
public:
    int gcd(int a,int b){
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }
    string gcdOfStrings(string str1, string str2) {
        return (str1+str2==str2+str1) ? str1.substr(0,gcd(max(str1.length(),str2.length()),min(str1.length(),str2.length()))): "";
    }
};
int main(){
    Solution s;
    cout<<s.gcdOfStrings("ABABAB","AB");
}