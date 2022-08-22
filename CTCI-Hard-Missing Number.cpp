#include <bits/stdc++.h>
using namespace std;

int findOneMissing(vector<int> arr, int size){
    int preCalculated = ((size)*(size + 1))/2;
    int sum = 0;
    for(int i=0;i<size;i++){
        sum+=(arr[i]);
    }
    return preCalculated - sum;
}

int main() {
	int size, i = 0;
	cin>>size;
	vector<int> arr;
	while(i++ < size){
	    int ele;
	    cin>>ele;
	    arr.push_back(ele);
	}
	int res = findOneMissing(arr, size);
	cout<<res;
	return 0;
}
