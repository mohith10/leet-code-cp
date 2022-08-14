#include <bits/stdc++.h>
using namespace std;

int minimumDifference(vector<int> arr1, vector<int> arr2, int sizeA, int sizeB){
    if(sizeA == 0 || sizeB == 0){
        return -1;
    }
    int iterA = 0, iterB = 0, res = INT_MAX;
    while(iterA < sizeA && iterB < sizeB){
        res = min(res, abs(arr1[iterA] - arr2[iterB]));
        if(res == 0){
            return res;
        }
        
        if(arr1[iterA] < arr2[iterB]){
            iterA++;
        }else{
            iterB++;
        }
    }
    return res;
}


int main() {
    int sizeA, sizeB;
    cin>>sizeA>>sizeB;
    vector<int> arr1, arr2;
    for(int i=0;i<sizeA;i++){
        int ele;
        cin>>ele;
        arr1.push_back(ele);
    }
    for(int i=0;i<sizeB;i++){
        int ele;
        cin>>ele;
        arr2.push_back(ele);
    }
    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());
    
    int res = minimumDifference(arr1,arr2, sizeA, sizeB);
    cout<<res;
}
