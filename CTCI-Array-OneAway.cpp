#include <iostream>
using namespace std;

bool oneAway(string str1, string str2){
    int lenOfStr1 = str1.size();
    int lenOfStr2 = str2.size();
    if(lenOfStr2<lenOfStr1) return oneAway(str2,str1);
    if(abs(lenOfStr2 - lenOfStr1)>1) return false;
    
    int indexOfStr1 = 0, indexOfStr2 = 0;
    bool descrepancy = false;
    while(indexOfStr1<lenOfStr1 && indexOfStr2<lenOfStr2){
        if(str1[indexOfStr1]!=str2[indexOfStr2]){
            if(descrepancy) return false;
            descrepancy = true;
            if(lenOfStr2 == lenOfStr1){
                indexOfStr1++;
            }
        }
        else{
            indexOfStr1++;
        }
        indexOfStr2++;
    }
    return true;
}

int main() {
	string str1,str2;
	getline(cin,str1);
	getline(cin,str2);
	cout<<oneAway(str1,str2);
	return 0;
}
