#include <bits/stdc++.h>
using namespace std;

void pairWithSumK(int size, vector<int> arr, int key){
    sort(arr.begin(), arr.end());
    int begin = 0, end = size - 1;
    while(begin<end){
        int sum = arr[begin] + arr[end];
        if(sum == key){
            cout<<arr[begin]<<" "<<arr[end]<<endl;
            begin++, end--;
        }
        else if(sum < key){
            begin++;
        }
        else{
            end--;
        }
    }
    return;
}

int main() {
	int size, key;
	cin>>size>>key;
	vector<int> arr;
	for(int i=0; i<size;i++){
	    int ele;
	    cin>>ele;
	    arr.push_back(ele);
	}
	pairWithSumK(size, arr, key);
	return 0;
}
