#include <iostream>
using namespace std;

int main() {
	int a,b;
	cin>>a>>b;
	cout<<a<<" "<<b<<endl;
	a = (a-b);
	b = (b + a);
	a = b-a;
	cout<<a<<" "<<b<<endl;
	return 0;
}
