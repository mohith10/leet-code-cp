// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
int main() {
    string s;
    getline(cin,s);
    string ans = "",temp ="";
    int left = 0, right = s.size()-1;
    while(left<=right){
        char c = s[left];
        if(c==' '){
                ans = temp + " " + ans;
                temp = "";
        }
        else{
            temp = temp + c;
        }
        left++;
    }
    ans = temp + " " + ans;
    cout<<ans;
}Reverse Words in a String
