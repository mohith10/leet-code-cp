#include <bits/stdc++.h>
using namespace std;

int max_bitonic_bs(vector<int> a, int n){
    int start = 0, end = n-1, res = INT_MIN;
    while(start<=end){
        int mid = start + (end-start)/2;
        res = max(res,a[mid]);
        if(mid!=n-1 && a[mid+1]>a[mid]){
            start = mid + 1;
        }else{
            end = mid-1;
        }
    }
    return res;
}
int main() {
	// your code goes here
	int n;
	double ele;
	cin>>n;
	vector<int> arr;
	for(int i=0;i<n;i++){
	    int x;
	    cin>>x;
	    arr.push_back(x);
	}
	cout<<max_bitonic_bs(arr,n);
	return 0;
}
