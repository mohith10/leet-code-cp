// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    int a[n+1];
    for(int i=0;i<n+1;i++){
        cin>>a[i];
    }
    int fast = a[0], slow =a[0];
    
    do{
        slow = a[slow];
        fast = a[a[fast]];
    }while(slow!=fast);
    fast = a[0];
    while (slow != fast) {
    slow = a[slow];
    fast = a[fast];
  }
    cout<<slow;
    return 0;
}
