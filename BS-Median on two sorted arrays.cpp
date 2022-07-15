#include <bits/stdc++.h>
using namespace std;

//n is lesser than  if not choose the smaller array as first

double median_sorted_arrays_bs(int n, vector<int> a, int m, vector<int> b){
    int low = 0, high = n;
    while(low<=high){
        int cut1 = low + (high - low)/2;
        int cut2 = ((n + m + 1)/2) - cut1;
        int l1 = INT_MIN, l2 = INT_MIN, r1 = INT_MAX, r2 = INT_MAX;
        if(l1-1>=0) l1 = a[cut1-1];
        if(l2-1>=0) l2 = b[cut2-1];
        if(cut1!=n) r1 = a[cut1];
        if(cut2!=m) r2 = b[cut2];
        
        if(l1<=r2 && l2<=r1){
            if(n+m%2==0){
                return ( max(l1,l2) + min(r1,r2) )/2.0;
            }else{
                return max(l1,l2);
            }
        }else if(l1>r2){
            high = cut1-1;
        }else {
            low = cut1+1;
        }
    }
    return 0.0;
}

int main() {
	int n,m;
	cin>>n>>m;
	
	vector<int> a;
	vector<int> b;
	for(int i=0;i<n;i++){
	        int x;
	        cin>>x;
	        a.push_back(x);
	}
	
	for(int i=0;i<m;i++){
	        int x;
	        cin>>x;
	        b.push_back(x);
	}
	cout<<median_sorted_arrays_bs(n,a,m,b);
	
	return 0;
	
}
