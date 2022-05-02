// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

void generateSubset(int i,int a[],int n,int sum){
    if(i==n){
        cout<<"Sum = "<<sum<<endl;
        return;
    }
    generateSubset(i+1,a,n,sum+a[i]);
    generateSubset(i+1,a,n,sum);
}
int main() {
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    generateSubset(0,a,n,0);
    return 0;
}
