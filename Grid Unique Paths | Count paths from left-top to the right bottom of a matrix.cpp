
#include <iostream>

using namespace std;

int main()
{
    int m,n;
    cin>>m>>n;
    int top = m + n -2;
    int base = n - 1;
    int res = 1;
    while(top!=1){
        res = res * top;
        top--;
    }
    int res2 = 1;
    while(base!=1){
        res2 = res2 * base;
        base--;
    }
    cout<<res/res2;
}
