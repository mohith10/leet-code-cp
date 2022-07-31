#include <bits/stdc++.h>
using namespace std;


void matrixTranspose(vector<vector<int>> &arr, int rowLen, int collLen){
    for(int row = 0; row<rowLen; row++){
        for(int coll = row + 1; coll<collLen; coll++){
            int temp = arr[row][coll];
            arr[row][coll] = arr[coll][row];
            arr[coll][row] = temp;
        }
    }
}

void matrixRotation(vector<vector<int>> &arr,int rowLen, int collLen){
   matrixTranspose(arr,rowLen,collLen);
	
    for(int row = 0; row<rowLen; row++){
        int begin =0, end = collLen-1;
        while(begin<end){
            int temp = arr[row][begin];
            arr[row][begin] = arr[row][end];
            arr[row][end] = temp;
            begin++, end--;
        }
    }
}

int main() {
	int rowLen, collLen;
	cin>>rowLen>>collLen;
	vector<vector<int>> arr(rowLen, vector<int> (collLen));
	for(int row = 0; row<rowLen; row++){
	    for(int coll = 0; coll<collLen; coll++){
	        cin>>arr[row][coll];
	    }
	}
	matrixRotation(arr,rowLen, collLen);
	for(int row = 0; row<rowLen; row++){
	    for(int coll = 0; coll<collLen; coll++){
	        cout<<arr[row][coll]<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}
