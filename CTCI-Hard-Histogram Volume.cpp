#include <bits/stdc++.h>
using namespace std;

int findVolumeHistogram(vector<int> arr, int size){
    int leftMaxNum = 0;
    vector<int> leftMax(size, 0), rightMax(size, 0), minVector(size, 0), deltaVector(size, 0);
    for(int i=0;i<size;i++){
        if(arr[i] > leftMaxNum){
            leftMaxNum = arr[i];
        }
        leftMax[i] = leftMaxNum;
    }
    int rightMaxNum = 0, sum = 0;
    for(int i=size-1;i>=0;i--){
        if(arr[i] > rightMaxNum){
            rightMaxNum = arr[i];
        }
        rightMax[i] = rightMaxNum;
        minVector[i] = min(leftMax[i], rightMax[i]);
        deltaVector[i] = abs(arr[i] - minVector[i]);
        sum+=deltaVector[i];
    }
    return sum;
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
	int res = findVolumeHistogram(arr, size);
	cout<<res;
	return 0;
}
