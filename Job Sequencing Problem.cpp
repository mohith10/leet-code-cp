// Online C compiler to run C program online
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool sortbysecdesc(const pair<int,int> &a,
                   const pair<int,int> &b)
{
       return a.second>b.second;
}

int main() {
    int n;
    cin>>n;
    vector< pair<int,int>> v;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        v.push_back(make_pair(a,b));
    }
    sort(v.begin(), v.end(), sortbysecdesc);
    int res = 0,maxi = 0;
    cout<<"Descending order as per profit "<<endl;
    for(int i=0;i<n;i++){
        maxi = max(maxi,v[i].first);
        cout<<v[i].first<<" "<<v[i].second<<"\n";
    }
    int job[maxi+1];
    for(int i=0;i<=maxi;i++){
        job[i] = -1;
    }
    for(int i=0;i<n;i++){
        int ind = v[i].first;
        while(true){
            if(ind>0 && job[ind]!=-1){
                ind--;
            }
            else if(ind<=0){
                break;
            }
            else if(job[ind]==-1){
                job[ind] = v[i].first;
                res+=v[i].second;
                cout<<"\nJob profit added at "<<ind<<" : "<<v[i].second<<endl;
                break;
            }
        }
        
    }
    cout<<endl;
    cout<<"Job array: "<<endl;
    for(int i=0;i<=maxi;i++){
        cout<<job[i];
    }
    cout<<endl;
    cout<<res;
    
}
