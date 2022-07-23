#include <bits/stdc++.h>
using namespace std;

bool isSafe(int row, int coll, vector<string> board,int n){
    //horizontal check
    int tempRow = row, tempColl = coll;
    
    while(coll>=0){
        if(board[row][tempColl] == 'Q'){
            return false;
        }
        tempColl--;
    }
    //upper diagnol check
    tempRow=row, tempColl = coll;
    while(tempRow>=0 && tempColl >= 0){
        if(board[tempRow][tempColl] == 'Q'){
            return false;
        }
        tempRow--;
        tempColl--;
    }
    //Lower diagnol check
    tempRow = row, tempColl = coll;
    while(tempRow<n && tempColl >= 0){
        if(board[tempRow][tempColl] == 'Q') return false;
        tempRow++;
        tempColl--;
    }
    return true;
    
}

void solve(int coll, vector<string> &board, vector<vector<string>> &ans, int n){
    if(coll==n){
        ans.push_back(board);
    }
    
    for(int row = 0; row<n; row++){
        
        if(isSafe(row,coll,board,n)){
            board[row][coll] = 'Q';
            solve(coll+1, board,ans,n);
            board[row][coll] = '.';
        }
    }
}

int main() {
    int n;
    cin>>n;
	vector<vector<string>> ans;
	vector<string> board(n);
	string s(n,'.');
	
	for(int i=0;i<n;i++) board[i] = s;
	solve(0,board, ans, n);
	for(int i = 0;i<n;i++){
	    for(int j=0;j<n;j++){
	        cout<<ans[i][j]<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}
