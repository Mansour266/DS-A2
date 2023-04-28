/*
 * FCAI – Data Structure – 2023 - Assignment 2
 * Program Name: stack
 * Last Modification Date: 15/04/2023
 * Author and ID and Group: Adham Wael Mansour - 20210057 - Group B
 * Teaching Assistant: unknown
 * Purpose: Implement stack from scratch.
 */

#include <bits/stdc++.h>
#define MAX 1000

using namespace std;



template<typename T>
class Stack{
private:
    int top;

public:

    //This defines an array of stack with maximum size 1000
    T arr[MAX];

    Stack(){
        top = -1;
    }

    void push(T element){

        if(top >= MAX - 1){
            cout << "Stack is full\n";
            return;
        }
        arr[++top] = element;
    }

    T pop(){
        return arr[top--];
    }

    T Top(){
        return arr[top];
    }

    bool is_empty(){
        return top == -1;
    }

    int stack_size(){
        if(top == -1)
            return 0;

        return top + 1;
    }

    void clear(){
        memset(arr, 0, sizeof arr);
        top = -1;
    }

    void print(){
        if (top == -1)
            return;

        for (int i = 0; i <= top; ++i) {
            cout << arr[i] << ' ';
        }
    }
};


//int main(){
//    Stack<char> st;
//    st.Top();
//
//    cout << boolalpha;
//    cout << endl << st.is_empty() << endl;
//
//    cout << "Stack size:" << st.stack_size() << endl;
//
//    st.print();
//
//    st.clear();
//    st.print();
//}