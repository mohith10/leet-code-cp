// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
int main() {
    int n,m;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    
    int count1=0,count2=0,ele1 = -1, ele2 = -1;
    for(int i=0;i<n;i++){
        if(count1 == 0){
            ele1 = a[i];
        }
        else if(count2 == 0 ){
            ele2 = a[i];
        }
       
        if(a[i] == ele1){
            count1++;
        }
       
        if(a[i] == ele2){
            count2++;
        }
        
        if(a[i]!=ele1 && a[i]!=ele2){
            count1--;
            count2--;
        }
       
    }
    count1 = 0, count2 = 0;
    for(int i=0;i<n;i++){
        count1+=(a[i]==ele1);
        count2+=(a[i]==ele2);
        if(count1>n/3)
            cout<<ele1<<" ";
        if(count2>n/3)
            cout<<ele2;
    }
}
