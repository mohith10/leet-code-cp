#include <bits/stdc++.h>
using namespace std;

int binary_search_floor(vector<int> a, int n, double ele){
    int start = 0, end = n-1, res = INT_MIN;
    while(start<=end){
        int mid = start+(end-start)/2;
        if(a[mid]==ele) return mid;
        if(a[mid]<ele){
            res = max(res,a[mid]);
            start = mid+1;
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
	cin>>n>>ele;
	vector<int> arr;
	for(int i=0;i<n;i++){
	    int x;
	    cin>>x;
	    arr.push_back(x);
	}
	cout<<binary_search_floor(arr,n,ele);
	return 0;
}
