#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, sum=0;
    cin>>n;
    int a[n];
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum = sum + a[i];
    }
    int fast = a[1], slow =a[1];
    
    do{
        slow = a[slow];
        fast = a[a[fast]];
    }while(slow!=fast);
    fast = a[1];
    while (slow != fast) {
    slow = a[slow];
    fast = a[fast];
  }
    cout<<"Repeating Number: "<<slow;
    cout<<"\nMissing Number: "<<((n*(n+1))/2 - sum) + slow;
    return 0;
}
