#include <bits/stdc++.h>
using namespace std;

void groupAnagram(vector<string> arr, map<int, vector<string>> &hashTable){
    for(int index = 0; index<arr.size(); index++){
        string str = arr[index];
        int count = 0;
        for(int i = 0; i<str.size();i++){
            count+=(int)str[i];
        }
        hashTable[count].push_back(str);
    }
}


int main() {
    vector<string> arr;
    int numOfStrings;
    cin>>numOfStrings;
    for(int index = 0; index<numOfStrings; index++){
        string s;
        cin>>s;
        arr.push_back(s);
    }
    map<int,vector<string>> hashTable;
    groupAnagram(arr,hashTable);
    for(auto itr = hashTable.begin(); itr!=hashTable.end();itr++){
        vector<string> res = itr->second;
        for(int index = 0; index<res.size();index++){
            cout<<res[index]<<endl;
        }
    }
	return 0;
}
