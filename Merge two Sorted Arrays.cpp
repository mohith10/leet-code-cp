// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,m;
    cin>>n>>m;
    int a[n],b[m];
    int pointA=0,pointB=0;
    int c[n+m], curr = 0;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<m;i++){
        cin>>b[i];
    }
    while(pointA<n && pointB<m){
        if(a[pointA]<b[pointB]){
            c[curr] = a[pointA];
            curr++;
            pointA++;
        }
        else if(a[pointA]>b[pointB]){
            c[curr] = b[pointB];
            curr++;
            pointB++;
        }
        else{
            c[curr] = a[pointA];
            curr++;
            c[curr] = b[pointB];
            curr++;
            pointA++, pointB++;
        }
    }
    if(pointA!=n){
        while(pointA!=n){
            c[curr] = a[pointA];
            curr++, pointA++;
    }}
    else if(pointB!=m){
        while(pointB!=m){
            c[curr] = b[pointB];
            curr++, pointB++;
    }
    }
    for(int i =0;i<m+n;i++){
        cout<<c[i]<<" ";
    }

    return 0;
}
