// Online C++ compiler to run C++ program online
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool sortbysec(const pair<int,int> &a,
              const pair<int,int> &b)
{
    return (a.second < b.second);
}
int main() {
    int n;
    vector< pair<int,int>> v;
    cin>>n;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        v.push_back(make_pair(a,b));
    }
    
    sort(v.begin(), v.end(), sortbysec);
    int sum = 1;
    cout<<v[0].first<<" "<<v[0].second<<endl;
    for(int i=1; i<n ;i++){
        if(v[i].first>=v[i-1].first){
            sum++;
            cout<<v[i].first<<" "<<v[i].second<<endl;
        }
    }
    
    cout<<sum;
}
