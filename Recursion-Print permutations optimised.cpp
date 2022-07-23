#include <bits/stdc++.h>
using namespace std;

void swap(int ind1, int ind2 ,vector<int> &arr){
    int t = arr[ind1];
    arr[ind1] = arr[ind2];
    arr[ind2] = t;
}

void permutations_extra_space(int ind, int n, vector<int> a){
    if(ind == n){
        for(int i=0;i<n;i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
        return;
    }
    
    for(int i=ind;i<n;i++){
            swap(ind,i,a);
            permutations_extra_space(ind+1,n,a);
            swap(ind,i,a);
    }
}

int main() {
	vector<int> a;
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
	    int x;
	    cin>>x;
	    a.push_back(x);
	}
	vector<int> res;
	permutations_extra_space(0,n,a);
	return 0;
}
