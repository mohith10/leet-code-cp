#include <bits/stdc++.h>
using namespace std;

void computeDelta(vector<char> arr, int size, vector<int> &deltaArr){
    int count = 0;
    for(int i=0;i<size;i++){
        if(isdigit(arr[i])){
            count--;
        }else if(isalpha(arr[i])){
            count++;
        }
        deltaArr.push_back(count);
    }
    return;
}

int computeLargestSubarray(vector<char> arr, int size, vector<int> deltaArr){
    map<int,int> hashTable;
    int res = INT_MIN;
    for(int i=0;i<size;i++){
        if(hashTable.find(deltaArr[i]) == hashTable.end()){
            hashTable[deltaArr[i]] = i;
        }else{
            res = max(res, i - hashTable[deltaArr[i]]);
        }
    }
    return res;
}

int main() {
    int size, i =0;
    cin>>size;
    vector<char> arr;
    while(i++ < size){
        char ele;
        cin>>ele;
        arr.push_back(ele);
    }
    vector<int> deltaArr;
    computeDelta(arr, size, deltaArr);
    int res = computeLargestSubarray(arr, size, deltaArr);
    cout<<res;
}
