

#include <iostream>
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
void twopointer(int a[],int low, int high){
    
}
int main()
{
    int n, target;
    cin>>n>>target;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++)
        {
            int rem = target - (a[i] + a[j]);
            int low = j+1, high = n-1;
            while(low<high){
                if(a[low] + a[high] == rem){
                    cout<<a[i]<<" "<<a[j]<<" "<<a[low]<<" "<<a[high]<<endl;
                    while(a[low]!=a[low+1]){
                        low++;
                    }
                }
                if(a[low] + a[high] < rem){
                    low++;
                }
                else if (a[low] + a[high] > rem){
                    high--;
                }
            }
            while(a[j]==a[j+1]){
                j++;
            }
            
        }
        while(a[i]==a[i+1]){
                i++;
            }
    }
    
}
