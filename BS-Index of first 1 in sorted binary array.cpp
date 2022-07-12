#include <bits/stdc++.h>
using namespace std;

int find_index_bs(vector<int> a, int n){
    int start = 0, end = n - 1;
    while(start <= end){
        int mid = start + (end-start)/2;
        if(a[mid] == 1){
            int prev = (mid-1+n)%n;
            if(a[prev]==1){
                end = mid-1;
                continue;
            }else{
                return mid;
            }
        }
        if(a[mid]!=1){
            start = mid+1;
        }
    }
    return -1;
}
int main() {
	// your code goes here
	int n;
	char ele;
	cin>>n;

	vector<int> arr;
	for(int i=0;i<n;i++){
	    int x;
	    cin>>x;
	    arr.push_back(x);
	}
	cout<<"Index of first 1 "<<find_index_bs(arr,n);
	return 0;
}
