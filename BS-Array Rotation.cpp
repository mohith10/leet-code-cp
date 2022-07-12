#include <bits/stdc++.h>
using namespace std;

int find_index(vector<int> &a, int n){
    int start = 0, end = n-1;
    while(start<=end){
        cout<<start<<" "<<end<<endl;
        int mid = start + (end - start)/2;
        int next = (mid+1)%n;
        int prev = (mid-1+n)%n;
        if(a[mid]<=a[prev] && a[mid]<=a[next]) return mid;
        else if(a[mid]<=a[end]) end = mid-1;
        else start = mid+1;
    }
    return 0;
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
	
	int ind = find_index(arr,n);
	cout<<"Array rotated by "<<n-ind;
	return 0;
}
