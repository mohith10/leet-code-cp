// Online C++ compiler to run C++ program online
#include <iostream>
#include<stack>
using namespace std;

int main() {
   string s;
   stack<int> st;
   getline(cin,s);
   for(int i=0;i<s.size();i++){
       if(s[i]=='{' || s[i] == '[' || s[i]=='('){
           st.push(s[i]);
       }
       else{
           if(st.empty()){
               cout<<"Unbalanced";
               exit(0);
           }
           int x = st.top();
           st.pop();
           if((s[i]==']' && x!='[') || (s[i]=='}' && x!='{') || (s[i]==')' && x!='(')){
               cout<<"Unbalanced";
               exit(0);
           }
       }
   }
   cout<<"Balanced";
}
