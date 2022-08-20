#include <bits/stdc++.h>
using namespace std;

int findMissingBitNumber(vector<string> arr, int size){
    int binToDec = stoi(arr[0],0,2);
    if(binToDec!=0){
        return 0;
    }
    int lowerBound = 1, higherBound = size-1;
    while(lowerBound <= higherBound){
        int mid = lowerBound + (higherBound - lowerBound)/2;
        binToDec = stoi(arr[mid], 0,2);
        if((mid & 1) != (binToDec % 2)){
            
            int prev = stoi(arr[mid - 1],0,2);
            cout<<lowerBound<<" "<<higherBound<<" "<<mid<<" "<<binToDec<<" "<<prev<<endl;
            if(prev == (binToDec - 1)){
                higherBound = mid - 1;
            }else{
                return binToDec-1;
            }
        }else{
            cout<<"Parity same "<<arr[mid]<<" "<<mid<<endl;
            lowerBound = mid + 1;
        }
    }
    return -1;
}

int main() {
    int size;
    cin>>size;
    vector<string> arr;
    for(int binary = 0;binary<size; binary++){
        string s;
        cin>>s;
        arr.push_back(s);
    }
    int res = findMissingBitNumber(arr, size);
    cout<<"Missing Number is "<<res;
}
