#include <bits/stdc++.h>
using namespace std;

int findInRotatedArray(vector<int> arr, int num, int key, int low,int high){
    int mid = low + (high-low)/2;
    if(arr[mid] == key) return mid;
    
    if(low>high) return -1;
    
    if(arr[mid] > arr[low]){
        if(key >= arr[low] && arr[mid] > key){
            findInRotatedArray(arr,num,key,low, mid-1);
        }else{
            findInRotatedArray(arr, num, key, mid+1,high);
        }
    }
    else if(arr[mid] < arr[low]){
        if(key > arr[mid] && arr[high] >= key){
            findInRotatedArray(arr,num,key,low, mid-1);
        }else{
            findInRotatedArray(arr, num, key, mid+1,high);
        }
    }
    else if(arr[low] == arr[mid]){
        if(arr[high]!=arr[mid]){
            findInRotatedArray(arr, num, key, mid+1,high);
        }
    }else{
        int res = findInRotatedArray(arr,num,key,low,mid-1);
        if(res == -1){
            findInRotatedArray(arr,num,key,mid+1,high);
        }else{
            return res;
        }
    }
}

int main() {
    int num, key;
    cin>>num>>key;
    vector<int> arr;
    for(int ind = 0; ind<num; ind++){
        int x;
        cin>>x;
        arr.push_back(x);
    }
    int index = findInRotatedArray(arr,num,key,0,num-1);
    cout<<index;
	return 0;
}
