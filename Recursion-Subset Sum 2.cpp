#include <bits/stdc++.h>
using namespace std;

void subset_sum_duplicate(int ind, int n, vector<int> a, vector<int> res){
  for(int i=0;i<res.size();i++){
      cout<<res[i]<<" ";
  }
  cout<<endl;
  for(int i=ind;i<n;i++){
      if(i>ind && a[i] == a[i-1]) continue;
      res.push_back(a[i]);
      subset_sum_duplicate(i+1,n,a,res);
      res.pop_back();
  }
}

int main() {
    vector<int> a;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        a.push_back(x);
    }
    vector<int> res;
    subset_sum_duplicate(0,n,a,res);
    return 0;
}
