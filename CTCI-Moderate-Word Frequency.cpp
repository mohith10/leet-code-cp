#include <bits/stdc++.h>
using namespace std;

void constructFrequencyTable(string line, map<string,int> &frequencyTable){
    if(line.size() == 0){
        return;
    }
    string word = "";
    for(int iter = 0; iter < line.size(); iter++){
        if(line[iter] == ' '){
            frequencyTable[word]++;
            word = "";
        }else{
            word = word+line[iter];
        }
    }
    frequencyTable[word]++;
    return;
}

int main() {
	string line;
	getline(cin,line);
	//cout<<line;
	map<string,int> frequencyTable;
	constructFrequencyTable(line,frequencyTable);
	int queries;
	cin>>queries;
	for(int query=0;query<queries;query++){
	    string q;
	    cin>>q;
	    cout<<frequencyTable[q]<<endl;
	}
	return 0;
}
