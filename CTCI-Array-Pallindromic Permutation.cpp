#include <bits/stdc++.h>
using namespace std;

bool PallindromicPermutationPossible(string str){
    int count = 0;
    vector<int> frequenceArray(128,0);
    for(int i=0;i<str.size();i++){
        if(str[i]!=' '){
            frequenceArray[int(str[i])]++;
            count++;
        }
    }
    int flag = false;
    for(int i=0;i<128;i++){
        if(frequenceArray[i]%2){
            if(count%2){
                if(flag){
                    return false;
                }else{
                    flag = true;
                }
            }else{
                return false;
            }
        }
    }
    return true;
}

int main() {
	string str;
	getline(cin,str);
	cout<<PallindromicPermutationPossible(str);
	return 0;
}
