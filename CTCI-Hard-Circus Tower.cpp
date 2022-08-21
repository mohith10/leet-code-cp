#include <bits/stdc++.h>
using namespace std;

int findLargestSub(vector<pair<int, int>> arr, vector<int> &countVector, int maxIndex){
    countVector[maxIndex]++;
    for(int i=0; i<maxIndex; i++){
        if(arr[i].first < arr[maxIndex].first && arr[i].second < arr[maxIndex].second){
            countVector[maxIndex]++;
        }
    }
    return countVector[maxIndex];
}

int  buildCircusTower(vector<pair<int,int>> arr, int size){
    int res = INT_MIN;
    vector<int> countVector(size, 0);
    for(int ind = 0; ind<size; ind++){
        res = max(res, findLargestSub(arr, countVector, ind));
    }
    return res;
}

int main() {
	vector<pair<int,int>> arr;
	int size, i=0;
	cin>>size;
	while(i++ < size){
	    int h, w;
	    cin>>h>>w;
	    arr.push_back({h,w});
	}
	int res = buildCircusTower(arr, size);
	cout<<res;
	return 0;
}
