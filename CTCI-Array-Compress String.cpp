#include <iostream>
using namespace std;

string stringCompression(string str){
    int contigousLen = 0;
    char contigousChar = str[0];
    string result = "";
    for(int i=0;i<str.size();i++){
        if(str[i]!=contigousChar){
            result = result + contigousChar + to_string(contigousLen);
            contigousLen = 1;
            contigousChar = str[i];
        }else{
            contigousLen++;
        }
    }
    result = result + contigousChar + to_string(contigousLen);
    return result;
}

int main() {
	string str;
	getline(cin,str);
	cout<<stringCompression(str);
	return 0;
}
