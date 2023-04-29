/*
 * FCAI – Data Structure – 2023 - Assignment 2
 * Program Name: pb#7.cpp
 * Last Modification Date: 28/04/2023
 * Author and ID and Group: Adham Wael Mansour - 20210057 - Group B
 * Teaching Assistant: unknown
 * Purpose: solve seventh problem of the assignment.
 */

#include "queue.cpp"

#include <bits/stdc++.h>

using namespace std;

queue<int> queue_sort(queue<int> q){
    int arr[q.size()];

    int length = q.size();

    for (int i = 0; i < length; ++i) {
        arr[i] = q.front();
        q.pop();
    }
    sort(arr, arr + length);
    for (int i = 0; i < length; ++i) {
        q.push(arr[i]);
    }

    return q;
}

int main(){
    queue<int> q;
    q.push(3);
    q.push(15);
    q.push(2);
    q.push(4);

    queue<int> final =  queue_sort(q);

    while(!final.empty()){
        cout << final.front() << " ";
        final.pop();
    }
}