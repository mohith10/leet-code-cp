// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
int main() {
    int m,n, key;
    cin>>m>>n>>key;
    int a[m][n];
    for(int i=0;i<m;i++){
        for(int j= 0;j<n;j++){
            cin>>a[i][j];
        }
    }
    
    int low = 0, high = (m*n)-1;
    while(low<=high){
        int mid = (low+high)/2;
        if(a[mid/m][mid%m]==key){
            cout<<"Found "<<mid/m<<" "<<mid%m;
            break;
        }
        else if(a[mid/m][mid%m]<key){
            low = mid + 1;
        }
        else{
            high = mid-1;
        }
    }
}
