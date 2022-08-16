#include <bits/stdc++.h>
using namespace std;

void T9dialHandler(int dataCount, map<string, vector<string>> &hashTable, string input, map<char,int> dialpadMapping, vector<string> &res, vector<string> data){
    if(input == ""){
        return;
    }
    
    for(int i=0; i<dataCount;i++){
        string st = data[i];
        string dialString = "";
        for(int j=0;j<st.size();j++){
            dialString=dialString + to_string(dialpadMapping[st[j]]);
        }
        //cout<<st<<" "<<dialString<<endl;
        hashTable[dialString].push_back(st);
    }
    res = hashTable[input];
    return;
}


int main() {
	int dataCount;
	cin>>dataCount;
	vector<string> data;
	for(int i=0; i<dataCount; i++){
	    string s;
	    cin>>s;
	    data.push_back(s);
	}
	map<char,int> dialpadMapping;
	dialpadMapping['a']=2;
	dialpadMapping['b']=2;
	dialpadMapping['c']=2;
	dialpadMapping['d']=3;
	dialpadMapping['e']=3;
	dialpadMapping['f']=3;
	dialpadMapping['g']=4;
	dialpadMapping['h']=4;
	dialpadMapping['i']=4;
	dialpadMapping['j']=5;
	dialpadMapping['k']=5;
	dialpadMapping['l']=5;
	dialpadMapping['m']=6;
	dialpadMapping['n']=6;
	dialpadMapping['o']=6;
	dialpadMapping['p']=7;
	dialpadMapping['q']=7;
	dialpadMapping['r']=7;
	dialpadMapping['s']=7;
	dialpadMapping['t']=8;
	dialpadMapping['u']=8;
	dialpadMapping['v']=8;
	dialpadMapping['w']=9;
	dialpadMapping['x']=9;
	dialpadMapping['y']=9;
	dialpadMapping['z']=9;
	string input;
	cin>>input;
	vector<string> res;
	map<string, vector<string>> hashTable;
	
	T9dialHandler(dataCount, hashTable, input, dialpadMapping, res, data);
	
	for(int i=0;i<res.size();i++){
	    cout<<res[i]<<" ";
	}
	return 0;
}
