// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
int main() {
   int n;
   cin>>n;
   int a[n];
   for(int i=0;i<n;i++){
       cin>>a[i];
   }
   int low =0,high = n-2;
   while(low<=high){
       int mid = (low + high)/2;
       if(a[mid] == a[mid^1]){
           low = mid + 1;
       }
       else{
           high = mid - 1;
       }
   }
   cout<<a[low];
}
