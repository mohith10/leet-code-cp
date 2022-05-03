// Online C++ compiler to run C++ program online
#include <iostream>
#include<vector>
#include<string>
using namespace std;
bool checkPallindrome(string s,int start,int end){
    while(start<=end){
        if(s[start++]!=s[end--]){
            return false;
        }
    }
    return true;
}
void generatePallindrome(int ind, string s,vector<vector<string>> &ans,vector<string> &path){
    if(ind == s.size()){
        ans.push_back(path);
        return;
    }
    for(int i=ind;i<s.size();i++){
        if(checkPallindrome(s,ind,i)){
            path.push_back(s.substr(ind,i-ind+1));
            generatePallindrome(i+1,s,ans,path);
            path.pop_back();
        }
    }
}
int main() {
  string s;
  cin>>s;
  vector<vector<string>> ans;
  vector<string> path;
  generatePallindrome(0,s,ans,path);
  for(auto i:ans){
      for(auto j:i){
          cout<<j<<" ";
      }
     cout<<endl;
  }
}
