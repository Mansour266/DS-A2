/*
 * FCAI – Data Structure – 2023 - Assignment 2
 * Program Name: pb#1
 * Last Modification Date: 28/04/2023
 * Author and ID and Group: Adham Wael Mansour - 20210057 - Group B
 * Teaching Assistant: unknown
 * Purpose: solve fifth problem of the assignment.
 */
#include "queue.cpp"


#include <bits/stdc++.h>

using namespace std;

void binary_generation(int n){
    queue<string> q;

    // Enqueue the first binary number
    q.push("1");


    while (n--) {
        string s1 = q.front();
        q.pop();
        cout << s1 << ' ';

        //Store s1 before changing it
        string s2 = s1;

        // Append "0" to s1 and enqueue it
        q.push(s1.append("0"));

        // Append "1" to s2 and enqueue it
        q.push(s2.append("1"));
    }
}

int main(){

    binary_generation(5);
}