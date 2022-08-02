#include <bits/stdc++.h>
using namespace std;

void sortStack(stack<int> &st){
    if(st.empty()) return;
    
    stack<int> tempStack;
    while(!st.empty()){
        int ele = st.top();
        st.pop();
        if(!tempStack.empty()){
            if(tempStack.top() > ele){
                while(!tempStack.empty()){
                    int tempEle = tempStack.top();
                    tempStack.pop();
                    st.push(tempEle);
                }
            }
        }
        tempStack.push(ele);
    }
    while(!tempStack.empty()){
        st.push(tempStack.top());
        tempStack.pop();
    }
}


int main() {
	stack<int> st;
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
	    int ele;
	    cin>>ele;
	    st.push(ele);
	}
	sortStack(st);
	while(!st.empty()){
	    cout<<st.top()<<" ";
	    st.pop();
	}
	return 0;
}
