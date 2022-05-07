// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
double mul(double n,int k){
    double ans = 1.0;
    for(int i=1;i<=k;i++){
        ans = ans * n;
    }
    return ans;
}
int main() {
    double n,m;
    cin>>n>>m;
    double low = 1, high = m, eps = 1e-6;
    while((high-low) > eps){
        double mid = (high+low)/2.0;
        if(mul(mid,n)<m){
            low = mid;
        }
        else{
            high = mid;
        }
        cout<<"Iteration "<<high<<" "<<low<<endl;
    }
    cout<<low;
}
