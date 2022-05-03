// Online C++ compiler to run C++ program online
#include <iostream>
#include<vector>
#include<string>
using namespace std;

int main() {
 int n,k;
 cin>>n>>k;
 string ans="";
 int fact = 1;
 vector<int> num;
 for(int i=1;i<n;i++){
     fact = fact*i;
     num.push_back(i);
 }
 num.push_back(n);
 k=k-1;
 while(true){
     ans = ans + to_string(num[k/fact]);
     num.erase(num.begin()+k/fact);
     if(num.size()==0){
         break;
     }
     k=k%fact;
     fact = fact/num.size();
 }
 cout<<ans;
}
