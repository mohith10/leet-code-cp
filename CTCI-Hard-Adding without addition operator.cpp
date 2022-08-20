#include <bits/stdc++.h>
using namespace std;

int addWithoutAddOperator(int a, int b){
    while(b!=0){
        int sum = a^b;
        int carry = (a&b)<<1;
        a = sum;
        b = carry;
    }
    return a;
}

int main() {
	int a,b;
	cin>>a>>b;
	int res = addWithoutAddOperator(a,b);
	cout<<res;
	return 0;
}
