#include <bits/stdc++.h>
using namespace std;

int maxSum(vector<int> arr){
    int sum =0, maxSum = 0;
    for(int i=0;i<arr.size();i++){
        sum+=arr[i];
        maxSum = max(maxSum,sum);
        if(sum<0){
             sum = 0;
        }
    }
    return maxSum;
}

int main() {
    int num;
    cin>>num;
    vector<int> arr;
    for(int i =0;i<num;i++){
        int ele;
        cin>>ele;
        arr.push_back(ele);
    }
    int res = maxSum(arr);
    cout<<res;
	return 0;
}
