/*
 * FCAI – Data Structure – 2023 - Assignment 2
 * Program Name: pb#1
 * Last Modification Date: 28/04/2023
 * Author and ID and Group: Adham Wael Mansour - 20210057 - Group B
 * Teaching Assistant: unknown
 * Purpose: solve sixth problem of the assignment.
 */
#include "queue.cpp"


#include <bits/stdc++.h>

using namespace std;

template<typename T>
class queue_based_stack{
    queue<T> q1, q2;

public:
    void push(T element){
        q2.push(element);

        // Push all the remaining data in q1 to q2.
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        // swap the names of two queues
        queue<T> q = q1;
        q1 = q2;
        q2 = q;
    }

    void pop()
    {
        // if no elements are there in q1
        if (q1.empty())
            return;
        q1.pop();
    }

    int top()
    {
        if (q1.empty())
            return -1;

        return q1.front();
    }

    int size() {
        return q1.size();
    }
};

int main(){
    queue_based_stack<int> s;

    s.push(1);
    s.push(2);
    s.push(5);

    cout << "stack size is: " << s.size() << '\n';

    cout << "the top element is: " << s.top() << '\n';
}