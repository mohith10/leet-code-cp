// Online C++ compiler to run C++ program online
#include <iostream>
#include<stack>
using namespace std;
int main() {
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    stack<int> s;
    int nse[n],pse[n];
     int x = 0;
    for(int i=0;i<n;i++){
       
        
        while(!s.empty()){
            x = s.top();
            
            if(a[x]>=a[i]){
                s.pop();
            }
            else{
                
                break;
            }
        }
        if(!s.empty()){
            
            pse[i]=x+1;
        }else{
            pse[i] = 0;
        }
        s.push(i);
       
    }
    
    cout<<"PSE"<<endl;
    for(int i=0;i<n;i++){
        cout<<pse[i]<<" ";
    }
    cout<<endl;
    while(!s.empty()){
        s.pop();
    }
    for(int i=n-1;i>-1;i--){
        while(!s.empty()){
            x = s.top();
            
            if(a[x]>=a[i]){
                s.pop();
            }
            else{
               
                break;
            }
        }
        if(!s.empty()){
            
            nse[i]=x-1;
        }else{
            nse[i] = n-1;
        }
        s.push(i);
       
    }
    cout<<"NSE"<<endl;
    for(int i=0;i<n;i++){
        cout<<nse[i]<<" ";
    }
    cout<<endl;
    int res = 0;
    for(int i=0;i<n;i++){
        res = max(res,abs(nse[i] - pse[i] + 1)*a[i]);
    }
    cout<<res;
}
