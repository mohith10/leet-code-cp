#include <bits/stdc++.h>
using namespace std;
int rowLen, collLen;
void nullifyRow(int row, int collLen, int arr[][collLen]){
    for(int coll = 0; coll<collLen; coll++){
        arr[row][coll] = 0; 
    }
}
void nullifyCollumn(int rowLen, int coll, int collLen, int arr[][collLen]){
    for(int row = 0; row < rowLen; row++){
        arr[row][coll] = 0; 
    }
}


void zeroMatrx(int rowLen, int collLen, int arr[][collLen]){
    int rowHasZero=0, collHasZero = 0;
    
    //check if first coll have zero
    for(int row = 0;row<rowLen;row++){
        if(arr[row][0] == 0){
            collHasZero = 1;
            break;
        }
    }
    
    //check if first row have zero
    for(int coll = 0; coll<collLen;coll++){
        if(arr[0][coll] == 0){
            rowHasZero = 1;
            break;
        }
    }
    
    //check and mark for zeroes
    for(int row = 1;row<rowLen;row++){
        for(int coll = 1; coll<collLen;coll++){
            if(arr[row][coll] == 0){
                arr[0][coll] = 0;
                arr[row][0] = 0;
            }
        }
    }
    
    //Iterate in first column to nullify rows
    for(int row = 1;row<rowLen;row++){
        if(arr[row][0] == 0){
            nullifyRow(row,collLen, arr);
        }
    }
    
    //Iterate of first row to nullfiy collumn
    for(int coll = 1;coll<collLen;coll++){
        if(arr[0][coll] == 0){
            nullifyCollumn(rowLen,coll, arr);
        }
    }
    
    //check if row had zero
    if(rowHasZero){
        nullifyRow(0, collLen, arr);
    }
    
    //check if collumn had zero
    if(collHasZero){
        nullifyCollumn(rowLen, 0, collLen , arr);
    }
    
    
}

int main() {
    
    cin>>rowLen>>collLen;
    int arr[rowLen][collLen];
    for(int row = 0;row<rowLen;row++){
        for(int coll=0;coll<collLen;coll++){
            cin>>arr[row][coll];
        }
    }
    zeroMatrx(rowLen,collLen, arr);
    for(int row = 0;row<rowLen;row++){
        for(int coll = 0; coll<collLen;coll++){
            cout<<arr[row][coll]<<" ";
        }
        cout<<endl;
    }
	return 0;
}
