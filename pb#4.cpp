/*
 * FCAI – Data Structure – 2023 - Assignment 2
 * Program Name: pb#1
 * Last Modification Date: 28/04/2023
 * Author and ID and Group: Adham Wael Mansour - 20210057 - Group B
 * Teaching Assistant: unknown
 * Purpose: solve fourth problem of the assignment.
 */
#include "stack.cpp"


#include <bits/stdc++.h>

using namespace std;


int longest_valid_parentheses(string expression){

    stack<int> s;
    s.push(-1);

    int final{0};

    for (int i = 0; i < expression.length(); ++i) {

        //push the index of opening bracket
        if(expression[i] == '(')
            s.push(i);

        else{
            //if closing bracket
            if (!s.empty())
            {
                s.pop();
            }
        }

        //find max index of valid parentheses.
        if (!s.empty())
            final = max(final, i - s.top());
        //if stack is empty then push the current index to begin a new valid parentheses.
        else
            s.push(i);
    }
    return final;
}


int main(){
    string expression{")()())"};

    cout << longest_valid_parentheses(expression);
}
