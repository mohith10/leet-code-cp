#include <bits/stdc++.h>
using namespace std;
bool isValid(double num, double n,double k){
    double res = 1;
    for(int i=0;i<k;i++){
        res = res * num;
    }
    return res<=n;
}


double n_root_bs(double n, double k){
    double start = 0, end = n, res = INT_MIN;
    while(end-start>1e-6){
        double mid = start + (end-start)/2;
        //cout<<start<<" "<<mid<<" "<<end<<endl;
        if(isValid(mid,n,k)){
            res = max(res,mid);
            start = mid;
        }else{
            end=mid;
        }
        
    }
    return res;
}


int main() {
	// your code goes here
	double n,k;
	cin>>n>>k;
	cout<<n_root_bs(n,k);
	return 0;
	
}
