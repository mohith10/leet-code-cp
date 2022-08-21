#include <bits/stdc++.h>
using namespace std;

int validateMajority(vector<int> arr, int size, int majority){
    int count = 0;
    for(int ind = 0; ind<size; ind++){
        count+=(arr[ind] == majority);
    }
    cout<<"Count of majority "<<majority<<" is "<<count<<endl;
    if(count <= size/2){
        return -1;
    }
    return majority;
}

int findMajority(vector<int> arr, int size){
    int count = 0, majority = 0;
    for(int ind = 0; ind<size; ind++){
        if(count == 0){
            majority = arr[ind];
        }else if(arr[ind] == majority){
            count++;
        }else{
            count--;
        }
        cout<<arr[ind]<<" "<<majority<<" "<<count<<endl;
    }
    cout<<"Tenative "<<majority<<endl;
    return majority = validateMajority(arr, size, majority);
}


int main() {
	int size, i = 0;
	vector<int> arr;
	cin>>size;
	while( i++ < size){
	    int ele;
	    cin>>ele;
	    arr.push_back(ele);
	}
	int res = findMajority(arr, size);
	cout<<res;
	return 0;
}
