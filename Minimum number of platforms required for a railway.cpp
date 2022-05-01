// Online C compiler to run C program online
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int n;
    cin>>n;
    vector< pair<int,int>> v;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        v.push_back(make_pair(a,b));
    }
    sort(v.begin(), v.end());
    int count = 1, res = 1;
    for(int i=1;i<n;i++){
        if(v[i].first<=v[i-1].second){
            count++;
        }
        else{
            count--;
        }
        res = max(res,count);
    }
    
    cout<<res;
    return 0;
}
