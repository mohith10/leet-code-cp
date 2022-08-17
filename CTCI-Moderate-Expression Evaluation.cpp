#include <bits/stdc++.h>
using namespace std;

int precedence(char operators){
    if(operators == '-'){
        return 1;
    }
    if(operators == '+'){
        return 1;
    }
    if(operators == '*'){
        return 2;
    }
    return 2;
}
int doTheMath(int x, int y, char operators){
    if(operators == '-'){
        return x-y;
    }
    if(operators == '+'){
        return x+y;
    }
    if(operators == '*'){
        return x*y;
    }
    return x/y;
}

int calculate(string input){
    stack<int> operands;
    stack<char> operater;
    for(int i=0; i<input.size();i++){
        if(input[i] == '+' || input[i] == '-' || input[i] == '/' || input[i] == '*'){
            if(operater.empty()){
                operater.push(input[i]);
                continue;
            }else{
                while(!operater.empty() && precedence(input[i]) <= precedence(operater.top())){
                    char operators = operater.top();
                    operater.pop();
                    int y = operands.top();
                    operands.pop();
                    int x = operands.top();
                    operands.pop();
                    int out = doTheMath(x,y,operators);
                    cout<<x<<" "<<operators<<" "<<y<<" Pushed "<<out<<endl;
                    operands.push(out);
                }
                operater.push(input[i]);
            }
        }else{
            cout<<"Pushed "<<input[i] - '0'<<endl;
            operands.push(int(input[i] - '0'));
        }
    }
    while(!operater.empty()){
        char operators = operater.top();
        operater.pop();
        int y = operands.top();
        operands.pop();
        int x = operands.top();
        operands.pop();
        int out = doTheMath(x,y,operators);
        operands.push(out);
        cout<<x<<" "<<operators<<" "<<y<<" Pushed "<<out<<endl;
    }
    return operands.top();
}

int main() {
	string input;
	getline(cin, input);
	int res = calculate(input);
	cout<<res;
	return 0;
}
