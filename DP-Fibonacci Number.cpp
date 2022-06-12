// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
int main() {
    int a[100];
    a[0] = 0;
    a[1] = 1;
    for(int i=2;i<=100;i++){
        a[i] = a[i-1]+a[i-2];
    }
    
    return 0;
}
