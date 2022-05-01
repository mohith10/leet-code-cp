// Online C compiler to run C program online
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int v;
    cin>>v;
    int coins = 0;
    //1, 2, 5, 10, 20, 50, 100, 500, 1000
    while(v){
        if(v/1000>0){
            coins+=(v/1000);
            v=v%1000;
        }
        else if(v/500>0){
            coins+=(v/500);
            v=v%500;
        }
        else if(v/100>0){
            coins+=(v/100);
            v=v%100;
        }
        else if(v/50>0){
            coins+=(v/50);
            v=v%50;
        }
        else if(v/20>0){
            coins+=(v/20);
            v=v%20;
        }
        else if(v/10>0){
            coins+=(v/10);
            v=v%10;
        }
        else if(v/5>0){
            coins+=(v/5);
            v=v%5;
        }
        else if(v/2>0){
            coins+=(v/2);
            v=v%2;
        }
        else if(v/1>0){
            coins+=(v/1);
            v=v%1;
            break;
        }
    }
    cout<<coins;
}
