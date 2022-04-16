// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
int main() {
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    
    int count =0, element = 0;
    
    for(int i=0;i<n;i++){
        if(count == 0){
            element = a[i];
        }
        
        if(element == a[i]){
            count ++;
        }
        else{
            count--;
        }
    }
    cout<<element;
}
