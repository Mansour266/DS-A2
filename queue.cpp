/*
 * FCAI – Data Structure – 2023 - Assignment 2
 * Program Name: queue
 * Last Modification Date: 13/04/2023
 * Author and ID and Group: Adham Wael Mansour - 20210057 - Group B
 * Teaching Assistant: unknown
 * Purpose: Implement queue from scratch.
 */

#include <bits/stdc++.h>
#define MAX 1000

using namespace std;

template<typename T>
class Queue{
private:
  T arr[MAX];
  int front;
  int back;
  int size;

public:
    Queue(){
        front = -1;
        back = -1;
        size = 0;
    }

    bool is_empty(){
        return front == -1;
    }

    void enqueue(T element){
        if(!(front == 0 && back == MAX - 1 || front == back + 1)){
            if(back == MAX - 1 || back == -1) {
                arr[0] = element;
                back = 0;

                if (front == -1)
                    front = 0;
            }
            else
                arr[++back] = element;

            size++;
        }
        else
            cout << "Queue is full\n";

    }

    T dequeue(){
        T temp;
        temp = arr[front];

        if(front == back){
            back = -1;
            front = -1;
        }
        else if(front == MAX - 1){
            front = 0;
        }
        else
            front++;

        size--;
        return temp;
    }

    T first(){
       return arr[front];
    }

    int queue_size(){
        return size;
    }

    void clear(){
        size = 0;
        front = -1;
        back = -1;
    }

    void print(){
        for (int i = front; i <= back; ++i) {
            cout << arr[i] << ' ';
        }
    }

};

//int main(){
//    Queue<int> q;
//
//    q.enqueue(5);
//    q.enqueue(6);
//    q.enqueue(7);
//    q.enqueue(8);
//
//    cout << q.dequeue() << endl;
//    cout << q.queue_size() << endl;
//    q.print();
//
//}