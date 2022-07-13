#include <bits/stdc++.h>
using namespace std;


int main() {
	// your code goes here
	int n,m;
	int ele;
	cin>>n>>m>>ele;
	vector<vector<int>> a(n);
	for(int i=0;i<n;i++){
	    for(int j=0;j<m;j++){
	        int x;
	        cin>>x;
	        a[i].push_back(x);
	        //cout<<a[i][j]<<" ";
	    }
	    //cout<<endl;
	}
	int x = 0,y = m-1;
	while(x>-1 && x<n && y<m && y>-1){
	    if(a[x][y] == ele){
	        break;
	    }
	    if(a[x][y] > ele){
	        y--;
	    }
	    if(a[x][y] < ele){
	        x++;
	    }
	    //cout<<x<<" "<<y<<endl;
	}
	if(x==m || y<0) cout<<"Not found";
	else cout<<x<<" "<<y;
	return 0;
}
