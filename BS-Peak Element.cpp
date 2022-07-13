#include <bits/stdc++.h>
using namespace std;

int peak_ele(vector<int> a, int n){
    int start = 0, end = n-1;
    while(start<=end){
        int mid = start + (end-start)/2;
        cout<<start<<" "<<mid<<" "<<end<<endl;
        if(mid!=0 && mid!=n-1){
            if(a[mid]>a[mid-1] && a[mid]>a[mid+1]) return mid;
            
            if(a[mid-1]>a[mid]){
                end = mid-1;
            }
            
            else if(a[mid+1] > a[mid]){
                start = mid + 1;
            }
        }else{
            if(mid==0){
                if(a[mid] > a[mid+1]) return mid;
                else return mid+1;
            }
            if(mid==n-1){
                if(a[mid] > a[mid-1]) return mid;
                else return mid-2;
            }
        }
    }
    return -1;
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
	cout<<peak_ele(arr,n);
	return 0;
}
