/* This program checks whether the expression has a balanced parenthesis or not.
This means that the type of brackets opened last will be closed first and all brackets must be closed.
    {a + [b - (c * d)] + g} -> Balanced
    {a + (b - c} ) -> Not Balanced
    {a + (b-c) + d -> Not Balanced
We can approach this problem using Stacks. */

#include<iostream>
#include<string>
#include<stack>
using namespace std;

bool balancedExpression(string S) {
    stack<char> exp;
    for(int i=0; i<S.length(); i++) {
        if(S[i]=='{' || S[i]=='[' || S[i]=='(') {
            exp.push(S[i]);
        }
        else if(S[i]=='}') {
            if(!exp.empty() && exp.top() == '{') {
                exp.pop();
            }
            else {
                return false;
            }
        }
        else if(S[i]==']') {
            if(!exp.empty() && exp.top() == '[') {
                exp.pop();
            }
            else {
                return false;
            }
        }
        else if(S[i]==')') {
            if(!exp.empty() && exp.top() == '(') {
                exp.pop();
            }
            else {
                return false;
            }
        }
    }
    if(!exp.empty()) 
        return false;
    return true;
}

int main() {
    string expression;
    cin>>expression;
    cout<<balancedExpression(expression)<<endl;
    return 0;
}