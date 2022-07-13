#include <bits/stdc++.h>
using namespace std;

bool isValid(vector<int> a,int n,int mid,int k){
    int count = 1,sum = 0;
    for(int i=0;i<n;i++){
        if(sum+a[i]>mid){
            count++;
            sum=a[i];
        }else{
            sum+=a[i];
        }
    }
    if(count==k) return true;
    
    return false;
}

int min_pages_bs(vector<int> a,int n,int start, int end, int k){
    int res = INT_MAX;
    while(start<=end){
        int mid = start+(end-start)/2;
        
        if(isValid(a,n,mid,k)){
            res = min(res,mid);
            end = mid-1;
        }else{
            start = mid+1;
        }
    }
    return res;
}


int main() {
	// your code goes here
	int n;
	int k;
	cin>>n>>k;
	vector<int> a;
	int sum = 0, maxi = INT_MIN;
	for(int i=0;i<n;i++){
	    int x;
	    cin>>x;
	    a.push_back(x);
	    sum+=x;
	    maxi = max(maxi,x);
	}
	cout<<min_pages_bs(a,n,maxi,sum, k);
	return 0;
}
