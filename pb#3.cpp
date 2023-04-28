/*
 * FCAI – Data Structure – 2023 - Assignment 2
 * Program Name: pb#1
 * Last Modification Date: 28/04/2023
 * Author and ID and Group: Adham Wael Mansour - 20210057 - Group B
 * Teaching Assistant: unknown
 * Purpose: solve third problem of the assignment.
 */
#include "stack.cpp"


#include <bits/stdc++.h>

using namespace std;

int precedence(char op){
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
    }
    return -1;
}

int is_operator(char c){
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

bool is_operand(char c){
    return ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

bool is_higher_precedence(char operand_1, char operand_2){
    int weight_1 = precedence(operand_1);
    int weight_2 = precedence(operand_2);

    if(weight_1 == weight_2) {
        if (operand_1 == '^')
            return false;
        else
            return true;
    }
    else
        return weight_1 > weight_2;
}
string infix_to_postfix(string expression){
    stack<char> s;
    string postfix;

    for (int i = 0; i < expression.length(); ++i) {

        //check if the character is a delimiter
        if (expression[i] == ' ' || expression[i] == ',')
            continue;

        else if(is_operator(expression[i])){
            while (!s.empty() && s.top() != '(' && is_higher_precedence(s.top(), expression[i])){
                postfix += s.top();
                s.pop();
            }
            s.push(expression[i]);
        }

        else if (is_operand(expression[i])){
            postfix += expression[i];
        }

        else if (expression[i] == '('){
            s.push(expression[i]);
        }

        else if (expression[i] == ')'){
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            s.pop();
        }
    }
    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }

    return postfix;
}

int main(){
    string exp{"(A + B) * (C + D)"};

    cout << infix_to_postfix(exp);
}