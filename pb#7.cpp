/*
 * FCAI – Data Structure – 2023 - Assignment 2
 * Program Name: pb#7.cpp
 * Last Modification Date: 28/04/2023
 * Author and ID and Group: Adham Wael Mansour - 20210057 - Group B
 * Teaching Assistant: unknown
 * Purpose: solve seventh problem of the assignment.
 */

#include "queue.cpp"

#include <algorithm>

using namespace std;

Queue<int> queue_sort(Queue<int> q){
    int length = q.queue_size();
    /*
     * This defines a temporary array to move the queue data to it
     * then sort the array and move the sorted data back into the queue.
     */

    int arr[length];

    for (int i = 0; i < length; ++i) {
        arr[i] = q.first();
        q.dequeue();
    }
    sort(arr, arr + length);
    for (int i = 0; i < length; ++i) {
        q.enqueue(arr[i]);
    }

    return q;
}

int main(){
    Queue<int> q;
    q.enqueue(3);
    q.enqueue(15);
    q.enqueue(2);
    q.enqueue(4);

    Queue<int> final =  queue_sort(q);

    while(!final.is_empty()){
        cout << final.first() << " ";
        final.dequeue();
    }
}