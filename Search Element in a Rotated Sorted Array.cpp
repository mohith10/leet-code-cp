// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int a[n];
    int target;
    cin>>target;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int low=0,high = n-1;
    while(low<=high){
        int mid = (low+high)/2;
        if(a[mid]==target){
            cout<<mid;
            break;
        }
        if(a[low]<=a[mid]){
            if(a[low]<target && a[mid]>=target){
                high = mid-1;
            }
            else{
                low = mid +1;
            }
        }
        else{
            if(a[mid]<=target && a[high]>=target){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
    }
}
