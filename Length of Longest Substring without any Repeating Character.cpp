
#include <iostream>
#include<vector>
using namespace std;

int main()
{
    string s;
    getline(cin,s);
    vector<int> m(256,-1);
    int res =0, l=0, r=0;
    while(r<s.size()){
        if(m[s[r]]!=-1){
            l = max(m[s[r]]+1,l);
        }
        m[s[r]] = r;
        
        res = max(res,r-l+1);
        r++;
    }
    cout<<res;
}
