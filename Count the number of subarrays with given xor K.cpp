
#include <iostream>

using namespace std;

int main()
{
    int n,target;
    cin>>n>>target;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int count = 0;
    for(int i=0;i<n;i++){
        int XoR = 0;
        for(int j = i; j<n;j++){
            XoR = XoR^a[j];
            
            count = count +  (XoR == target);
        }
    }
    cout<<count;
}
