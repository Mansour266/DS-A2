/*
 * FCAI – Data Structure – 2023 - Assignment 2
 * Program Name: pb#1
 * Last Modification Date: 27/04/2023
 * Author and ID and Group: Adham Wael Mansour - 20210057 - Group B
 * Teaching Assistant: unknown
 * Purpose: solve second problem of the assignment.
 */
#include "single_linked_list.cpp"


#include <bits/stdc++.h>

using namespace std;



class compare_ll {
public:
    bool operator()(Node<int> *n1, Node<int> *n2){
        return n1->data > n2->data;
    }
};



Node<int> *merge_lists(vector<Node<int> *> const vec){
    priority_queue<Node<int>* , vector<Node<int>*>, compare_ll> p_queue;

    for (Node<int>* list: vec) {
        p_queue.push(list);
    }

    //use head and tail to facilitate the sorting.
    Node<int> *head = nullptr, *last = nullptr;

    // run till minimum heap is empty
    while (!p_queue.empty())
    {
        //get the node with the minimum value.
        Node<int>* min = p_queue.top();
        p_queue.pop();

        // add the minimum node to the output list
        if (head == nullptr) {
            head = last = min;
        }
        else {
            last->next = min;
            last = min;
        }

        // take the next node from the same list and insert it into the minimum heap.
        if (min->next != nullptr) {
            p_queue.push(min->next);
        }
    }

    return head;
}


void print_merged_list(Node<int> *head) {
    while(head != nullptr) {
       cout << head->data << ' ';
       head = head->next;
    }
    cout << '\n';
}



int main(){
    vector<Node<int> *> vec(3);


    vec[0] = new Node<int>;
    vec[0]->data = 1;
    vec[0]->next = new Node<int>;
    vec[0]->next->data = 3;
    vec[0]->next->next = new Node<int>;
    vec[0]->next->next->data = 5;
    vec[0]->next->next->next = new Node<int>;
    vec[0]->next->next->next->data = 7;

    vec[1] = new Node<int>;
    vec[1]->data = 2;
    vec[1]->next = new Node<int>;
    vec[1]->next->data = 4;
    vec[1]->next->next = new Node<int>;
    vec[1]->next->next->data = 6;
    vec[1]->next->next->next = new Node<int>;
    vec[1]->next->next->next->data = 8;

    vec[2] = new Node<int>;
    vec[2]->data = 0;
    vec[2]->next = new Node<int>;
    vec[2]->next->data = 9;
    vec[2]->next->next = new Node<int>;
    vec[2]->next->next->data = 10;

    Node<int> *head = merge_lists(vec);

    print_merged_list(head);


}