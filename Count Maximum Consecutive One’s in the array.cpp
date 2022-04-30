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
    int result = 0, current = 0;
    for(int i=1;i<n;i++){
        if(a[i]!=1){
            result = max(result,current);
            current = 0;
        }
        current+=(a[i]==1);
    }
    cout<<result;
}
