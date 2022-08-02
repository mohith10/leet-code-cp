#include <bits/stdc++.h>
using namespace std;

class MinOperationStack{
    stack<int> integerStack;
    stack<int> minStack;
  public:
    void pushInto(int value){
        if(integerStack.empty()){
            integerStack.push(value);
            minStack.push(value);
        }else{
            if(value<=minStack.top())
                minStack.push(value);
            integerStack.push(value);
        }
    }
    
    int popOut(){
        if(integerStack.empty()) return -1;
        if(minStack.top() == integerStack.top()){
            minStack.pop();
        }
        int topElement = integerStack.top();
        integerStack.pop();
        return topElement;
    }
    
    int getMinimum(){
        return minStack.top();
    }
    
};


int main() {
	MinOperationStack st;
	cout<<st.popOut()<<endl;
	st.pushInto(3);
	st.pushInto(4);
	cout<<st.getMinimum()<<endl;
	st.pushInto(2);
	//st.popOut();
	cout<<st.getMinimum()<<endl;
	return 0;
}
