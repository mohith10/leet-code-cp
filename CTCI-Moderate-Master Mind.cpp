#include <bits/stdc++.h>
using namespace std;

pair<int,int> masterMind(string solution, string guess, int len){
    if(len == 0){
        return {0,0};
    }
    int hit =0, psuedoHit = 0;
    map<char, int> hashTable;
    for(int iter = 0; iter<len; iter++){
        if(guess[iter] == solution[iter]){
            hit++;
        }else{
            hashTable[solution[iter]]++;
        }
    }
    for(int iter =0; iter<len; iter++){
        if(solution[iter]!=guess[iter]){
            if(hashTable[guess[iter]] > 0){
                psuedoHit = psuedoHit + 1;
                hashTable[guess[iter]]--;
            }
        }
    }
    return {hit, psuedoHit};
}

int main() {
    string solution, guess;
    getline(cin, solution);
    getline(cin, guess);
    
	pair<int, int> res = masterMind(solution, guess, solution.size());
	cout<<"Hit "<<res.first<<" Psuedo Hit "<<res.second;
	return 0;
}
