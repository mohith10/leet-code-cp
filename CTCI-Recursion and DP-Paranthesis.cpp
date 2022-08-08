#include <bits/stdc++.h>
using namespace std;

void Parenthesis(vector<string> &res, int leftParan, int rightParan, int index, string &currentString){
    if(leftParan < 0 || leftParan > rightParan) return;
    
    if(leftParan == 0 && rightParan ==0){
        cout<<"pushed "<<currentString<<endl;
        res.push_back(currentString);
        return;
    }
    currentString[index++] = '(';
    Parenthesis(res, leftParan-1,rightParan, index+1,currentString);
    currentString[index++] = ')';
    Parenthesis(res, leftParan, rightParan-1, index+1, currentString);
    return;
}

int main() {
	int n;
	cin>>n;
	
	vector<string> res;
	string currentString = "";
	Parenthesis(res,n,n,0,currentString);
	for(int i=0;i<res.size();i++){
	    cout<<res[i]<<" ";
	}

	return 0;
}
