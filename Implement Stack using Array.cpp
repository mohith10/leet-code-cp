// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
int top=-1,a[1000];
int size(){
    return top+1;
}
void push(int x) {
    top++;
    a[top]=x;
    
}
int pop(){
    if(top==-1){
        return -1;
    }
    int x = a[top];
    top--;
    return x;
}

int main() {
    push(1);
    push(2);
    cout<<size()<<endl;
    cout<<pop();
}
