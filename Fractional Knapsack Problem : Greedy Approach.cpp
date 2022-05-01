// Online C compiler to run C program online
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool static comp(pair<int,int> a, pair<int,int> b) {
         double r1 = (double) a.first / (double) a.second;
         double r2 = (double) b.first / (double) b.second;
         return r1 > r2;
      }

int main() {
    int n,w;
    cin>>n>>w;
    vector< pair<int,int>> v;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        v.push_back(make_pair(a,b));
    }
    int currWeight=0, value=0;
    sort(v.begin(), v.end(), comp);
    for(int i=0;i<n;i++){
        if(v[i].second+currWeight <=w){
            value = value + v[i].first;
            currWeight+=v[i].second;
        }
        else{
            int rem = w - currWeight;
            value+= (v[i].first/(double)v[i].second) * (double)rem;
            break;
        }
    }
    cout<<value;
    
    
}
