// Online C++ compiler to run C++ program online
#include<bits/stdc++.h>
using namespace std;
int main() {
    vector<pair<int,int> > v, answer;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        v.push_back(make_pair(a,b));
    }
    answer.push_back(make_pair(v[0].first,v[0].second));
    for(int i=1;i<v.size();i++){
        if(answer[answer.size()-1].second>=v[i].first){
            answer[answer.size()-1].second = v[i].second;
        }
        else{
            answer.push_back(v[i]);
        }
    }
    
    for(int i=0;i<answer.size();i++){
        cout<<answer[i].first<<" "<<answer[i].second<<endl;
    }
}
