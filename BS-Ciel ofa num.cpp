#include <bits/stdc++.h>
using namespace std;

int binary_search_ciel(vector<int> a, int n, double ele){
    int start = 0, end = n-1, res = INT_MAX;
    while(start<=end){
        int mid = start+(end-start)/2;
        if(a[mid]==ele) return mid;
        if(a[mid]<ele){
            start = mid+1;
        }else{
            res = min(res,a[mid]);
            end = mid-1;
        }
    }
    return res;
}
int main() {
	// your code goes here
	int n;
	double ele;
	cin>>n>>ele;
	vector<int> arr;
	for(int i=0;i<n;i++){
	    int x;
	    cin>>x;
	    arr.push_back(x);
	}
	cout<<binary_search_ciel(arr,n,ele);
	return 0;
}
