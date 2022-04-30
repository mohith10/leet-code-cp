
// C++ program to sort an array
#include <algorithm>
#include <iostream>
using namespace std;
int main() {
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    
    sort(a,a+n);
    
    cout<<endl;
    for(int i=0;i<n-2;i++){
        if(i==0 || (i>0 && a[i]!=a[i-1])){
        int low = i+1, high = n-1, req = 0-a[i];
        while(low<high){
            if(a[low] + a[high] > req){
                high--;
            }
            else if(a[low] + a[high] < req){
                low++;
            }
            else{
                while(low<high && a[low]==a[low+1]){
                    low++;
                }
                while(a[high]==a[high-1] && low<high){
                    high--;
                }
                //cout<<"Low = "<<low<<" High="<<high<<endl;
                cout<<a[i]<<" "<<a[low]<<" "<<a[high]<<endl;
                low++;
                high--;
            }
        }}
    }
}
