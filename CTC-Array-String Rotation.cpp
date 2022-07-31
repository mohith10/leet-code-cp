#include <bits/stdc++.h>
using namespace std;

bool isStringRotation(string str1, string str2){
    if(str1.size() != str2.size()){
        return false;
    }
    
    string doubleStr1 = str1 + str1;
    cout<<doubleStr1<<endl;
    //check for substring of S2 in doubleStr1 and return accrodingly
}
int main() {
	string str1, str2;
	getline(cin,str1);
	getline(cin, str2);
	cout<<isStringRotation(str1, str2);
	return 0;
}
