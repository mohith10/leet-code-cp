#include <bits/stdc++.h>
using namespace std;

int single_element(vector<int> a, int n){
    int start = 0, end  = n - 1;
    while(start<=end){
        int mid = start + (end-start)/2;
        //cout<<a[start]<<" "<<a[mid]<<" "<<a[end]<<endl;
        if(mid%2==1){
            if(a[mid] != a[mid-1]){
                end = mid-1;
            }else{
                start = mid+1;
            }
        }
        
        else{
            if(a[mid] != a[mid+1]){
                end = mid - 1;
            }else{
                start = mid + 1;
            }
        }
    }
    return a[start];
}


int main() {
	int n;
	cin>>n;
	
	vector<int> a;
	for(int i=0;i<n;i++){
	        int x;
	        cin>>x;
	        a.push_back(x);
	    
	}
	cout<<single_element(a,n);
	return 0;
	
}
