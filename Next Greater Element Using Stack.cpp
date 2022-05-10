// Online C++ compiler to run C++ program online
#include <iostream>
#include<stack>
using namespace std;

int main() {
   stack<int> s;
   int n;
   cin>>n;
   int a[n],ans[n];
   for(int i=0;i<n;i++){
       cin>>a[i];
   }
   
   for(int i=2*n-1;i>=0;i--){
       while(!s.empty() && a[i%n]>=s.top()){
           s.pop();
       }
       if(i<n){
           if(!s.empty()){
               ans[i]=s.top();
           }
           else{
               ans[i]=-1;
           }
       }
       
        s.push(a[i%n]);
   }
   for(int i=0;i<n;i++){
       cout<<ans[i]<<" ";
   }
}
