
#include <iostream>
#include <bits/stdc++.h>
#include<unordered_map>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
       cin>>a[i];
    }
    unordered_map<int,int> m;
    int sum =0, res =0;
    for(int i=0;i<n;i++){
        sum = sum + a[i];
        
        if(sum == 0){
            res = i+1;
        }
        else{
            if(m.find(sum) != m.end()){
            res = max(res,i-m[sum]);
            }
            else{
                m[sum] = i;
            }
        }
    }
    cout<<res;
}
