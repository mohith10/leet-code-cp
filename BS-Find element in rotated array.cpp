#include <bits/stdc++.h>
using namespace std;

int find_index(vector<int> &a, int n){
    int start = 0, end = n-1;
    while(start<=end){
        //cout<<start<<" "<<end<<endl;
        int mid = start + (end - start)/2;
        int next = (mid+1)%n;
        int prev = (mid-1+n)%n;
        if(a[mid]<=a[prev] && a[mid]<=a[next]) return mid;
        else if(a[mid]<=a[end]) end = mid-1;
        else start = mid+1;
    }
    return 0;
}
int binary_Search(int start, int end, int ele, vector<int> arr){
    while(start<=end){
	    int mid = start+(end-start)/2;
	    if(arr[mid]==ele){
	       return mid;
	    }
	    if(arr[mid]>ele){
	        end = (mid-1);
	    }else{
	        start = (mid+1);
	    }
	}
	return -1;
}
int main() {
	// your code goes here
	int n;
	cin>>n;
	vector<int> arr;
	for(int i=0;i<n;i++){
	    int x;
	    cin>>x;
	    arr.push_back(x);
	}
	int ele = 4;
	int ind = find_index(arr,n);
	int start = ind, end = (ind-1+n)%n;
	cout<<max(binary_Search(0,(ind-1),ele,arr), binary_Search(ind,n-1,ele,arr));
	//cout<<"Array rotated by "<<n-ind;
	return 0;
}
