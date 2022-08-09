#include <bits/stdc++.h>
using namespace std;

void mergeSortedArrays(int arr1Size, int arr2Size, vector<int> &arr1, vector<int> &arr2){
    int arr1Iter = arr1Size-1, arr2Iter = arr2Size-1;
    int mergedIndex = arr1Size + arr2Size - 1;
    while(arr2Iter >=0){
        if(arr1Iter >= 0 && arr1[arr1Iter] > arr2[arr2Iter]){
            arr1[mergedIndex] = arr1[arr1Iter];
            arr1Iter--;
        }else{
            arr1[mergedIndex] = arr2[arr2Iter];
            arr2Iter--;
        }
        mergedIndex--;
    }
}

int main() {
    int arr1Size, arr2Size;
    cin>>arr1Size>>arr2Size;
    vector<int> arr1(arr1Size + arr2Size,0), arr2;
    
    for(int insertIndex = 0; insertIndex<arr1Size; insertIndex++){
        int x;
        cin>>x;
        arr1[insertIndex] = x;
    }
    for(int insertIndex = 0; insertIndex<arr2Size; insertIndex++){
        int x;
        cin>>x;
        arr2.push_back(x);
    }
    mergeSortedArrays(arr1Size, arr2Size, arr1,arr2);
    for(int index = 0; index<arr1.size(); index++){
        cout<<arr1[index]<<" ";
    }
	// your code goes here
	return 0;
}
