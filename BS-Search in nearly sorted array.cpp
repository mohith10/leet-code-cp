#include <bits/stdc++.h>
using namespace std;

int binary_Search_nearly_sorted(vector<int> a, int n, int ele){
    int start = 0, end = n-1;
    while(start<=end){
        int mid = start+(end-start)/2;
        int left = (mid-1+n)%n;
        int right = (mid+1)%n;
        if(a[mid]==ele) return mid;
        if(a[left] == ele) return left;
        if(a[right] == ele) return right;
        if(a[mid]>ele){
            end = (mid-2-n)%n;
        }else{
            start = (mid+2)%n;
        }
    }
    return -1;
}
int main() {
	// your code goes here
	int n, ele;
	cin>>n>>ele;
	vector<int> arr;
	for(int i=0;i<n;i++){
	    int x;
	    cin>>x;
	    arr.push_back(x);
	}
	cout<<binary_Search_nearly_sorted(arr,n,ele);
	return 0;
}
