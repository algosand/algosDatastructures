#include <bits/stdc++.h>
using namespace std;

/*
This is an example of a shunting yard algorithm with stacks to create a calculator. 

This converts infix to postfix notation and evaluates the postfix notation using stacks with both
those steps. 

This can be extended to include more operators such as division and multiplication.  
*/
// the precedence of every character 
int precedence(char o) {
    switch(o) {
        case '+': 
            return 1;
        case '-':
            return 1;
        case '(':
            return 0;
    }
    return -1;
}
// converting infix notation to postfix notation
vector<string> postFix(string &s) {
    vector<string> postfix;
    int n = s.size();
    stack<char> operatorStk;
    string num = "";
    auto isGrEqPrecedence = [&](const char a, const char b) {
        return precedence(a)>=precedence(b);
    };
    auto operate = [&](const char op) {
        while (!operatorStk.empty() && isGrEqPrecedence(operatorStk.top(), op)) {
            postfix.push_back(string(1, operatorStk.top()));
            operatorStk.pop();
        }
    };
    for (int i = 0;i<n;i++) {
        if (isspace(s[i])) {continue;}
        if (isdigit(s[i])) {
            num+=s[i];
        } else {
            if (num.size()>0) {
                postfix.push_back(num);
                num = "";
            }
            if (s[i]=='(') {
                operatorStk.push(s[i]);
            } else if (s[i]==')') {
                while (operatorStk.top()!='(') {
                    postfix.push_back(string(1,operatorStk.top()));
                    operatorStk.pop();
                }
                operatorStk.pop();
            } else {
                operate(s[i]);
                operatorStk.push(s[i]);
            }

        }
    }
    if (num.size()>0) {
        postfix.push_back(num);
    }
    operate('!');
    return postfix;
}
// evaluation with an operator
int eval(const int a, const int b, const string &op) {
    return op=="+" ? b+a : b-a;
}
// evaluating the postfix notation to compute the result
int evaluatePostFix(vector<string>& postfix) {
    stack<int> operandStk;
    auto isOper = [&](const string &s) {
        return s=="+" || s=="-";
    };
    for (string &o : postfix) {
        if (isOper(o)) {
            int a = operandStk.top();
            operandStk.pop();
            int b = 0;
            if (!operandStk.empty()) {
                b = operandStk.top();
                operandStk.pop();
            }
            operandStk.push(eval(a,b,o));
        } else {
            operandStk.push(stoi(o));
        }
    }
    return operandStk.top();
}
int calculate(string s) {
    vector<string> postfix = postFix(s);
    return evaluatePostFix(postfix);
}