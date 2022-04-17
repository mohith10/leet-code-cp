
#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    int n, target;
    cin>>n>>target;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    unordered_map<int,int> m;
    for(int i=0;i<n;i++){
        if(m.find(target - a[i])!=m.end()){
          cout<<"Found "<<i<<" "<<m[target-a[i]];
          break; 
        }
    else{
         m[a[i]] = i;
         cout<<"m[a[i]] = "<<m[a[i]]<<endl;
    }
    }
}
