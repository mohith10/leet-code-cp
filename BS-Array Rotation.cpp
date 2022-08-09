#include <bits/stdc++.h>
using namespace std;

int findOriginOfRotation(vector<int> arr, int num){
    int low = 0, high = num-1;
    while(low<high){
        int mid = low + (high-low)/2;
        int prev = (mid-1+num)%num;
        int next = (mid+1)%num;
        if(arr[mid] < arr[prev] && arr[mid] < arr[next]) return mid;
        if(arr[mid] < arr[high]){
            high = mid-1;
        }else{
            low = mid + 1;
        }
    }
    
}

int main() {
    int num;
    cin>>num;
    vector<int> arr;
    for(int ind = 0; ind<num; ind++){
        int x;
        cin>>x;
        arr.push_back(x);
    }
    int origin = findOriginOfRotation(arr,num);
    cout<<origin;
	return 0;
}
