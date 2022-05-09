// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
int main() {
   int n,stud;
   cin>>n>>stud;
   int a[n],sum=0;
   for(int i=0;i<n;i++){
       cin>>a[i];
       sum+=a[i];
   }
   int low = a[0], high = sum;
   if(stud>n){
       cout<<-1;
       exit(0);
   }
   while(low<=high){
       int mid = (low + high)/2;
       //check
       cout<<low<<" "<<mid<<" "<<high<<endl;
       int sumAlloc = 0, count = 1, flag = 0;
       for(int i=0;i<n;i++){
           if(sumAlloc + a[i] > mid){
               count++;
               sumAlloc = a[i];
               if(sumAlloc > mid){
                   flag = -1;
                   cout<<"break"<<endl;
               }
           }
           else{
               sumAlloc=sumAlloc + a[i];
           }
           if(flag == -1){
               break;
           }
           cout<<sumAlloc<<" "<<count<<endl;
       }
       if(count>stud || flag == -1){
           low = mid + 1;
           cout<<"not fit\n";
       }
       else{
          high  = mid - 1;
          cout<<"fit\n";
       }
       
   }
   cout<<low;
}
